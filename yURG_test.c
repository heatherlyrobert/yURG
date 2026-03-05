/*===[[ START ]]==============================================================*/
#include    "yURG.h"
#include    "yURG_priv.h"



/*===[[ GNU GENERAL PUBLIC LICENSE (GPL) ]]===================================*/
/*´´·········1·········2·········3·········4·········5·········6·········7·········8  */

#define  P_COPYRIGHT   \
   "copyright (c) 2014 robert.s.heatherly at balsashrike at gmail dot com"

#define  P_LICENSE     \
   "the only place you could have gotten this code is my github, my website,¦"   \
   "or illegal sharing. given that, you should be aware that this is GPL licensed."

#define  P_COPYLEFT    \
   "the GPL COPYLEFT REQUIREMENT means any modifications or derivative works¦"   \
   "must be released under the same GPL license, i.e, must be free and open."

#define  P_INCLUDE     \
   "the GPL DOCUMENTATION REQUIREMENT means that you must include the original¦" \
   "copyright notice and the full licence text with any resulting anything."

#define  P_AS_IS       \
   "the GPL NO WARRANTY CLAUSE means the software is provided without any¦"      \
   "warranty and the author cannot be held liable for damages."

#define  P_THEFT    \
   "if you knowingly violate the spirit of these ideas, i suspect you might¦"    \
   "find any number of freedom-minded hackers may take it quite personally ;)"

/*´´·········1·········2·········3·········4·········5·········6·········7·········8  */
/*===[[ GNU GENERAL PUBLIC LICENSE (GPL) ]]===================================*/



/*====================------------------------------------====================*/
/*===----                        utility functions                     ----===*/
/*====================------------------------------------====================*/
static void      o___UTILITY_______o (void) {;}

char        yURG_ver     [500];

char*      /* ---- : return library versioning information -------------------*/
yURG_version       (void)
{
   char    t [20] = "";
#if    __TINYC__ > 0
   strncpy (t, "[tcc built  ]", 15);
#elif  __GNUC__  > 0
   strncpy (t, "[gnu gcc    ]", 15);
#elif  __HEPH__  > 0
   strncpy (t, "[hephaestus ]", 15);
#else
   strncpy (t, "[unknown    ]", 15);
#endif
   snprintf (yURG_ver, 100, "%s   %s : %s", t, P_VERNUM, P_VERTXT);
   return yURG_ver;
}

char         /*--> return status of debug ----------------[ ------ [ ------ ]-*/
yURG_debugmode     (void)
{
   if (myURG.logger < 0)   return '-';
   return 'y';
}



/*====================------------------------------------====================*/
/*===----                    unit testing accessor                     ----===*/
/*====================------------------------------------====================*/
static void      o___UNITTEST______o (void) {;}

char          unit_answer [LEN_RECD];

char*            /* [------] unit test accessor ------------------------------*/
yURG__unit         (char *a_question, int a_num)
{
   char        t           [LEN_RECD];
   int         c           = 0;
   /*---(initialize)---------------------*/
   strncpy (unit_answer, "yURG_unit, unknown request", 100);
   /*---(string testing)-----------------*/
   if      (strncmp(a_question, "lower"     , 20)  == 0) {
      yurg__strings ();
      snprintf (unit_answer, LEN_RECD, "yURG lower       : [%s]", myURG_priv.lower);
   } else if (strncmp(a_question, "upper"     , 20)  == 0) {
      yurg__strings ();
      snprintf (unit_answer, LEN_RECD, "yURG upper       : [%s]", myURG_priv.upper);
   } else if (strncmp(a_question, "count"     , 20)  == 0) {
      c = yurg__count ();
      snprintf (unit_answer, LEN_RECD, "yURG count       : %d"  , c);
   } else if (strncmp(a_question, "curr"      , 20)  == 0) {
      if (myURG_priv.curr < 0) {
         snprintf (unit_answer, LEN_RECD, "yURG curr   (%2d) : %c %s"  , myURG_priv.curr, '-', "n/a");
      } else {
         snprintf (unit_answer, LEN_RECD, "yURG curr   (%2d) : %c %s"  , myURG_priv.curr, yURG_info [myURG_priv.curr].abbr, yURG_info [myURG_priv.curr].full);
      }
   } else if (strncmp(a_question, "orig"      , 20)  == 0) {
      c = yURG_orig (t);
      snprintf (unit_answer, LEN_RECD, "yURG orig   (%2d) : [%s]"  , c, t);
   } else if (strncmp(a_question, "now"       , 20)  == 0) {
      c = yURG_curr (t);
      snprintf (unit_answer, LEN_RECD, "yURG now    (%2d) : [%s]"  , c, t);
   } else if (strncmp(a_question, "muting"    , 20)  == 0) {
      c = yURG_curr (t);
      snprintf (unit_answer, LEN_RECD, "yURG muting      : %c å%-25.25sæ  %c å%-25.25sæ"  , myURG_priv.mlive, t);
   }
   /*---(complete)-----------------------*/
   return unit_answer;
}

char*
yURG_mute_status        (void)
{
   char        s           [LEN_DESC]  = "";
   char        t           [LEN_DESC]  = "";
   sprintf (s, "%c %-10.10p å%-.30sæ", myURG_priv.mlive, myURG_priv.mfile, myURG_priv.mname);
   sprintf (t, "%c %-10.10p å%-.30sæ", myURG_priv.elive, myURG_priv.efile, myURG_priv.ename);
   sprintf (unit_answer, "MSG %-45.45s     ERR %s", s, t);
   return unit_answer;
}

