/*===[[ START ]]==============================================================*/
#include    "yURG.h"
#include    "yURG_priv.h"



static char  s_ename   [LEN_FULL] = "stderr";
static FILE *s_efile   = NULL;
static char  s_elive   = 'y';

static char  s_mname   [LEN_FULL] = "stdout";
static FILE *s_mfile   = NULL;
static char  s_mlive   = 'y';

static char  s_print   [LEN_RECD] = "";
static char  s_perror  [LEN_FULL] = "";
static char  s_status  [LEN_FULL] = "";

static char  s_peek    [LEN_RECD] = "";


char
yurg_category           (cchar *a_prog, cchar a_type)
{
   /*---(locals)-----------+-----+-----+-*/
   int         i           =    0;
   int         j           =    0;
   int         k           =    0;
   int         x_len       =    0;
   char        x_upper     [LEN_LABEL] = "";
   char        x_header    [LEN_FULL ] = "";
   char        x_debug     [LEN_LABEL] = "";
   char        x_urgent    [LEN_LABEL] = "";
   int         c           =    0;
   /*---(list universals)----------------*/
   if (a_prog != NULL) {
      printf ("yURG urgents report\n\n");
      if (myURG.loud != 'y') {
         printf ("YOU ARE NOT RUNNING IN DEBUG MODE\n");
         printf ("urgents are only active if debug version of program is used.\n");
         printf ("to run %s in debug mode, use %s_debug.\n\n", a_prog, a_prog);
      }
   }
   /*---(cycle types)--------------------*/
   for (i = 0; i < MAX_URGS; ++i) {
      /*---(filter)----------------------*/
      if (yURG_type [i].type     == '\0')                            break;
      if (yURG_type [i].type     != a_type)                          continue;
      /*---(header)----------------------*/
      if (yURG_type [i].sub      == '-' ) {
         sprintf (x_header, "%s --------------------------", yURG_type [i].desc);
         printf ("%-23.23s ---description-------------------------- ---macro-----------\n", x_header);
      } else {
         sprintf (x_header, "---%s---------------------------", yURG_type [i].desc);
         printf  ("   %-30.30s\n", x_header);
      }
      /*---(cycle urgents)---------------*/
      for (j = 0; j < MAX_URGS; ++j) {
         /*---(filter)----------------------*/
         if (yURG_info [j].abbr     == '\0')                            break;
         if (yURG_info [j].type     != yURG_type [i].type)              continue;
         if (yURG_info [j].sub      != yURG_type [i].sub)               continue;
         ++c;
         /*---(convert to upper)------------*/
         strncpy (x_upper, yURG_info [j].full, LEN_LABEL);
         x_len = strlen (x_upper);
         for (k = 0; k < x_len; ++k)  x_upper [k] = toupper (x_upper [k]);
         /*---(debug macro)-----------------*/
         if (yURG_info [j].point == NULL)   strcpy  (x_debug, "-");
         else                               sprintf (x_debug, "DEBUG_%s", x_upper);
         /*---(printf)----------------------*/
         if (yURG_info [j].abbr  != '-')    sprintf (x_urgent, "@%c, @@%-13.13s", yURG_info [j].abbr, yURG_info [j].full);
         else                               sprintf (x_urgent, "@@%-15.15s"     , yURG_info [j].full);
         printf ("   %-20.20s %-40.40s %-20.20s\n",
               x_urgent, yURG_info [j].desc , x_debug);
      }
   }
   /*---(grand totals)-------------------*/
   printf ("   --- sub-total = %2d --------------------------------------------------------------\n\n", c);
   /*---(complete)-----------------------*/
   return c;
}

char
yurg_urgents            (cchar *a_prog)
{
   int         n           =    0;
   n   += yurg_category     (a_prog, 'u');
   n   += yurg_category     (NULL  , 'l');
   n   += yurg_category     (NULL  , 'p');
   n   += yurg_category     (NULL  , 'h');
   printf ("GRAND TOTAL %3d\n\n", n);
   return 0;
}

