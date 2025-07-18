/*===[[ START ]]==============================================================*/
#include    "yURG.h"
#include    "yURG_priv.h"


char
yurg__setlog            (cchar *a_name, cchar a_log)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   if (myURG.loud != 'y')                                  return 0;
   switch (a_log) {
   case YLOG_NULL       :
      myURG.logger = yLOGS_begin (a_name, a_log, YLOG_QUIET);
      break;
   case YLOG_SYS        : case YLOG_HIST       :
   case YLOG_STDOUT     : case YLOG_ROOT       :
   case YLOG_TMP        :
      myURG.logger = yLOGS_begin (a_name, a_log, YLOG_NOISE);
      break;
   case YLOG_USB        :
      rc = mount ("/dev/sdb1", "/mnt/usb1", "vfat", MS_NOSUID | MS_NODEV | MS_NOEXEC | MS_NOATIME, NULL);
      myURG.logger = yLOGS_begin (a_name, YLOG_USB   , YLOG_NOISE);
      break;
   case YLOG_QUIET : default  :
      myURG.logger = yLOGS_begin (a_name, YLOG_SYS   , YLOG_QUIET);
      break;
   }
   if (myURG.logger < 0) {
      return myURG.logger;
   }
   return 0;
}

#define  TWOARG  if (++i >= a_argc)  printf ("%s option requires an argument (%d)\n", a, --rc); else 

