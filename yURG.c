/*===[[ START ]]==============================================================*/
#include    "yURG.h"
#include    "yURG_priv.h"

tURG_DEBUG      yURG_debug;

char        s_lower     [30] = "";
char        s_upper     [30] = "";
char        s_digit     [30] = "";


tYURG_INFO  yURG_info [MAX_URGS] = {
   /* abbr  fast  full--------   desc------------------------------------  type */
   /*---(compound)-----------------------*/
   {   '-' , 'y' , "quiet"      , "turn absolutely everything off"        , '-', NULL                  },
   {   '-' , 'y' , "full"       , "turn all universals on"                , '-', NULL                  },
   {   '-' , 'y' , "FULL"       , "turn all universals and their mas on"  , '-', NULL                  },
   {   '-' , 'y' , "kitchen"    , "turn all universals and special on"    , '-', NULL                  },
   {   '-' , 'y' , "omniscient" , "turn absolutely everything on"         , '-', NULL                  },
   /*---(overall)------------------------*/
   {   't' , '-' , "tops"       , "broad structure and context"           , 'u', &yURG_debug.tops      },
   {   'r' , '-' , "summ"       , "runtime statistics/analytical output"  , 'u', &yURG_debug.summ      },
   /*---(startup/shutdown)---------------*/
   {   'a' , 'y' , "args"       , "command-line args and urgent handling" , 'u', &yURG_debug.args      },
   {   'A' , 'y' , "ARGS"       , "command-line args and urgent handling" , '#', &yURG_debug.args_mas  },
   {   'c' , '-' , "conf"       , "configuration handling"                , 'u', &yURG_debug.conf      },
   {   'C' , '-' , "CONF"       , "configuration handling"                , '#', &yURG_debug.conf_mas  },
   {   'p' , 'y' , "prog"       , "program setup and shutdown"            , 'u', &yURG_debug.prog      },
   {   'P' , 'y' , "PROG"       , "program setup and shutdown"            , '#', &yURG_debug.prog_mas  },
   /*---(file processing)----------------*/
   {   'i' , '-' , "inpt"       , "text and data file input"              , 'u', &yURG_debug.inpt      },
   {   'I' , '-' , "INPT"       , "text and data file input"              , '#', &yURG_debug.inpt_mas  },
   {   'o' , '-' , "outp"       , "text and data file output"             , 'u', &yURG_debug.outp      },
   {   'O' , '-' , "OUTP"       , "text and data file output"             , '#', &yURG_debug.outp_mas  },
   {   'q' , '-' , "sqls"       , "database and sql interaction"          , 'u', &yURG_debug.sqls      },
   {   'Q' , '-' , "SQLS"       , "database and sql interaction"          , '#', &yURG_debug.sqls_mas  },
   /*---(event handling)-----------------*/
   {   'l' , '-' , "loop"       , "main program event loop"               , 'u', &yURG_debug.loop      },
   {   'L' , '-' , "LOOP"       , "main program event loop"               , '#', &yURG_debug.loop_mas  },
   {   'u' , '-' , "user"       , "user input and handling"               , 'u', &yURG_debug.user      },
   {   'U' , '-' , "USER"       , "user input and handling"               , '#', &yURG_debug.user_mas  },
   {   'z' , '-' , "apis"       , "interprocess communication"            , 'u', &yURG_debug.apis      },
   {   'Z' , '-' , "APIS"       , "interprocess communication"            , '#', &yURG_debug.apis_mas  },
   {   'x' , '-' , "sign"       , "o/s signal handling"                   , 'u', &yURG_debug.sign      },
   {   'X' , '-' , "SIGN"       , "o/s signal handling"                   , '#', &yURG_debug.sign_mas  },
   {   'b' , '-' , "scrp"       , "scripts and batch handling"            , 'u', &yURG_debug.scrp      },
   {   'B' , '-' , "SCRP"       , "scripts and batch handling"            , '#', &yURG_debug.scrp_mas  },
   {   'h' , '-' , "hist"       , "history, undo, redo"                   , 'u', &yURG_debug.hist      },
   {   'H' , '-' , "HIST"       , "history, undo, redo"                   , '#', &yURG_debug.hist_mas  },
   /*---(deeper program)-----------------*/
   {   'g' , '-' , "graf"       , "graphics, drawing, and display"        , 'u', &yURG_debug.graf      },
   {   'G' , '-' , "GRAF"       , "graphics, drawing, and display"        , '#', &yURG_debug.graf_mas  },
   {   'd' , '-' , "data"       , "complex data structure handling"       , 'u', &yURG_debug.data      },
   {   'D' , '-' , "DATA"       , "complex data structure handling"       , '#', &yURG_debug.data_mas  },
   {   'e' , '-' , "envi"       , "environmental processing"              , 'u', &yURG_debug.envi      },
   {   'E' , '-' , "ENVI"       , "environmental processing"              , '#', &yURG_debug.envi_mas  },
   {   's' , '-' , "sort"       , "data sorting and ordering"             , 'u', &yURG_debug.sort      },
   {   'S' , '-' , "SORT"       , "data sorting and ordering"             , '#', &yURG_debug.sort_mas  },
   /*---(spreadsheet)--------------------*/
   {   '-' , '-' , "loc"        , "spreadsheet location parsing and use"  , 's', &yURG_debug.loc       },
   {   '-' , '-' , "cell"       , "spreadsheet cell creation and mtce"    , 's', &yURG_debug.cell      },
   {   '-' , '-' , "CELL"       , "spreadsheet cell creation and mtce"    , 'M', &yURG_debug.cell_mas  },
   /*---(calculations)-------------------*/
   {   '-' , '-' , "rpn"        , "calculation conversion infix to rpn"   , 's', &yURG_debug.rpn       },
   {   '-' , '-' , "RPN"        , "calculation conversion infix to rpn"   , 'M', &yURG_debug.rpn_mas   },
   {   '-' , '-' , "calc"       , "calculation building from rpn"         , 's', &yURG_debug.calc      },
   {   '-' , '-' , "CALC"       , "calculation building from rpn"         , 'M', &yURG_debug.calc_mas  },
   {   '-' , '-' , "exec"       , "calculation execution"                 , 's', &yURG_debug.exec      },
   {   '-' , '-' , "EXEC"       , "calculation execution"                 , 'M', &yURG_debug.exec_mas  },
   /*---(dependencies)-------------------*/
   {   '-' , '-' , "deps"       , "dependency creation and maintenance"   , 's', &yURG_debug.deps      },
   {   '-' , '-' , "DEPS"       , "dependency creation and maintenance"   , 'M', &yURG_debug.deps_mas  },
   /*---(visual)-------------------------*/
   {   '-' , '-' , "visu"       , "visual selection of objects"           , 's', &yURG_debug.visu      },
   {   '-' , '-' , "ssel"       , "visual selection of text strings"      , 's', &yURG_debug.ssel      },
   {   '-' , '-' , "mark"       , "location and object marks"             , 's', &yURG_debug.mark      },
   /*---(registers)----------------------*/
   {   '-' , '-' , "regs"       , "copy and paste registers"              , 's', &yURG_debug.regs      },
   /*---(libraries)----------------------*/
   {   '-' , '-' , "ystr"       , "heatherly ySTR string library"         , 's', &yURG_debug.ystr      },
   {   '-' , '-' , "YSTR"       , "heatherly ySTR string library"         , 'M', &yURG_debug.ystr_mas  },
   {   '-' , '-' , "ykine"      , "heatherly yKINE kinematics library"    , 's', &yURG_debug.ykine     },
   {   '-' , '-' , "YKINE"      , "heatherly yKINE kinematics library"    , 'M', &yURG_debug.ykine_mas },
   /*---(end-of-list)--------------------*/
   {   '\0', '-' , "END-OF-LIST", "end of list"                           , ' ', NULL                  },

};