/*> char         /+--> display all urgents and status --------[ ------ [ ------ ]-+/                            <* 
 *> yURG_help          (char *a_prog)                                                                           <* 
 *> {                                                                                                           <* 
 *>    /+---(locals)-----------+-----------+-+/                                                                 <* 
 *>    int         i           = 0;                                                                             <* 
 *>    int         j           = 0;                                                                             <* 
 *>    int         k           = 0;                                                                             <* 
 *>    char        x_type      = ' ';                                                                           <* 
 *>    char        x_subsave   = ' ';                                                                           <* 
 *>    int         x_count     = 0;                                                                             <* 
 *>    int         x_countmas  = 0;                                                                             <* 
 *>    int         x_total     = 0;                                                                             <* 
 *>    int         x_totalmas  = 0;                                                                             <* 
 *>    char        x_upper     [LEN_LABEL] = "";                                                                <* 
 *>    char        x_mas       = ' ';                                                                           <* 
 *>    int         x_len       = 0;                                                                             <* 
 *>    char        x_header    [LEN_FULL  ] = "";                                                               <* 
 *>    /+---(list universals)----------------+/                                                                 <* 
 *>    printf ("yURG : urgent inventory report\n\n");                                                           <* 
 *>    if (myURG.loud != 'y') {                                                                            <* 
 *>       printf ("YOU ARE NOT RUNNING IN DEBUG MODE\n");                                                       <* 
 *>       printf ("urgents are only active if debug version of program is used (except @v).\n");                <* 
 *>       printf ("to run %s in debug mode, use %s_debug\n\n", a_progname, a_progname);                         <* 
 *>    }                                                                                                        <* 
 *>    /+---(cycle types)--------------------+/                                                                 <* 
 *>    for (i = 0; i < MAX_URGS; ++i) {                                                                         <* 
 *>       /+---(filter)----------------------+/                                                                 <* 
 *>       if (yURG_type [i].type     == '\0')                            break;                                 <* 
 *>       if (yURG_type [i].sub      != '-' )                            continue;                              <* 
 *>       x_type = yURG_type [i].type;                                                                          <* 
 *>       sprintf (x_header, "%s --------------------------", yURG_type [i].desc);                              <* 
 *>       printf ("%-21.21s mas ---description----------------------------\n", x_header);                       <* 
 *>       x_subsave  = '?';                                                                                     <* 
 *>       /+---(cycle urgents)---------------+/                                                                 <* 
 *>       for (j = 0; j < MAX_URGS; ++j) {                                                                      <* 
 *>          /+---(filter)-------------------+/                                                                 <* 
 *>          if (yURG_info [j].abbr  == '\0')                            break;                                 <* 
 *>          if (yURG_info [j].type  != x_type)                          continue;                              <* 
 *>          /+---(find mas version)---------+/                                                                 <* 
 *>          x_mas = '-';                                                                                       <* 
 *>          strncpy (x_upper, yURG_info [j].full, LEN_LABEL);                                                  <* 
 *>          x_len = strlen  (x_upper);                                                                         <* 
 *>          for (k = 0; k < x_len; ++k)  x_upper [k] = toupper (x_upper [k]);                                  <* 
 *>          for (k = 0; k < MAX_URGS; ++k) {                                                                   <* 
 *>             if (yURG_info [k].abbr  == '\0')                         break;                                 <* 
 *>             if (yURG_info [k].full[0] != x_upper [0])                continue;                              <* 
 *>             if (strcmp (yURG_info [k].full, x_upper) != 0)           continue;                              <* 
 *>             x_mas = 'y';                                                                                    <* 
 *>             break;                                                                                          <* 
 *>          }                                                                                                  <* 
 *>          /+---(print)--------------------+/                                                                 <* 
 *>          if (yURG_info [j].sub != x_subsave && yURG_info [j].sub != '-') {                                  <* 
 *>             for (k = 0; k < MAX_URGS; ++k) {                                                                <* 
 *>                /+---(filter)----------------------+/                                                        <* 
 *>                if (yURG_type [k].type    == '\0')                    break;                                 <* 
 *>                if (yURG_type [k].type    != x_type)                  continue;                              <* 
 *>                if (yURG_type [k].sub != yURG_info [j].sub)   continue;                                      <* 
 *>                sprintf (x_header, "---%s---------------------------", yURG_type [k].desc);                  <* 
 *>                printf  ("   %-30.30s\n", x_header);                                                         <* 
 *>                break;                                                                                       <* 
 *>             }                                                                                               <* 
 *>             x_subsave = yURG_info [j].sub;                                                                  <* 
 *>          }                                                                                                  <* 
 *>          if (yURG_info [j].abbr  != '-')                                                                    <* 
 *>             printf ("   @%c,@@%-14.14s %c  %-40.40s\n",                                                     <* 
 *>                   yURG_info [j].abbr , yURG_info [j].full , x_mas, yURG_info [j].desc );                    <* 
 *>          else                                                                                               <* 
 *>             printf ("   @@%-14.14s    %c  %-40.40s\n",                                                      <* 
 *>                   yURG_info [j].full , x_mas, yURG_info [j].desc );                                         <* 
 *>          /+---(totals)-------------------+/                                                                 <* 
 *>          ++x_count;                                                                                         <* 
*>          if (x_mas == 'y')  ++x_countmas;                                                                   <* 
*>          /+---(done)---------------------+/                                                                 <* 
*>       }                                                                                                     <* 
*>       /+---(sub-totals)------------------+/                                                                 <* 
*>       printf ("   ---count = %d (%d mas)\n\n", x_count, x_countmas);                                        <* 
*>       x_total     += x_count;                                                                               <* 
*>       x_totalmas  += x_countmas;                                                                            <* 
*>       x_count      = x_countmas = 0;                                                                        <* 
*>    }                                                                                                        <* 
*>    /+---(grand totals)-------------------+/                                                                 <* 
*>    printf ("grand total count = %d (%d mas), %d overall\n\n", x_total, x_totalmas, x_total + x_totalmas);   <* 
*>    /+---(complete)-----------------------+/                                                                 <* 
*>    return 0;                                                                                                <* 
*> }                                                                                                           <*/

