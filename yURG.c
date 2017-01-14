/*===[[ START ]]==============================================================*/
#include    "yURG.h"
#include    "yURG_priv.h"

char        s_lower     [30] = "";
char        s_upper     [30] = "";
char        s_digit     [30] = "";


tYURG_INFO  yURG_info [MAX_URGS] = {
   /* abbr   full--------   desc------------------------------------  type */
   /*---(compound)-----------------------*/
   {   '-' , "quiet"      , "turn all universals off"               , '-', NULL                  },
   {   '-' , "full"       , "turn all universals on"                , '-', NULL                  },
   {   '-' , "kitchen"    , "turn all universals and special on"    , '-', NULL                  },
   {   '-' , "omniscient" , "turn absolutely everything on"         , '-', NULL                  },
   /*---(overall)------------------------*/
   {   't' , "tops"       , "broad structure and context"           , 'u', &yURG_debug.tops      },
   {   'r' , "summ"       , "runtime statistics/analytical output"  , 'u', &yURG_debug.summ      },
   /*---(startup/shutdown)---------------*/
   {   'a' , "args"       , "command-line args and urgent handling" , 'u', &yURG_debug.args      },
   {   'A' , "ARGS"       , "command-line args and urgent handling" , '#', &yURG_debug.args_mas  },
   {   'c' , "conf"       , "configuration handling"                , 'u', &yURG_debug.conf      },
   {   'C' , "CONF"       , "configuration handling"                , '#', &yURG_debug.conf_mas  },
   {   'p' , "prog"       , "program setup and shutdown"            , 'u', &yURG_debug.prog      },
   {   'P' , "PROG"       , "program setup and shutdown"            , '#', &yURG_debug.prog_mas  },
   /*---(file processing)----------------*/
   {   'i' , "inpt"       , "text and data file input"              , 'u', &yURG_debug.inpt      },
   {   'I' , "INPT"       , "text and data file input"              , '#', &yURG_debug.inpt_mas  },
   {   'o' , "outp"       , "text and data file output"             , 'u', &yURG_debug.outp      },
   {   'O' , "OUTP"       , "text and data file output"             , '#', &yURG_debug.outp_mas  },
   {   'q' , "sqls"       , "database and sql interaction"          , 'u', &yURG_debug.sqls      },
   {   'Q' , "SQLS"       , "database and sql interaction"          , '#', &yURG_debug.sqls_mas  },
   /*---(event handling)-----------------*/
   {   'l' , "loop"       , "main program event loop"               , 'u', &yURG_debug.loop      },
   {   'L' , "LOOP"       , "main program event loop"               , '#', &yURG_debug.loop_mas  },
   {   'u' , "user"       , "user input and handling"               , 'u', &yURG_debug.user      },
   {   'U' , "USER"       , "user input and handling"               , '#', &yURG_debug.user_mas  },
   {   'z' , "apis"       , "interprocess communication"            , 'u', &yURG_debug.apis      },
   {   'Z' , "APIS"       , "interprocess communication"            , '#', &yURG_debug.apis_mas  },
   {   'x' , "sign"       , "o/s signal handling"                   , 'u', &yURG_debug.sign      },
   {   'X' , "SIGN"       , "o/s signal handling"                   , '#', &yURG_debug.sign_mas  },
   {   'b' , "scrp"       , "scripts and batch handling"            , 'u', &yURG_debug.scrp      },
   {   'B' , "SCRP"       , "scripts and batch handling"            , '#', &yURG_debug.scrp_mas  },
   {   'h' , "hist"       , "history, undo, redo"                   , 'u', &yURG_debug.hist      },
   {   'H' , "HIST"       , "history, undo, redo"                   , '#', &yURG_debug.hist_mas  },
   /*---(deeper program)-----------------*/
   {   'g' , "graf"       , "graphics, drawing, and display"        , 'u', &yURG_debug.graf      },
   {   'G' , "GRAF"       , "graphics, drawing, and display"        , '#', &yURG_debug.graf_mas  },
   {   'd' , "data"       , "complex data structure handling"       , 'u', &yURG_debug.data      },
   {   'D' , "DATA"       , "complex data structure handling"       , '#', &yURG_debug.data_mas  },
   {   'e' , "envi"       , "environmental processing"              , 'u', &yURG_debug.envi      },
   {   'E' , "ENVI"       , "environmental processing"              , '#', &yURG_debug.envi_mas  },
   {   's' , "sort"       , "data sorting and ordering"             , 'u', &yURG_debug.sort      },
   {   'S' , "SORT"       , "data sorting and ordering"             , '#', &yURG_debug.sort_mas  },
   /*---(specific)-----------------------*/
   /*---(end-of-list)--------------------*/
   {   '\0', "END-OF-LIST", "end of list"                           , ' ', NULL                  },

};

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
      printf ("%3d %c %-15.15s %-40.40s %10p %c\n", i,
            yURG_info [i].abbr , yURG_info [i].full ,
            yURG_info [i].desc , yURG_info [i].point,
            *(yURG_info [i].point));
   }
   /*---(complete)-----------------------*/
   return 0;
}