/*====================------------------------------------====================*/
/*===----                        utility functions                     ----===*/
/*====================------------------------------------====================*/
static void      o___UTILITY_________________o (void) {;}

char        yURG_ver     [500];

char*      /* ---- : return library versioning information -------------------*/
yURG_version       (void)
{
   char    t [20] = "";
#if    __TINYC__ > 0
   strlcpy (t, "[tcc built  ]", 15);
#elif  __GNUC__  > 0
   strlcpy (t, "[gnu gcc    ]", 15);
#elif  __HEPH__  > 0
   strncpy (t, "[hephaestus ]", 15);
#else
   strlcpy (t, "[unknown    ]", 15);
#endif
   snprintf (yURG_ver, 100, "%s   %s : %s", t, YURG_VER_NUM, YURG_VER_TXT);
   return yURG_ver;
}

char         /*--> return status of debug ----------------[ ------ [ ------ ]-*/
yURG_debugmode     (void)
{
   if (yURG_debug.logger < 0)   return '-';
   return 'y';
}

char         /*--> count number of set urgents -----------[ ------ [ ------ ]-*/
yURG__count        (void)
{
   /*---(locals)-----------+-----------+-*/
   int         i           = 0;
   int         c           = 0;
   /*---(list)---------------------------*/
   for (i = 0; i < MAX_URGS; ++i) {
      /*---(stop at end)-----------------*/
      if (yURG_info [i].abbr     == '\0')     break;
      /*---(filter)----------------------*/
      if (yURG_info [i].type     == '-')      continue;
      if (  yURG_info [i].point  == NULL)     continue;
      if (*(yURG_info [i].point) != 'y')      continue;
      /*---(append)----------------------*/
      ++c;
   }
   /*---(complete)-----------------------*/
   return c;
}