char         /*--> display all urgents and status --------[ ------ [ ------ ]-*/
yURG_list          (void)
{
   /*---(locals)-----------+-----------+-*/
   int         i           = 0;
   /*---(list)---------------------------*/
   for (i = 0; i < MAX_URGS; ++i) {
      /*---(stop at end)-----------------*/
      if (yURG_info [i].abbr  == '\0')     break;
      /*---(filter)----------------------*/
      if (yURG_info [i].type  == '-')      continue;
      /*---(show)------------------------*/
      printf ("%3d %c %-15.15s %-40.40s %c %10p %c\n", i,
            yURG_info [i].abbr , yURG_info [i].full ,
            yURG_info [i].desc , yURG_info [i].type ,
            yURG_info [i].point, *(yURG_info [i].point));
   }
   /*---(complete)-----------------------*/
   return 0;
}

char         /*--> display all urgents and status --------[ ------ [ ------ ]-*/
yURG_summ          (void)
{
   /*---(locals)-----------+-----------+-*/
   int         i           = 0;
   /*---(list)---------------------------*/
   DEBUG_ARGS   yLOG_note   ("universal urgents");
   for (i = 0; i < MAX_URGS; ++i) {
      /*---(stop at end)-----------------*/
      if (yURG_info [i].abbr  == '\0')     break;
      /*---(filter)----------------------*/
      if (yURG_info [i].type  != 'u')      continue;
      if (yURG_info [i].type  == '-')      continue;
      if (yURG_info [i].point == NULL)     continue;
      /*---(show)------------------------*/
      DEBUG_ARGS   yLOG_complex (yURG_info [i].full, "%c, %c, %s", *(yURG_info [i].point), yURG_info [i].abbr, yURG_info [i].desc);
   }
   DEBUG_ARGS   yLOG_note   ("specific urgents");
   for (i = 0; i < MAX_URGS; ++i) {
      /*---(stop at end)-----------------*/
      if (yURG_info [i].abbr  == '\0')     break;
      /*---(filter)----------------------*/
      if (yURG_info [i].type  == 'u')      continue;
      if (yURG_info [i].type  == '-')      continue;
      if (yURG_info [i].point == NULL)     continue;
      /*---(show)------------------------*/
      DEBUG_ARGS   yLOG_complex (yURG_info [i].full, "%c, %c, %s", *(yURG_info [i].point), yURG_info [i].abbr, yURG_info [i].desc);
   }
   /*---(complete)-----------------------*/
   return 0;
}