char         /*--: evaluate logger needs early -----------[ leaf   [ ------ ]-*/
yURG_logger        (int a_argc, char *a_argv[])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   int         i           = 0;
   char       *a           = NULL;
   int         x_len       = 0;
   char       *p           = NULL;
   int         t           [LEN_FULL];
   char        x_progname  [LEN_FULL] = "";
   char        x_basename  [LEN_FULL] = "";
   char        x_log       = YLOG_SYS;
   char        x_args      = '-';
   char        x_prog      = '-';
   char        x_verb      = '-';
   char        x_dest      = '-';
   /*---(messages)-----------------------*/
   x_dest = yURG_msg_where ();
   myURG_priv.mlive = 'y';
   strcpy (myURG_priv.mname, "stdout");
   myURG_priv.mfile = stdout;
   /*---(errors)-------------------------*/
   myURG_priv.elive = 'y';
   strcpy (myURG_priv.ename, "stderr");
   myURG_priv.efile = stderr;
   /*---(default urgents)----------------*/
   myURG.cstage   = '�';
   yLOG_curr (myURG.cstage, '�');
   myURG.logger   =  -1;
   myURG.loud     = '-';
   myURG.use      = '-';
   yurg_mass    ('-', 'E');   /* turn everything off */
   /*---(get basename)-------------------*/
   p = strrchr (a_argv [0], '/');
   if (p == NULL)  strncpy (x_progname, a_argv [0], LEN_FULL);
   else            strncpy (x_progname, p + 1     , LEN_FULL);
   strncpy (x_basename, x_progname, LEN_FULL);
   x_len  = strlen (x_basename);
   /*---(test for normal version)--------*/
   /*> printf ("name %s, %d[%s]\n", a_argv [0], x_len, x_basename);                   <*/
   if (x_len >= 6) {
      if (strstr (x_basename, "_debug") != 0)  myURG.use  = 'd';
      if (strstr (x_basename, "_unit" ) != 0)  myURG.use  = 'u';
      if (myURG.use != '-')                    myURG.loud = 'y';
   }
   /*> printf ("myURG.loud = %c\n", myURG.loud);                                      <*/
   /*---(fix program name)---------------*/
   switch (myURG.use) {
   case 'd' : /* debug version */
      x_basename [x_len - 6] = '\0';
      strncpy (x_progname, x_basename, LEN_FULL);
      break;
   case 'u' : /* unit testing */
      x_basename [x_len - 5] = '\0';
      break;
   default  : /* no logging */
      return 0;
      break;
   }
   x_len  = strlen (x_progname);
   /*> printf ("x_log = %c\n", x_log);                                                <*/
   /*---(process)------------------------*/
   for (i = 1; i < a_argc; ++i) {
      /*---(prepare)---------------------*/
      a = a_argv[i];
      /*---(filter)----------------------*/
      /*> printf ("argv [%d] = [%s]\n", i, a_argv [i]);                               <*/
      if (a[0] != '@')   continue;
      /*---(non-logging)-----------------*/
      if      (strcmp (a, "@v"           ) == 0) { x_verb = 'v'; continue; }
      else if (strcmp (a, "@@verbose"    ) == 0) { x_verb = 'v'; continue; }
      else if (strcmp (a, "@V"           ) == 0) { x_verb = 'V'; continue; }
      else if (strcmp (a, "@@VERBOSE"    ) == 0) { x_verb = 'V'; continue; }
      /*---(locations)-------------------*/
      if      (strcmp (a, "@@null"       ) == 0) x_log  = YLOG_NULL;
      else if (strcmp (a, "@@ylog"       ) == 0) x_log  = YLOG_SYS;
      else if (strcmp (a, "@@ylogh"      ) == 0) x_log  = YLOG_HIST;
      else if (strcmp (a, "@@here"       ) == 0) x_log  = YLOG_STDOUT;
      else if (strcmp (a, "@@root"       ) == 0) x_log  = YLOG_ROOT;
      else if (strcmp (a, "@@usb"        ) == 0) x_log  = YLOG_USB;
      else if (strcmp (a, "@@tmp"        ) == 0) x_log  = YLOG_TMP;
      /*---(singles)---------------------*/
      else if (strcmp (a, "@a"           ) == 0)   x_args = 'a';
      else if (strcmp (a, "@@args"       ) == 0)   x_args = 'a';
      else if (strcmp (a, "@A"           ) == 0)   x_args = 'A';
      else if (strcmp (a, "@@ARGS"       ) == 0)   x_args = 'A';
      else if (strcmp (a, "@p"           ) == 0)   x_prog = 'p';
      else if (strcmp (a, "@@prog"       ) == 0)   x_prog = 'p';
      else if (strcmp (a, "@P"           ) == 0)   x_prog = 'P';
      else if (strcmp (a, "@@PROG"       ) == 0)   x_prog = 'P';
      /*---(compounds)-------------------*/
      else if (strcmp (a, "@@full"       ) == 0) { if (x_args != 'A')  x_args = 'a'; if (x_prog != 'P') x_prog = 'p'; }
      else if (strcmp (a, "@@mas"        ) == 0) { x_args = 'A'; x_prog = 'P'; }
      else if (strcmp (a, "@@kitchen"    ) == 0) { if (x_args != 'A')  x_args = 'a'; if (x_prog != 'P') x_prog = 'p'; }
      else if (strcmp (a, "@@omni"       ) == 0) { x_args = 'A'; x_prog = 'P'; }
      else if (strcmp (a, "@@urgents"    ) == 0) { yurg_urgents   (x_basename);    exit (0); }
      else if (strcmp (a, "@@universal"  ) == 0) { yurg_category  (x_basename, 'u'); exit (0); }
      else if (strcmp (a, "@@program"    ) == 0) { yurg_category  (x_basename, 'p'); exit (0); }
      else if (strcmp (a, "@@library"    ) == 0) { yurg_category  (x_basename, 'l'); exit (0); }
      /*---(stderr)----------------------*/
      else if (strcmp (a, "@@stderr"     ) == 0)  yURG_err_std  ();
      else if (strcmp (a, "@@noerror"    ) == 0)  yURG_err_none ();
      else if (strcmp (a, "@@tmperr"     ) == 0)  yURG_err_tmp  ();
      else if (strcmp (a, "@@errors"     ) == 0)  TWOARG yURG_err_custom (a_argv [i]);
      /*---(stdout)----------------------*/
      else if (strcmp (a, "@@stdout"     ) == 0)  yURG_msg_std  ();
      else if (strcmp (a, "@@noout"      ) == 0)  yURG_msg_none ();
      else if (strcmp (a, "@@tmpout"     ) == 0)  yURG_msg_tmp  ();
      else if (strcmp (a, "@@console"    ) == 0)  TWOARG yURG_msg_custom (a_argv [i]);
      /*---(both)------------------------*/
      else if (strcmp (a, "@@alltmp"     ) == 0)  {
         if (x_dest == 't') strcpy (myURG_priv.mname, YURG_MSG);
         yURG_msg_atmp  ();
         yURG_msg_live  ();
         yURG_msg_clear ();
         yURG_err_tmp   ();
         yURG_err_live  ();
         yURG_err_clear ();
      }
      /*> else if (strcmp (a, "@@help"       ) == 0) { yURG_help (x_basename); exit (0); }   <*/
      /*---(done)------------------------*/
   }
   /*---(hande verbose flag)-------------*/
   if      (x_verb == 'v')    myURG.view = YURG_ON;
   else if (x_verb == 'V')    myURG.view = YURG_MAS;
   /*---(jump out if not needed)---------*/
   if (myURG.loud != 'y')   return 0;
   /*---(startup logging)----------------*/
   /*> printf ("x_log = %c\n", x_log);                                                <*/
   rc = yurg__setlog (x_progname, x_log);
   if (myURG.logger < 0) {
      DEBUG_ARGS    yLOG_exitr   (__FUNCTION__, myURG.logger);
      return myURG.logger;
   }
   /*---(fast update)--------------------*/
   myURG.prog = YURG_ON;
   if (x_args == 'a')    myURG.args = YURG_ON;
   if (x_args == 'A')    myURG.args = YURG_MAS;
   if (x_prog == 'p')    myURG.prog = YURG_ON;
   if (x_prog == 'P')    myURG.prog = YURG_MAS;;
   DEBUG_ARGS    yLOG_enter   (__FUNCTION__);
   DEBUG_ARGS    yLOG_note    ("@@tops turned on in yURG_logger()");
   DEBUG_ARGS    yLOG_note    ("@@args turned on in yURG_logger()");
   DEBUG_ARGS_M  yLOG_note    ("@@ARGS turned on in yURG_logger()");
   DEBUG_ARGS    yLOG_note    ("@@prog turned on in yURG_logger()");
   DEBUG_ARGS_M  yLOG_note    ("@@PROG turned on in yURG_logger()");
   DEBUG_ARGS    yLOG_exit    (__FUNCTION__);
   /*---(complete)-----------------------*/
   return 0;
}

char
yurg_log__unit_find     (cchar *a_name, cchar a_log)
{

}

char
yURG_check              (uchar a_urg, uchar a_mas, char *a_flag, char *a_alt)
{
   /*> printf ("yURGS_check %c %c\n", a_urg, a_mas);                                  <*/
   yLOG_curr (myURG.cstage, a_urg);
   if (a_mas == '-')  a_mas = 'y';
   if (a_mas == 'y' && *a_flag != '-')  return 1;
   if (a_mas == 'Y' && *a_flag == 'Y')  return 1;
   if (a_alt != NULL) {
      if (a_mas == 'y' && *a_alt  != '-')  return 1;
      if (a_mas == 'Y' && *a_alt  == 'Y')  return 1;
   }
   return 0;
}