char         /*--> put lower letters in a string ---------[ ------ [ ------ ]-*/
yURG__strings      (void)
{
   /*---(locals)-----------+-----------+-*/
   int         i           = 0;
   char        c           = ' ';
   /*---(initialize)---------------------*/
   strlcpy  (s_lower, "--------------------------", LEN_STR);
   strlcpy  (s_upper, "--------------------------", LEN_STR);
   strlcpy  (s_digit, "----------"                , LEN_STR);
   /*---(list)---------------------------*/
   for (i = 0; i < MAX_URGS; ++i) {
      /*---(stop at end)-----------------*/
      if (yURG_info [i].abbr     == '\0')     break;
      /*---(filter)----------------------*/
      if (yURG_info [i].abbr     == '-')      continue;
      if (yURG_info [i].type     == '-')      continue;
      if (  yURG_info [i].point  == NULL)     continue;
      if (*(yURG_info [i].point) != 'y')      continue;
      /*---(append)----------------------*/
      c = yURG_info [i].abbr;
      if (c >= 'a' && c <= 'z')  s_lower [c - 'a'] = c;
      if (c >= 'A' && c <= 'Z')  s_upper [c - 'A'] = c;
      if (c >= '0' && c <= '9')  s_digit [c - '0'] = c;
   }
   /*---(complete)-----------------------*/
   return 0;
}



/*====================------------------------------------====================*/
/*===----                          normal                              ----===*/
/*====================------------------------------------====================*/
static void      o___NORMAL__________________o (void) {;}

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
   DEBUG_ARGS   yLOG_note   ("summarization of urgent processing");
   for (i = 0; i < MAX_URGS; ++i) {
      /*---(stop at end)-----------------*/
      if (yURG_info [i].abbr  == '\0')     break;
      /*---(filter)----------------------*/
      if (yURG_info [i].type  == '-')      continue;
      /*---(show)------------------------*/
      DEBUG_ARGS   yLOG_char   (yURG_info [i].full, *(yURG_info [i].point));
   }
   /*---(complete)-----------------------*/
   return 0;
}