/*====================------------------------------------====================*/
/*===----                      error reporting                         ----===*/
/*====================------------------------------------====================*/
static void  o___ERRORS__________o () { return; }

char
yurg_rptg__eclose       (void)
{
   DEBUG_ARGS   yLOG_point   ("s_efile"   , s_efile);
   if (s_efile != NULL && s_efile != stderr) {
      DEBUG_ARGS   yLOG_note    ("closing bitbucket or custom error file");
      fclose (s_efile);
      s_efile = NULL;
   }
   return 0;
}

char
yurg_rptg__eopen        (char *a_name)
{
   char        rce         =  -10;
   DEBUG_ARGS   yLOG_info    ("a_name"    , a_name);
   --rce;  if (a_name == NULL) {
      DEBUG_ARGS   yLOG_note    ("a_name is null, reverting to stderr");
      yURG_err_std ();
      return rce;
   }
   --rce;  if (strlen (a_name) <= 0) {
      DEBUG_ARGS   yLOG_note    ("a_name is empty, reverting to stderr");
      yURG_err_std ();
      return rce;
   }
   s_efile = fopen (a_name, "wt");
   --rce;  if (s_efile == NULL) {
      DEBUG_ARGS   yLOG_note    ("can not open, reverting to stderr");
      yURG_err_std ();
      return rce;
   }
   strcpy (s_ename, a_name);
   DEBUG_ARGS   yLOG_point   ("s_efile"   , s_efile);
   return 0;
}

