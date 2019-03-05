/*===[[ START ]]==============================================================*/
#include    "yURG.h"
#include    "yURG_priv.h"


char
yurg__setlog            (cchar *a_name, cchar a_log)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   if (yURG_debug.loud != 'y')                                  return 0;
   switch (a_log) {
   case YLOG_SYS     :
      yURG_debug.logger = yLOGS_begin (a_name, YLOG_SYS    , YLOG_NOISE);
      break;
   case YLOG_HIST   :
      yURG_debug.logger = yLOGS_begin (a_name, YLOG_HIST, YLOG_NOISE);
      break;
   case YLOG_STDOUT     :
      yURG_debug.logger = yLOGS_begin (a_name, YLOG_STDOUT    , YLOG_NOISE);
      break;
   case YLOG_ROOT       :
      yURG_debug.logger = yLOGS_begin (a_name, YLOG_ROOT      , YLOG_NOISE);
      break;
   case YLOG_USB        :
      rc = mount ("/dev/sdb1", "/mnt/usb1", "vfat", MS_NOSUID | MS_NODEV | MS_NOEXEC | MS_NOATIME, NULL);
      yURG_debug.logger = yLOGS_begin (a_name, YLOG_USB       , YLOG_NOISE);
      break;
   case YLOG_QUIET : default  :
      yURG_debug.logger = yLOGS_begin (a_name, YLOG_SYS    , YLOG_QUIET);
      break;
   }
   if (yURG_debug.logger < 0) {
      return yURG_debug.logger;
   }
   return 0;
}

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
   char        x_log       = '-';
   char        x_type      = '-';
   char        x_args      = '-';
   char        x_prog      = '-';
   char        x_verb      = '-';
   /*---(default urgents)----------------*/
   yURG_debug.logger   =  -1;
   yURG_debug.loud     = '-';
   yURG_mass    ('-', 'E');   /* turn everything off */
   p = strrchr (a_argv [0], '/');
   if (p == NULL)  strlcpy (x_progname, a_argv [0], LEN_FULL);
   else            strlcpy (x_progname, p + 1     , LEN_FULL);
   strlcpy (x_basename, x_progname, LEN_FULL);
   x_len  = strllen (x_basename, LEN_LABEL);
   /*---(test for normal version)--------*/
   /*> printf ("name %s, %d[%s]\n", a_argv [0], x_len, x_basename);                   <*/
   if (x_len >= 6) {
      if (strstr (x_basename, "_debug") != 0)  x_type = 'd';
      if (strstr (x_basename, "_unit" ) != 0)  x_type = 'u';
      if (x_type != '-')   yURG_debug.loud   = 'y';
   }
   /*> printf ("yURG_debug.loud = %c\n", yURG_debug.loud);                            <*/
   /*---(fix program name)---------------*/
   if (x_type == 'd') {
      x_basename [x_len - 6] = '\0';
      strlcpy (x_progname, x_basename, LEN_FULL);
   }
   if (x_type == 'u') {
      x_basename [x_len - 5] = '\0';
   }
   x_len  = strllen (x_progname, LEN_LABEL);
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
      /*---(logging)---------------------*/
      if (x_log == '-') x_log = YLOG_SYS;
      /*> printf ("argv [%d] = [%s]\n", i, a_argv [i]);                               <*/
      /*---(locations)-------------------*/
      if      (strcmp (a, "@q"           ) == 0) x_log  = YLOG_QUIET;
      else if (strcmp (a, "@@quiet"      ) == 0) x_log  = YLOG_QUIET;
      else if (strcmp (a, "@@ylog"       ) == 0) x_log  = YLOG_SYS;
      else if (strcmp (a, "@@ylogh"      ) == 0) x_log  = YLOG_HIST;
      else if (strcmp (a, "@@stdout"     ) == 0) x_log  = YLOG_STDOUT;
      else if (strcmp (a, "@@root"       ) == 0) x_log  = YLOG_ROOT;
      else if (strcmp (a, "@@usb"        ) == 0) x_log  = YLOG_USB;
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
      /*> else if (strcmp (a, "@@help"       ) == 0) { yURG_help (x_basename); exit (0); }   <*/
   }
   /*---(hande verbose flag)-------------*/
   if      (x_verb == 'v')    yURG_debug.view = YURG_ON;
   else if (x_verb == 'V')    yURG_debug.view = YURG_MAS;
   /*---(startup logging)----------------*/
   /*> printf ("x_args = %c\n", x_args);                                              <*/
   /*> printf ("x_log  = %c\n", x_log);                                               <*/
   if (yURG_debug.loud != 'y')                                  return 0;
   switch (x_log) {
   case YLOG_SYS     :
      yURG_debug.logger = yLOGS_begin (x_progname, YLOG_SYS    , YLOG_NOISE);
      break;
   case YLOG_HIST :
      yURG_debug.logger = yLOGS_begin (x_progname, YLOG_HIST, YLOG_NOISE);
      break;
   case YLOG_STDOUT     :
      yURG_debug.logger = yLOGS_begin (x_progname, YLOG_STDOUT    , YLOG_NOISE);
      break;
   case YLOG_ROOT       :
      yURG_debug.logger = yLOGS_begin (x_progname, YLOG_ROOT      , YLOG_NOISE);
      break;
   case YLOG_USB        :
      rc = mount ("/dev/sdb1", "/mnt/usb1", "vfat", MS_NOSUID | MS_NODEV | MS_NOEXEC | MS_NOATIME, NULL);
      yURG_debug.logger = yLOGS_begin (x_progname, YLOG_USB       , YLOG_NOISE);
      break;
   case YLOG_QUIET : default  :
      yURG_debug.logger = yLOGS_begin (x_progname, YLOG_SYS    , YLOG_QUIET);
      break;
   }
   if (yURG_debug.logger < 0) {
      return yURG_debug.logger;
   }
   /*---(fast update)--------------------*/
   yURG_debug.tops = YURG_ON;
   if (x_args == 'a')    yURG_debug.args = YURG_ON;
   if (x_args == 'A')    yURG_debug.args = YURG_MAS;
   if (x_prog == 'p')    yURG_debug.prog = YURG_ON;
   if (x_prog == 'P')    yURG_debug.prog = YURG_MAS;;
   DEBUG_TOPS    yLOG_enter   (__FUNCTION__);
   DEBUG_TOPS    yLOG_note    ("@@tops turned on in yURG_logger()");
   DEBUG_ARGS    yLOG_note    ("@@args turned on in yURG_logger()");
   DEBUG_ARGS_M  yLOG_note    ("@@ARGS turned on in yURG_logger()");
   DEBUG_PROG    yLOG_note    ("@@prog turned on in yURG_logger()");
   DEBUG_PROG_M  yLOG_note    ("@@PROG turned on in yURG_logger()");
   DEBUG_TOPS    yLOG_exit    (__FUNCTION__);
   /*---(complete)-----------------------*/
   return 0;
}

char
yurg_log__unit_find     (cchar *a_name, cchar a_log)
{

}