char         /*--> set a single urgent by abbr -----------[ ------ [ ------ ]-*/
yURG_abbr          (cchar a_abbr)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         = -10;
   int         i           = 0;
   int         x_count     = 0;
   char       *x_valid     = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
   /*---(header)-------------------------*/
   DEBUG_ARGS_M   yLOG_enter   (__FUNCTION__);
   DEBUG_ARGS_M   yLOG_value   ("a_abbr"    , a_abbr);
   /*---(defense)------------------------*/
   --rce;  if (a_abbr <=  32) {
      DEBUG_ARGS_M   yLOG_note    ("a_abbr is control character");
      DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   --rce;  if (strchr (x_valid, a_abbr) == NULL) {
      DEBUG_ARGS_M   yLOG_note    ("a_abbr not alphabetic");
      DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   /*---(find)---------------------------*/
   --rce;
   DEBUG_ARGS_M  yLOG_note    ("start search");
   for (i = 0; i < MAX_URGS; ++i) {
      DEBUG_ARGS_M  yLOG_info    ("checking"  , yURG_info [i].full);
      /*---(stop at end)-----------------*/
      if (yURG_info [i].abbr  == '\0') {
         DEBUG_ARGS_M   yLOG_note    ("hit end of table");
         break;
      }
      /*---(filter)----------------------*/
      if (yURG_info [i].type  == '-')                 continue;
      if (yURG_info [i].abbr  != a_abbr)              continue;
      DEBUG_ARGS_M   yLOG_note    ("MATCH");
      if (yURG_info [i].point == NULL) {
         DEBUG_ARGS_M   yLOG_note    ("bad pointer on record");
         DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
         return rce;
      }
      /*---(set)-------------------------*/
      DEBUG_ARGS_M   yLOG_note    ("set on and increment counter");
      ++x_count;
      *(yURG_info [i].point) = 'y';
      /*---(check mas)-------------------*/
      if (yURG_info [i].type  == '#' && a_abbr >= 'A' && a_abbr <= 'Z') {
         DEBUG_ARGS_M   yLOG_note    ("attemp to set non-mas version");
         yURG_abbr (tolower (a_abbr));
      }
      break;
   }
   /*---(check)--------------------------*/
   DEBUG_ARGS_M   yLOG_value   ("count"     , x_count);
   --rce;  if (x_count < 1  ) {
      DEBUG_ARGS_M   yLOG_note    ("did not find any urgents matching name");
      DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   --rce;  if (x_count > 1  ) {
      DEBUG_ARGS_M   yLOG_note    ("found more than one urgent matching name");
      DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
   return 0;
}

char         /*--> set a single urgent by name -----------[ ------ [ ------ ]-*/
yURG_name          (cchar *a_name)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         = -10;
   int         i           = 0;
   int         x_len       = 0;
   int         x_count     = 0;
   char       *x_valid     = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
   char        x_lower     [LEN_LABEL] = "";
   /*---(header)-------------------------*/
   DEBUG_ARGS_M   yLOG_enter   (__FUNCTION__);
   DEBUG_ARGS_M   yLOG_info    ("a_name"    , a_name);
   /*---(defense)------------------------*/
   x_len = strllen (a_name, LEN_LABEL);
   DEBUG_ARGS_M   yLOG_value   ("x_len"     , x_len);
   --rce;  if (x_len <  3) {
      DEBUG_ARGS_M   yLOG_note    ("a_name too short (< 3 chars)");
      DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   --rce;  if (x_len > 15) {
      DEBUG_ARGS_M   yLOG_note    ("a_name too long (> 15 chars)");
      DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   strlcpy (x_lower, a_name, LEN_LABEL);
   --rce;  for (i = 0; i < x_len; ++i) {
      DEBUG_ARGS_M   yLOG_char    ("check"     , a_name [i]);
      if (strchr (x_valid, a_name [i]) == NULL)  {
         DEBUG_ARGS_M   yLOG_note    ("a_abbr not alphabetic");
         DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
         return rce;
      }
      x_lower [i] = tolower (a_name [i]);
   }
   DEBUG_ARGS_M   yLOG_info    ("x_lower"   , x_lower);
   /*---(find)---------------------------*/
   --rce;
   for (i = 0; i < MAX_URGS; ++i) {
      DEBUG_ARGS_M  yLOG_info    ("checking"  , yURG_info [i].full);
      /*---(stop at end)-----------------*/
      if (yURG_info [i].abbr  == '\0') {
         DEBUG_ARGS_M   yLOG_note    ("hit end of table");
         break;
      }
      /*---(filter)----------------------*/
      if (yURG_info [i].full[0] != a_name [0])        continue;
      if (strcmp (yURG_info [i].full, a_name) != 0)   continue;
      DEBUG_ARGS_M   yLOG_note    ("MATCH");
      /*---(compound)--------------------*/
      if (yURG_info [i].type == '-') {
         DEBUG_ARGS_M   yLOG_note    ("compound urgent");
         if      (strcmp (a_name, "quiet"     ) == 0)   yURG_mass  ('-', 'E');
         else if (strcmp (a_name, "full"      ) == 0)   yURG_mass  ('y', '-');
         else if (strcmp (a_name, "FULL"      ) == 0)   yURG_mass  ('y', 'M');
         else if (strcmp (a_name, "kitchen"   ) == 0)   yURG_mass  ('y', 'y');
         else if (strcmp (a_name, "omniscient") == 0)   yURG_mass  ('y', 'E');
         ++x_count;
         break;
      }
      /*---(check)-----------------------*/
      if (yURG_info [i].point == NULL) {
         DEBUG_ARGS_M   yLOG_note    ("bad pointer on record");
         DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
         return rce;
      }
      /*---(set)-------------------------*/
      ++x_count;
      *(yURG_info [i].point) = 'y';
      /*---(check mas)-------------------*/
      if ((yURG_info [i].type  == '#' || yURG_info [i].type  == 'M') && strcmp (x_lower, a_name) != 0) {
         yURG_name (x_lower);
      }
      break;
   }
   /*---(check)--------------------------*/
   DEBUG_ARGS_M   yLOG_value   ("count"     , x_count);
   --rce;  if (x_count < 1  ) {
      DEBUG_ARGS_M   yLOG_note    ("did not find any urgents matching name");
      DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   --rce;  if (x_count > 1  ) {
      DEBUG_ARGS_M   yLOG_note    ("found more than one urgent matching name");
      DEBUG_ARGS_M   yLOG_exit    (__FUNCTION__);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_ARGS_M yLOG_exit    (__FUNCTION__);
   return 0;
}

char       /*----: process the urgents/debugging -----------------------------*/
yURG_mass          (cchar a_set, cchar a_extra)
{
   int         i           = 0;
   for (i = 0; i < MAX_URGS; ++i) {
      /*---(stop at end)-----------------*/
      if (yURG_info [i].abbr  == '\0')     break;
      /*---(filter)----------------------*/
      if (yURG_info [i].point == NULL)     continue;
      if (yURG_info [i].type  == '-')      continue;
      /*---(everything)------------------*/
      if (a_extra == 'E' ) {
         *(yURG_info [i].point) = a_set;
         continue;
      }
      /*---(universal)-------------------*/
      if (yURG_info [i].type  == 'u') {
         *(yURG_info [i].point) = a_set;
         continue;
      }
      /*---(mas)-------------------------*/
      if (yURG_info [i].type  == '#' && a_extra == 'M' ) {
         *(yURG_info [i].point) = a_set;
         continue;
      }
      /*---(specialty)-------------------*/
      if (yURG_info [i].type  == 's' && a_extra == 'y' ) {
         *(yURG_info [i].point) = a_set;
         continue;
      }
      /*---(done)------------------------*/
   }
   return 0;
}



/*====================------------------------------------====================*/
/*===----                           drivers                            ----===*/
/*====================------------------------------------====================*/
static void      o___DRIVERS_________________o (void) {;}

char         /*--: evaluate logger needs early -----------[ leaf   [ ------ ]-*/
yURG_logger        (int a_argc, char *a_argv[])
{
   /*---(locals)-----------+-----------+-*/
   int         i           = 0;
   char       *a           = NULL;
   int         x_len       = 0;
   char        x_progname  [LEN_STR] = "";
   char        x_log       = '-';
   char        x_type      = '-';
   char        x_args      = '-';
   char        x_prog      = '-';
   /*---(default urgents)----------------*/
   yURG_mass    ('-', 'E');   /* turn everything off */
   yURG_debug.logger   = -1;
   strlcpy (x_progname, a_argv [0], LEN_STR);
   x_len  = strllen (x_progname, LEN_LABEL);
   /*> printf ("%3d:%s\n", x_len, x_progname);                                        <* 
    *> printf ("   :%s\n",        x_progname + x_len - 6);                            <* 
    *> printf ("   :%s\n",        x_progname + x_len - 5);                            <*/
   /*---(test for normal version)--------*/
   if (x_len <= 6)                                     return 0;
   if (strcmp (a_argv[0] + x_len - 6, "_debug") == 0)  x_type = 'd';
   if (strcmp (a_argv[0] + x_len - 5, "_unit" ) == 0)  x_type = 'u';
   /*> printf ("type = %c\n", x_type);                                                <*/
   if (x_type == '-')                                  return 0;
   /*---(fix program name)---------------*/
   if (x_type == 'd')  x_progname [x_len - 6] = '\0';
   x_len  = strllen (x_progname, LEN_LABEL);
   /*> printf ("%3d:%s\n", x_len, x_progname);                                        <*/
   /*---(process)------------------------*/
   for (i = 1; i < a_argc; ++i) {
      a = a_argv[i];
      /*> printf ("evaluating %2d:%s\n", i, a);                                       <*/
      if (a[0] != '@')  continue;
      /*> printf ("  urgent\n");                                                      <*/
      if (x_log == '-') x_log = 'y';
      /*---(singles)---------------------*/
      if      (strcmp (a, "@q"           ) == 0)   x_log  = 'q';
      else if (strcmp (a, "@@quiet"      ) == 0)   x_log  = 'q';
      else if (strcmp (a, "@a"           ) == 0)   x_args = 'a';
      else if (strcmp (a, "@@args"       ) == 0)   x_args = 'a';
      else if (strcmp (a, "@A"           ) == 0)   x_args = 'A';
      else if (strcmp (a, "@@ARGS"       ) == 0)   x_args = 'A';
      else if (strcmp (a, "@p"           ) == 0)   x_prog = 'p';
      else if (strcmp (a, "@@prog"       ) == 0)   x_prog = 'p';
      else if (strcmp (a, "@P"           ) == 0)   x_prog = 'P';
      else if (strcmp (a, "@@PROG"       ) == 0)   x_prog = 'P';
      /*---(compounds)-------------------*/
      else if (strcmp (a, "@@full"       ) == 0) { x_args = 'a'; x_prog = 'p'; }
      else if (strcmp (a, "@@FULL"       ) == 0) { x_args = 'A'; x_prog = 'P'; }
      else if (strcmp (a, "@@kitchen"    ) == 0) { x_args = 'a'; x_prog = 'p'; }
      else if (strcmp (a, "@@omniscient" ) == 0) { x_args = 'A'; x_prog = 'P'; }
      /*> printf ("done, ready for next\n");                                          <*/
   }
   /*> printf ("log  = %c\n", x_log);                                                 <*/
   /*---(startup logging)----------------*/
   switch (x_log) {
   case 'y' :
      yURG_debug.logger = yLOG_begin (x_progname, yLOG_SYSTEM    , yLOG_NOISE);
      break;
   case 'q' :
   case '-' :
   default  :
      yURG_debug.logger = yLOG_begin (x_progname, yLOG_SYSTEM    , yLOG_QUIET);
      break;
   }
   /*> printf ("debugger = %d\n", yURG_debug.logger);                                 <*/
   /*---(fast update)--------------------*/
   yURG_debug.tops = 'y';
   if (x_args == 'a')    yURG_debug.args = 'y';
   if (x_args == 'A')  { yURG_debug.args = 'y'; yURG_debug.args_mas = 'y'; }
   if (x_prog == 'p')    yURG_debug.prog = 'y';
   if (x_prog == 'P')  { yURG_debug.prog = 'y'; yURG_debug.prog_mas = 'y'; }
   /*---(complete)-----------------------*/
   return 0;
}

char       /*----: process the urgents/debugging -----------------------------*/
yURG_urgs          (int a_argc, char *a_argv[])
{
   /*---(locals)-----------+-----------+-*/
   int         i           = 0;
   char        rc          = 0;
   char       *a           = NULL;
   int         x_len       = 0;
   int         x_total     = 0;
   int         x_urgs      = 0;
   int         x_bad       = 0;
   int         x_good      = 0;
   /*---(header)-------------------------*/
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   /*---(process)------------------------*/
   for (i = 1; i < a_argc; ++i) {
      a = a_argv[i];
      DEBUG_ARGS   yLOG_info    ("option"    , a);
      ++x_total;
      if (a[0] != '@')  continue;
      DEBUG_ARGS   yLOG_note    ("idenfified urgent");
      x_len  = strlen (a);
      ++x_urgs;
      rc = 0;
      if      (x_len == 2)  rc = yURG_abbr  (a[1]);
      else if (x_len >= 5)  rc = yURG_name  (a + 2);
      else {
         DEBUG_ARGS   yLOG_note    ("could not process");
         ++x_bad;
      }
      DEBUG_ARGS   yLOG_value   ("rc"        , rc);
      if (rc < 0) ++x_bad;
      else        ++x_good;
   }
   DEBUG_ARGS   yLOG_value   ("x_good"    , x_good);
   DEBUG_ARGS   yLOG_value   ("x_bad"     , x_bad);
   yURG_summ   ();
   /*---(complete)-----------------------*/
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   return x_good;
}



/*====================------------------------------------====================*/
/*===----                    unit testing accessor                     ----===*/
/*====================------------------------------------====================*/
static void      o___UNITTEST________________o (void) {;}

#define       LEN_TEXT  2000
char          unit_answer [ LEN_TEXT ];

char*            /* [------] unit test accessor ------------------------------*/
yURG__unit         (char *a_question, int a_num)
{
   int         c           = 0;
   /*---(initialize)---------------------*/
   strlcpy (unit_answer, "yURG_unit, unknown request", 100);
   /*---(string testing)-----------------*/
   if      (strncmp(a_question, "lower"     , 20)  == 0) {
      yURG__strings ();
      snprintf (unit_answer, LEN_TEXT, "yURG lower       : [%s]", s_lower);
   } else if (strncmp(a_question, "upper"     , 20)  == 0) {
      yURG__strings ();
      snprintf (unit_answer, LEN_TEXT, "yURG upper       : [%s]", s_upper);
   } else if (strncmp(a_question, "digit"     , 20)  == 0) {
      yURG__strings ();
      snprintf (unit_answer, LEN_TEXT, "yURG digit       : [%s]", s_digit);
   } else if (strncmp(a_question, "count"     , 20)  == 0) {
      c = yURG__count ();
      snprintf (unit_answer, LEN_TEXT, "yURG count       : %d"  , c);
   }
   /*---(complete)-----------------------*/
   return unit_answer;
}



char       /*----: set up programgents/debugging -----------------------------*/
yURG__testquiet     (void)
{
   char       *x_args [2]  = { "yURG_debug","@@quiet" };
   yURG_logger (2, x_args);
   return 0;
}

char       /*----: set up programgents/debugging -----------------------------*/
yURG__testloud      (void)
{
   char       *x_args [2]  = { "yURG_debug","@@kitchen" };
   yURG_logger (2, x_args);
   return 0;
}

char       /*----: set up program urgents/debugging --------------------------*/
yURG__testend       (void)
{
   DEBUG_TOPS   yLOG_end     ();
   return 0;
}

/*===[[ END ]]================================================================*/