char         /*--> set a single urgent by abbr -----------[ ------ [ ------ ]-*/
yURG_abbr          (char a_abbr)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         = -10;
   int         i           = 0;
   int         x_count     = 0;
   char       *x_valid     = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
   /*---(defense)------------------------*/
   --rce;  if (a_abbr <=  32)                         return rce;
   --rce;  if (strchr (x_valid, a_abbr) == NULL)      return rce;
   /*---(find)---------------------------*/
   --rce;
   for (i = 0; i < MAX_URGS; ++i) {
      /*---(stop at end)-----------------*/
      if (yURG_info [i].abbr  == '\0')                break;
      /*---(filter)----------------------*/
      if (yURG_info [i].type  == '-')                 continue;
      if (yURG_info [i].abbr  != a_abbr)              continue;
      if (yURG_info [i].point == NULL)                return rce;
      /*---(set)-------------------------*/
      ++x_count;
      *(yURG_info [i].point) = 'y';
      /*---(check mas)-------------------*/
      if (yURG_info [i].type  == '#' && a_abbr >= 'A' && a_abbr <= 'Z') {
         yURG_abbr (tolower (a_abbr));
      }
   }
   /*---(check)--------------------------*/
   --rce;  if (x_count < 1  )                         return rce;
   --rce;  if (x_count > 1  )                         return rce;
   /*---(complete)-----------------------*/
   return 0;
}

char       /*----: process the urgents/debugging -----------------------------*/
yURG_mass          (char a_set, char a_extra)
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

char       /*----: process the urgents/debugging -----------------------------*/
yURG_parse         (int a_argc, char *a_argv[])
{
   /*---(locals)-----------+-----------+-*/
   int         i           = 0;
   char        rc          = 0;
   char       *a           = NULL;
   int         x_len       = 0;
   int         x_total     = 0;
   int         x_urgs      = 0;
   int         x_bad       = 0;
   /*---(process)------------------------*/
   DEBUG_TOPS  yLOG_enter (__FUNCTION__);
   for (i = 1; i < a_argc; ++i) {
      a = a_argv[i];
      ++x_total;
      if (a[0] != '@')  continue;
      DEBUG_ARGS  yLOG_info  ("urgent", a);
      x_len  = strlen (a);
      ++x_urgs;
      rc = 0;
      if      (x_len == 2)  rc = yURG_abbr  (a[1]);
      /*> else if (x_len >= 5)  rc = yURG_set   (a + 2);                              <*/
      else    ++x_bad;
      if (rc < 0) ++x_bad;
   }
   /*---(complete)-----------------------*/
   DEBUG_TOPS  yLOG_exit  (__FUNCTION__);
   return 0;
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
   }
   /*---(complete)-----------------------*/
   return unit_answer;
}



char       /*----: set up programgents/debugging -----------------------------*/
yURG__testquiet     (void)
{
   return 0;
}

char       /*----: set up programgents/debugging -----------------------------*/
yURG__testloud      (void)
{
   return 0;
}

char       /*----: set up program urgents/debugging --------------------------*/
yURG__testend       (void)
{
   return 0;
}

/*===[[ END ]]================================================================*/
