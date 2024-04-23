/*===[[ START ]]==============================================================*/
#include    "yURG.h"
#include    "yURG_priv.h"



static char  s_mname   [LEN_FULL] = "";
static FILE *s_mfile   = NULL;
static char  s_mlive   = 'y';
static char  s_mprint  [LEN_RECD] = "";



/*====================------------------------------------====================*/
/*===----                   file openning and closing                  ----===*/
/*====================------------------------------------====================*/
static void  o___FILE____________o () { return; }

char
yurg_msg__open          (char a_type, char a_name [LEN_FULL], char **f, char r_save [LEN_FULL])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   /*---(header)-------------------------*/
   DEBUG_ARGS   yLOG_senter  (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_ARGS   yLOG_schar   (a_type);
   --rce;  if (a_type != 'm' && a_type != 'e') {
      DEBUG_ARGS   yLOG_snote   ("not a valid type");
      DEBUG_ARGS   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_ARGS   yLOG_spoint  (a_name);
   --rce;  if (a_name == NULL || strcmp (a_name, "") == 0) {
      DEBUG_ARGS   yLOG_snote   ("no name provided");
      DEBUG_ARGS   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_ARGS   yLOG_spoint  (f);
   --rce;  if (f == NULL) {
      DEBUG_ARGS   yLOG_snote   ("no pointer passed");
      DEBUG_ARGS   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_ARGS   yLOG_spoint  (*f);
   --rce;  if (*f != NULL) {
      DEBUG_ARGS   yLOG_snote   ("file already open");
      DEBUG_ARGS   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(filter)-------------------------*/
   --rce;
   if      (strcmp (a_name, "stdout") == 0) {
      DEBUG_ARGS   yLOG_snote   ("selected stdout");
      *f = stdout;
      strcpy (r_save, "stdout");
   }
   else if (strcmp (a_name, "stderr") == 0) {
      DEBUG_ARGS   yLOG_snote   ("selected stderr");
      *f = stderr;
      strcpy (r_save, "stderr");
   }
   else {
      DEBUG_ARGS   yLOG_snote   ("specific file");
      *f = fopen (a_name, "wt");
      DEBUG_ARGS   yLOG_spoint  (*f);
      if (*f == NULL) {
         DEBUG_ARGS   yLOG_snote   ("file is illegal");
         DEBUG_ARGS   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      } else {
         strcpy (r_save, a_name);
      }
   }
   /*---(complete)-----------------------*/
   DEBUG_ARGS   yLOG_sexit   (__FUNCTION__);
   return 1;
}

char yurg_msg_open      (char a_name [LEN_FULL]) { return yurg_msg__open  ('m', a_name, &s_mfile, s_mname); }

char
yurg_msg__close         (char a_type, char **f, char r_save [LEN_FULL])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   /*---(header)-------------------------*/
   DEBUG_ARGS   yLOG_senter  (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_ARGS   yLOG_schar   (a_type);
   --rce;  if (a_type != 'm' && a_type != 'e') {
      DEBUG_ARGS   yLOG_snote   ("not a valid type");
      DEBUG_ARGS   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_ARGS   yLOG_spoint  (f);
   --rce;  if (f == NULL) {
      DEBUG_ARGS   yLOG_snote   ("no pointer passed");
      DEBUG_ARGS   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_ARGS   yLOG_spoint  (*f);
   --rce;  if (*f == NULL) {
      DEBUG_ARGS   yLOG_snote   ("file not open, nothing to do");
      DEBUG_ARGS   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(filter)-------------------------*/
   if (*f == stdout || *f == stderr) {
      DEBUG_ARGS   yLOG_snote   ("never close stdout or stderr");
   }
   /*---(close file)---------------------*/
   else {
      DEBUG_ARGS   yLOG_snote   ("close file");
      rc = fclose (*f);
      DEBUG_ARGS   yLOG_sint    (rc);
      --rce;  if (rc != 0) {
         DEBUG_ARGS   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(ground globals)-----------------*/
   *f = NULL;
   DEBUG_ARGS   yLOG_spoint  (*f);
   if (r_save != NULL)  strcpy (r_save, "");
   /*---(complete)-----------------------*/
   DEBUG_ARGS   yLOG_sexit   (__FUNCTION__);
   return 1;
}

char yurg_msg_close     (void) { return yurg_msg__close ('m', &s_mfile, s_mname); }



/*====================------------------------------------====================*/
/*===----                      message destination                     ----===*/
/*====================------------------------------------====================*/
static void  o___DEST____________o () { return; }

char
yurg_msg__dest          (char a_name [LEN_FULL])
{
   char        rc          =    0;
   DEBUG_ARGS   yLOG_enter   (__FUNCTION__);
   rc = yurg_msg_close ();
   rc = yurg_msg_open  (a_name);
   DEBUG_ARGS   yLOG_value   ("open"      , rc);
   DEBUG_ARGS   yLOG_exit    (__FUNCTION__);
   return rc;
}

char yURG_msg_std       (void) { return yurg_msg__dest ("stdout"); }
char yURG_msg_none      (void) { return yurg_msg__dest ("/dev/null"); }
char yURG_msg_tmp       (void) { return yurg_msg__dest (YURG_MSG); }
char yURG_msg_custom    (char a_name [LEN_FULL]) { return yurg_msg__dest (a_name); }



/*====================------------------------------------====================*/
/*===----                         live vs mute                         ----===*/
/*====================------------------------------------====================*/
static void  o___MUTING__________o () { return; }

char yURG_msg_mute  (void) { s_mlive = '-'; }
char yURG_msg_live  (void) { s_mlive = 'y'; }



/*====================------------------------------------====================*/
/*===----                         main driver                          ----===*/
/*====================------------------------------------====================*/
static void  o___DRIVER__________o () { return; }

char
yURG_msg                (cchar a_type, cchar *a_format, ...)
{
   /*---(locals)-----------+-----+-----+-*/
   char        x_pre       [LEN_LABEL] = "";
   char        x_suf       [LEN_LABEL] = "";
   va_list     x_args;
   /*---(check output)-------------------*/
   if (s_mfile == NULL)  yURG_msg_std ();
   /*---(prefix)-------------------------*/
   switch (a_type) {
   case ':' :  strcpy (x_pre, ""     );     break;
   case '>' :  strcpy (x_pre, "\n"   );     break;
   case '-' :  strcpy (x_pre, "  -- ");     break;
   case '+' :  strcpy (x_pre, "    -- ");   break;
   case '~' :  strcpy (x_pre, "\n"   );     break;
   case 'P' :  strcpy (x_pre, BOLD_GRN "SUCCESS, ");
               strcpy (x_suf, BOLD_OFF);
               break;
   case 'p' :  strcpy (x_pre, "\n" BOLD_GRN "SUCCESS, ");
               strcpy (x_suf, BOLD_OFF);
               break;
   case 'W' :  strcpy (x_pre, BOLD_YEL "WARNING, ");
               strcpy (x_suf, BOLD_OFF);
               break;
   case 'w' :  strcpy (x_pre, "\n" BOLD_YEL "WARNING, ");
               strcpy (x_suf, BOLD_OFF);
               break;
   case 'F' :  strcpy (x_pre, BOLD_ERR "FAILED, ");
               strcpy (x_suf, BOLD_OFF);
               break;
   case 'f' :  strcpy (x_pre, "\n" BOLD_ERR "FAILED, ");
               strcpy (x_suf, BOLD_OFF);
               break;
   }
   /*---(va_args)------------------------*/
   va_start   (x_args, a_format);
   if (s_mlive == 'y' && s_mfile != NULL) {
      vsnprintf  (s_mprint, LEN_FULL - 1, a_format, x_args);
      fprintf    (s_mfile, "%s%s%s\n", x_pre, s_mprint, x_suf);
      fflush     (s_mfile);
   }
   va_end     (x_args);
   /*---(complete)-----------------------*/
   return 0;
}



/*====================------------------------------------====================*/
/*===----                     message and error                        ----===*/
/*====================------------------------------------====================*/
static void  o___ALL_____________o () { return; }

char
yURG_all_clear          (void)
{
   yURG_msg_clear ();
   yURG_err_clear ();
   return 0;
}

char
yURG_all_tmp            (void)
{
   yURG_msg_tmp ();
   yURG_msg_clear ();
   yURG_err_tmp ();
   yURG_err_clear ();
   return 0;
}

char
yURG_all_live           (void)
{
   yURG_msg_live ();
   yURG_err_live ();
   return 0;
}

char
yURG_all_none           (void)
{
   yURG_msg_none ();
   yURG_err_none ();
   return 0;
}

char
yURG_all_mute           (void)
{
   yURG_msg_mute ();
   yURG_err_mute ();
   return 0;
}

char
yURG_all_off            (void)
{
   yURG_all_mute ();
   yURG_all_none ();
   return 0;
}

char
yURG_all_tmplive        (void)
{
   yURG_msg_tmp   ();
   yURG_msg_live  ();
   yURG_msg_clear ();
   yURG_err_tmp   ();
   yURG_err_live  ();
   yURG_err_clear ();
   return 0;
}



/*====================------------------------------------====================*/
/*===----                          history                             ----===*/
/*====================------------------------------------====================*/
static void  o___HISTORY_________o () { return; }

char* yURG_msg_last  (void)  { return s_mprint; }
char  yURG_msg_clear (void)  { strcpy (s_mprint, "");  return 0; }

char
yURG_msg_purge          (void)
{
   yURG_msg_std ();
   system ("rm -rf /tmp/console.txt    > /dev/null  2>&1");
   return 0;
}



/*====================------------------------------------====================*/
/*===----                       unit test accessor                     ----===*/
/*====================------------------------------------====================*/
static void  o___UNITTEST________o () { return; }

char*            /* [------] unit test accessor ------------------------------*/
yurg_msg__unit          (char *a_question, int a_num)
{
   char        t           [LEN_HUND]  = "";
   char        s           [LEN_HUND]  = "";
   char        u           [LEN_LABEL] = "";
   /*---(initialize)---------------------*/
   strncpy (unit_answer, "MSG unit         : unknown request", 100);
   /*---(string testing)-----------------*/
   if (strcmp (a_question, "result"    ) == 0) {
      snprintf  (u, LEN_LABEL, "%p",         s_mfile);
      snprintf  (t, LEN_HUND, "å%-.30sæ"   , s_mname);
      snprintf  (s, LEN_HUND, "%2då%-.60sæ", strlen (s_mprint), s_mprint);
      snprintf (unit_answer, LEN_RECD, "MSG result       : %-10.10s  %-32.32s  %c  %s", u, t, s_mlive, s);
   }
   /*---(complete)-----------------------*/
   return unit_answer;
}


