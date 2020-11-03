/*===[[ START ]]==============================================================*/
#include    "yURG.h"
#include    "yURG_priv.h"

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

static char  s_name   [LEN_FULL] = "stderr";
static FILE *s_error  = NULL;
static char  s_print  [LEN_FULL] = "";

char
yurg_rptg__eclose       (void)
{
   DEBUG_ARGS   yLOG_point   ("s_error"   , s_error);
   if (s_error != NULL && s_error != stderr) {
      DEBUG_ARGS   yLOG_note    ("closing bitbucket or custom error file");
      fclose (s_error);
      s_error = NULL;
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
      yURG_stderr ();
      return rce;
   }
   --rce;  if (strlen (a_name) <= 0) {
      DEBUG_ARGS   yLOG_note    ("a_name is empty, reverting to stderr");
      yURG_stderr ();
      return rce;
   }
   s_error = fopen (a_name, "wt");
   --rce;  if (s_error == NULL) {
      DEBUG_ARGS   yLOG_note    ("can not open, reverting to stderr");
      yURG_stderr ();
      return rce;
   }
   strcpy (s_name, a_name);
   DEBUG_ARGS   yLOG_point   ("s_error"   , s_error);
   return 0;
}

char
yURG_stderr             (void)
{
   DEBUG_ARGS   yLOG_enter   (__FUNCTION__);
   yurg_rptg__eclose ();
   s_error = stderr;
   strcpy (s_name, "stderr");
   DEBUG_ARGS   yLOG_point   ("s_error"   , s_error);
   DEBUG_ARGS   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yURG_noerror            (void)
{
   char        rc          =    0;
   DEBUG_ARGS   yLOG_enter   (__FUNCTION__);
   rc = yurg_rptg__eclose ();
   rc = yurg_rptg__eopen  ("/dev/null");
   DEBUG_ARGS   yLOG_exit    (__FUNCTION__);
   return rc;
}

char
yURG_tmperr             (void)
{
   char        rc          =    0;
   DEBUG_ARGS   yLOG_enter   (__FUNCTION__);
   rc = yurg_rptg__eclose ();
   rc = yurg_rptg__eopen  ("/tmp/errors.txt");
   DEBUG_ARGS   yLOG_exit    (__FUNCTION__);
   return rc;
}

char
yURG_custom             (char *a_name)
{
   char        rc          =    0;
   DEBUG_ARGS   yLOG_enter   (__FUNCTION__);
   rc = yurg_rptg__eclose ();
   rc = yurg_rptg__eopen  (a_name);
   DEBUG_ARGS   yLOG_exit    (__FUNCTION__);
   return rc;
}

char
yURG_error              (cchar *a_format, ...)
{
   /*---(locals)-----------+-----+-----+-*/
   va_list     x_args;
   /*---(check output)-------------------*/
   if (s_error == NULL)  yURG_stderr ();
   /*---(va_args)------------------------*/
   va_start   (x_args, a_format);
   vsnprintf  (s_print, LEN_FULL - 1, a_format, x_args);
   va_end     (x_args);
   fprintf    (s_error, "%s\n", s_print);
   fflush     (s_error);
   /*---(complete)-----------------------*/
   return 0;
}



/*====================------------------------------------====================*/
/*===----                    unit testing accessor                     ----===*/
/*====================------------------------------------====================*/
static void      o___UNITTEST________________o (void) {;}

int
yURG_peek               (char *a_name, int n, char *a_recd)
{
   char        t           [LEN_RECD]  = "";
   FILE       *f           = NULL;
   int         c           =    0;
   int         x_len       =    0;
   if (a_name == NULL)            return 0;
   if (strcmp (a_name, "") == 0)  return 0;
   if (a_recd == NULL)            return 0;
   strcpy (a_recd, "");
   f = fopen (a_name, "rt");
   if (f == NULL)  return 0;
   while (1) {
      fgets (t, LEN_RECD, f);
      if (feof (f))  break;
      if (c == n)  strcpy (a_recd, t);
      ++c;
   }
   x_len = strlen (a_recd);
   if (x_len > 0 && a_recd [x_len - 1] == '\n')  a_recd [--x_len] = '\0';
   fclose (f);
   return c;
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
      snprintf  (t, LEN_HUND, "[%-.15s]"   , s_name);
      snprintf  (s, LEN_HUND, "%2d[%-.60s]", strlen (s_print), s_print);
      snprintf (unit_answer, LEN_RECD, "RPTG error       : %-17.17s  %s", t, s);
   }
   /*---(complete)-----------------------*/
   return unit_answer;
}