char
yURG_err_std            (void)
{
   DEBUG_ARGS   yLOG_enter   (__FUNCTION__);
   yurg_rptg__eclose ();
   s_efile = stderr;
   strcpy (s_ename, "stderr");
   DEBUG_ARGS   yLOG_point   ("s_efile"   , s_efile);
   DEBUG_ARGS   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yURG_err_none           (void)
{
   char        rc          =    0;
   DEBUG_ARGS   yLOG_enter   (__FUNCTION__);
   rc = yurg_rptg__eclose ();
   rc = yurg_rptg__eopen  ("/dev/null");
   DEBUG_ARGS   yLOG_exit    (__FUNCTION__);
   return rc;
}

char
yURG_err_tmp            (void)
{
   char        rc          =    0;
   DEBUG_ARGS   yLOG_enter   (__FUNCTION__);
   rc = yurg_rptg__eclose ();
   rc = yurg_rptg__eopen  (YURG_ERR);
   DEBUG_ARGS   yLOG_exit    (__FUNCTION__);
   return rc;
}

char
yURG_err_custom         (char *a_name)
{
   char        rc          =    0;
   DEBUG_ARGS   yLOG_enter   (__FUNCTION__);
   rc = yurg_rptg__eclose ();
   rc = yurg_rptg__eopen  (a_name);
   DEBUG_ARGS   yLOG_exit    (__FUNCTION__);
   return rc;
}

char yURG_err_mute  (void) { s_elive = '-'; }
char yURG_err_live  (void) { s_elive = 'y'; }

char
yURG_err                (cchar a_type, cchar *a_format, ...)
{
   /*---(locals)-----------+-----+-----+-*/
   char        x_pre       [LEN_LABEL] = "";
   char        x_suf       [LEN_LABEL] = "";
   char        x_label     [LEN_LABEL] = "";
   va_list     x_args;
   /*---(check output)-------------------*/
   if (s_efile == NULL)  yURG_err_std ();
   /*---(prefix)-------------------------*/
   switch (a_type) {
   case 'W' :  strcpy (x_pre, BOLD_YEL "");            strcpy (x_label, "warning, ");   break;
   case 'F' :  strcpy (x_pre, BOLD_ERR "");            strcpy (x_label, "FATAL, "  );   break;
   case 'w' :  strcpy (x_pre, "  " BOLD_YEL "** ");    strcpy (x_label, "warning, ");   break;
   case 'f' :  strcpy (x_pre, "  " BOLD_ERR "** ");    strcpy (x_label, "FATAL, "  );   break;
   case 'ÿ' :  strcpy (x_pre, "    " BOLD_YEL "** ");  strcpy (x_label, "warning, ");   break;
   case 'ü' :  strcpy (x_pre, "    " BOLD_ERR "** ");  strcpy (x_label, "FATAL, "  );   break;
   }
   strcpy (x_suf, BOLD_OFF);
   /*---(va_args)------------------------*/
   va_start   (x_args, a_format);
   vsnprintf  (s_perror, LEN_FULL - 1, a_format, x_args);
   va_end     (x_args);
   if (s_elive == 'y') {
      if (s_efile == NULL)  fprintf (s_efile, "%s%s%s\n", x_label, s_perror, x_suf);
      else                  fprintf (s_efile, "%s%s%s%s\n", x_pre, x_label, s_perror, x_suf);
      fflush     (s_efile);
   }
   /*---(complete)-----------------------*/
   return 0;
}

char* yURG_err_last  (void)  { return s_perror; }

char  yURG_err_clear (void)  { strcpy (s_perror, "");  return 0; }

char
yURG_err_purge          (void)
{
   yURG_err_std ();
   system ("rm -rf /tmp/errors.txt     > /dev/null  2>&1");
   return 0;
}


/*====================------------------------------------====================*/
/*===----                      error reporting                         ----===*/
/*====================------------------------------------====================*/
static void  o___OPERATOR________o () { return; }

char
yurg_rptg__cclose       (void)
{
   DEBUG_ARGS   yLOG_point   ("s_mfile" , s_mfile);
   if (s_mfile != NULL && s_mfile != stdout) {
      DEBUG_ARGS   yLOG_note    ("closing bitbucket or custom console file");
      fclose (s_mfile);
      s_mfile = NULL;
   }
   return 0;
}

char
yurg_rptg__copen        (char *a_name)
{
   char        rce         =  -10;
   DEBUG_ARGS   yLOG_info    ("a_name"    , a_name);
   --rce;  if (a_name == NULL) {
      DEBUG_ARGS   yLOG_note    ("a_name is null, reverting to stdout");
      yURG_msg_std ();
      return rce;
   }
   --rce;  if (strlen (a_name) <= 0) {
      DEBUG_ARGS   yLOG_note    ("a_name is empty, reverting to stdout");
      yURG_msg_std ();
      return rce;
   }
   s_mfile = fopen (a_name, "wt");
   --rce;  if (s_mfile == NULL) {
      DEBUG_ARGS   yLOG_note    ("can not open, reverting to stdout");
      yURG_msg_std ();
      return rce;
   }
   strcpy (s_mname, a_name);
   DEBUG_ARGS   yLOG_point   ("s_mfile"   , s_mfile);
   return 0;
}

char
yURG_msg_std            (void)
{
   DEBUG_ARGS   yLOG_enter   (__FUNCTION__);
   yurg_rptg__cclose ();
   s_mfile = stdout;
   strcpy (s_mname, "stdout");
   DEBUG_ARGS   yLOG_point   ("s_mfile"   , s_mfile);
   DEBUG_ARGS   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yURG_msg_none           (void)
{
   char        rc          =    0;
   DEBUG_ARGS   yLOG_enter   (__FUNCTION__);
   rc = yurg_rptg__cclose ();
   rc = yurg_rptg__copen  ("/dev/null");
   DEBUG_ARGS   yLOG_exit    (__FUNCTION__);
   return rc;
}

char
yURG_msg_tmp            (void)
{
   char        rc          =    0;
   DEBUG_ARGS   yLOG_enter   (__FUNCTION__);
   rc = yurg_rptg__cclose ();
   rc = yurg_rptg__copen  (YURG_MSG);
   DEBUG_ARGS   yLOG_exit    (__FUNCTION__);
   return rc;
}

char
yURG_msg_custom         (char *a_name)
{
   char        rc          =    0;
   DEBUG_ARGS   yLOG_enter   (__FUNCTION__);
   rc = yurg_rptg__cclose ();
   rc = yurg_rptg__copen  (a_name);
   DEBUG_ARGS   yLOG_exit    (__FUNCTION__);
   return rc;
}

char yURG_msg_mute  (void) { s_mlive = '-'; }
char yURG_msg_live  (void) { s_mlive = 'y'; }

char
yURG_msg                (cchar a_type, cchar *a_format, ...)
{
   /*---(locals)-----------+-----+-----+-*/
   char        x_pre       [LEN_LABEL] = "";
   va_list     x_args;
   /*---(check output)-------------------*/
   if (s_mfile == NULL)  yURG_msg_std ();
   /*---(prefix)-------------------------*/
   switch (a_type) {
   case '>' :  strcpy (x_pre, ""     );     break;
   case '-' :  strcpy (x_pre, "  -- ");     break;
   case '+' :  strcpy (x_pre, "    -- ");   break;
   }
   /*---(va_args)------------------------*/
   va_start   (x_args, a_format);
   if (s_mlive == 'y') {
      vsnprintf  (s_print, LEN_FULL - 1, a_format, x_args);
      fprintf    (s_mfile, "%s%s\n", x_pre, s_print);
      fflush     (s_mfile);
   }
   va_end     (x_args);
   /*---(complete)-----------------------*/
   return 0;
}

char* yURG_msg_last  (void)  { return s_print; }

char  yURG_msg_clear (void)  { strcpy (s_print, "");  return 0; }

char
yURG_msg_purge          (void)
{
   yURG_msg_std ();
   system ("rm -rf /tmp/console.txt    > /dev/null  2>&1");
   return 0;
}

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
yURG_all_mute           (void)
{
   yURG_msg_mute ();
   yURG_err_mute ();
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

char*
yURG_mute_status        (void)
{
   char        t           [LEN_HUND]  = "";
   char        s           [LEN_HUND]  = "";
   snprintf  (t, LEN_HUND, "%c å%-.25sæ"   , s_mlive, s_mname);
   snprintf  (s, LEN_HUND, "%c å%-.25sæ"   , s_elive, s_ename);
   sprintf (s_status, "%-30.30s   %s", t, s);
   return s_status;
}



/*====================------------------------------------====================*/
/*===----                    files and directories                     ----===*/
/*====================------------------------------------====================*/
static void      o___REVIEW__________________o (void) {;}

char
yURG_touch              (cchar *a_file, cchar *a_own, cchar *a_grp, cchar *a_perms)
{
   char        x_cmd       [LEN_RECD]  = "";
   sprintf (x_cmd, "touch %s       > /dev/null  2>&1", a_file);
   system  (x_cmd);
   sprintf (x_cmd, "chown %s:%s %s > /dev/null  2>&1", a_own  , a_grp  , a_file);
   system  (x_cmd);
   sprintf (x_cmd, "chmod %s %s    > /dev/null  2>&1", a_perms, a_file );
   system  (x_cmd);
   return 0;
}

char
yURG_rm                 (cchar *a_file)
{
   char        x_cmd       [LEN_RECD]  = "";
   sprintf (x_cmd, "rm -f %s       > /dev/null  2>&1", a_file);
   system  (x_cmd);
   return 0;
}

char
yURG_mkdir              (cchar *a_dir, cchar *a_own, cchar *a_grp, cchar *a_perms)
{
   char        x_cmd       [LEN_RECD]  = "";
   sprintf (x_cmd, "mkdir %s       > /dev/null  2>&1", a_dir);
   system  (x_cmd);
   sprintf (x_cmd, "chown %s:%s %s > /dev/null  2>&1", a_own  , a_grp  , a_dir);
   system  (x_cmd);
   sprintf (x_cmd, "chmod %s %s    > /dev/null  2>&1", a_perms, a_dir  );
   system  (x_cmd);
   return 0;
}

char
yURG_rmdir              (cchar *a_dir)
{
   char        x_cmd       [LEN_RECD];
   sprintf (x_cmd, "rm    -fr %s   > /dev/null  2>&1", a_dir);
   system  (x_cmd);
   return 0;
}

char*
yurg_peek               (cchar *a_name, int n, int *a_count)
{
   char        t           [LEN_RECD]  = "";
   FILE       *f           = NULL;
   int         c           =    0;
   int         x_len       =    0;
   static int  x_last      =    0;
   if (a_count != NULL)  *a_count = -1;
   if (a_name == NULL)            return "(null name)";
   if (strcmp (a_name, "") == 0)  return "(empty name)";
   if (a_count != NULL)  *a_count = 0;
   strcpy (s_peek, "");
   f = fopen (a_name, "rt");
   if (f == NULL) {
      if (a_count != NULL)  *a_count = -1;
      return "(not found)";
   }
   switch (n) {
   case -1 :
      fclose (f);
      return "(found)";
      break;
   case 'º' :
      n = x_last = 0;
      break;
   case '»' :
      n = x_last = 999;
      break;
   case 'Ö' : case '·' :  /* · means default */
      n = ++x_last;
      break;
   case '×' :
      n = --x_last;
      break;
   default :
      x_last = n;
      break;
   }
   if (n < 0)  n = x_last = 0;
   while (1) {
      fgets (t, LEN_RECD, f);
      if (feof (f))  break;
      if (c == x_last)    strcpy (s_peek, t);
      if (x_last == 999)  strcpy (s_peek, t);
      ++c;
   }
   x_len = strlen (s_peek);
   if (x_len > 0 && s_peek [x_len - 1] == '\n')  s_peek [--x_len] = '\0';
   fclose (f);
   if (a_count != NULL)  *a_count = c;
   return s_peek;
}

int
yURG_peek_count         (cchar *a_name)
{
   int         c           =    0;
   yurg_peek (a_name, 0, &c);
   return c;
}

char*
yURG_peek               (cchar *a_name, int n)
{
   return yurg_peek (a_name, n, NULL);
}

char 
yURG_peek_exists        (cchar *a_name)
{
   int         rc          =    0;
   tSTAT       s;
   rc = stat (a_name, &s);
   return rc;
}

char*
yURG_peek_fill          (cchar *a_name, int n)
{
   int         i           =    0;
   int         l           =    0;
   strcpy (s_print, yurg_peek (a_name, n, NULL));
   l = strlen (s_print);
   if (l == 0)  return "n/a";
   for (i = 0; i < l; ++i) {
      if (s_print [i] == ' ')   s_print [i] = '²';
      if (s_print [i] == '')  s_print [i] = '§';
      if (s_print [i] == '\t')  s_print [i] = 'Ú';
   }
   return s_print;
}



/*====================------------------------------------====================*/
/*===----                    unit testing accessor                     ----===*/
/*====================------------------------------------====================*/
static void      o___UNITTEST________________o (void) {;}

char
yurg_rptg__test_clear   (void)
{
   yURG_err_clear ();
   strcpy (s_ename, "stderr");
   s_efile  = stderr;
   yURG_msg_clear ();
   strcpy (s_mname, "stdout");
   s_mfile  = stdout;
   strcpy (s_print, "");
   return 0;
}

char*            /* [------] unit test accessor ------------------------------*/
yurg_rptg__unit         (char *a_question, int a_num)
{
   char        t           [LEN_HUND]  = "";
   char        s           [LEN_HUND]  = "";
   /*---(initialize)---------------------*/
   strncpy (unit_answer, "RPTG unit        : unknown request", 100);
   /*---(string testing)-----------------*/
   if      (strcmp (a_question, "error"     ) == 0) {
      snprintf  (t, LEN_HUND, "å%-.15sæ"   , s_ename);
      snprintf  (s, LEN_HUND, "%2då%-.60sæ", strlen (s_perror), s_perror);
      snprintf (unit_answer, LEN_RECD, "RPTG error       : %-17.17s  %s", t, s);
   }
   else if (strcmp (a_question, "console"   ) == 0) {
      snprintf  (t, LEN_HUND, "å%-.15sæ"   , s_mname);
      snprintf  (s, LEN_HUND, "%2då%-.60sæ", strlen (s_print), s_print);
      snprintf (unit_answer, LEN_RECD, "RPTG console     : %-17.17s  %s", t, s);
   }
   /*---(complete)-----------------------*/
   return unit_answer;
}


