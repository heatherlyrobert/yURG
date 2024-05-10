/*===[[ START ]]==============================================================*/
#include    "yURG.h"
#include    "yURG_priv.h"



static char  s_eprint  [LEN_RECD] = "";



/*====================------------------------------------====================*/
/*===----                   file openning and closing                  ----===*/
/*====================------------------------------------====================*/
static void  o___FILE____________o () { return; }

char yurg_err_open      (char a_name [LEN_FULL]) { return yurg_msg__open  ('e', a_name, &(myURG_priv.efile), myURG_priv.ename); }
char yurg_err_close     (void) { return yurg_msg__close ('e', &(myURG_priv.efile), myURG_priv.ename); }



/*====================------------------------------------====================*/
/*===----                      message destination                     ----===*/
/*====================------------------------------------====================*/
static void  o___DEST____________o () { return; }

char
yurg_err__dest          (char a_name [LEN_FULL])
{
   char        rc          =    0;
   DEBUG_ARGS   yLOG_enter   (__FUNCTION__);
   rc = yurg_err_close ();
   rc = yurg_err_open  (a_name);
   DEBUG_ARGS   yLOG_value   ("open"      , rc);
   DEBUG_ARGS   yLOG_exit    (__FUNCTION__);
   return rc;
}

char yURG_err_std       (void) { return yurg_err__dest ("stderr"); }
char yURG_err_none      (void) { return yurg_err__dest ("/dev/null"); }
char yURG_err_tmp       (void) { return yurg_err__dest (YURG_ERR); }
char yURG_err_custom    (char a_name [LEN_FULL]) { return yurg_err__dest (a_name); }



/*====================------------------------------------====================*/
/*===----                         live vs mute                         ----===*/
/*====================------------------------------------====================*/
static void  o___MUTING__________o () { return; }

char yURG_err_mute  (void) { myURG_priv.elive = '-'; return 1; }
char yURG_err_live  (void) { myURG_priv.elive = 'y'; return 1; }



/*====================------------------------------------====================*/
/*===----                         main driver                          ----===*/
/*====================------------------------------------====================*/
static void  o___DRIVER__________o () { return; }

char
yURG_err                (cchar a_type, cchar *a_format, ...)
{
   /*---(locals)-----------+-----+-----+-*/
   char        x_pre       [LEN_LABEL] = "";
   char        x_suf       [LEN_LABEL] = "";
   char        x_label     [LEN_LABEL] = "";
   va_list     x_args;
   /*---(check output)-------------------*/
   if (myURG_priv.efile == NULL)  yURG_err_std ();
   /*---(prefix)-------------------------*/
   strcpy (x_suf, BOLD_OFF);
   switch (a_type) {
   case 'W' :  strcpy (x_pre, BOLD_YEL "");            strcpy (x_label, "warning, ");   break;
   case 'F' :  strcpy (x_pre, BOLD_ERR "");            strcpy (x_label, "FATAL, "  );   break;
   case 'w' :  strcpy (x_pre, "  " BOLD_YEL "** ");    strcpy (x_label, "warning, ");   break;
   case 'f' :  strcpy (x_pre, "  " BOLD_ERR "** ");    strcpy (x_label, "FATAL, "  );   break;
   case 'ÿ' :  strcpy (x_pre, "    " BOLD_YEL "** ");  strcpy (x_label, "warning, ");   break;
   case 'ü' :  strcpy (x_pre, "    " BOLD_ERR "** ");  strcpy (x_label, "FATAL, "  );   break;
   case ':' :  strcpy (x_suf, ""); break;
   }
   /*---(va_args)------------------------*/
   va_start   (x_args, a_format);
   if (myURG_priv.elive == 'y' && myURG_priv.efile != NULL) {
      vsnprintf  (s_eprint, LEN_FULL - 1, a_format, x_args);
      /*> if (myURG_priv.efile == NULL)  fprintf (myURG_priv.efile, "%s%s%s¦", x_label, s_eprint, x_suf);            <* 
       *> else                  fprintf (myURG_priv.efile, "%s%s%s%s¦", x_pre, x_label, s_eprint, x_suf);   <*/
      fprintf (myURG_priv.efile, "%s%s%s%s\n", x_pre, x_label, s_eprint, x_suf);
      fflush     (myURG_priv.efile);
   }
   va_end     (x_args);
   /*---(complete)-----------------------*/
   return 0;
}



/*====================------------------------------------====================*/
/*===----                          history                             ----===*/
/*====================------------------------------------====================*/
static void  o___HISTORY_________o () { return; }

char* yURG_err_last  (void)  { return s_eprint; }
char  yURG_err_clear (void)  { strcpy (s_eprint, "");  return 0; }

char
yURG_err_purge          (void)
{
   yURG_err_std ();
   system ("rm -rf /tmp/error.txt    > /dev/null  2>&1");
   return 0;
}



/*====================------------------------------------====================*/
/*===----                       unit test accessor                     ----===*/
/*====================------------------------------------====================*/
static void  o___UNITTEST________o () { return; }

char*            /* [------] unit test accessor ------------------------------*/
yurg_err__unit          (char *a_question, int a_num)
{
   char        t           [LEN_HUND]  = "";
   char        s           [LEN_HUND]  = "";
   char        u           [LEN_LABEL] = "";
   /*---(initialize)---------------------*/
   strncpy (unit_answer, "ERR unit         : unknown request", 100);
   /*---(string testing)-----------------*/
   if (strcmp (a_question, "result"    ) == 0) {
      snprintf  (u, LEN_LABEL, "%p",         myURG_priv.efile);
      snprintf  (t, LEN_HUND, "å%-.30sæ"   , myURG_priv.ename);
      snprintf  (s, LEN_HUND, "%2då%-.60sæ", strlen (s_eprint), s_eprint);
      snprintf (unit_answer, LEN_RECD, "ERR result       : %-10.10s  %-32.32s  %c  %s", u, t, myURG_priv.elive, s);
   }
   /*---(complete)-----------------------*/
   return unit_answer;
}


