/*===[[ START ]]==============================================================*/
#include    "yURG.h"
#include    "yURG_priv.h"


char
yurg_stage_clear        (void)
{
   strlcpy (myURG.stage, "----- ----- -----", LEN_LABEL);
   return 0;
}

char
yurg_stage_prep         (void)
{
   int         i           =    0;
   if (strcmp (myURG.stage, "----- ----- -----") == 0) {
      strlcpy (myURG.stage, "yyyyy yyyyy yyyyy", LEN_LABEL);
      return 0;
   }
   if (myURG.stage [YURG_STAGE_MAIN] == 'y') {
      myURG.stage [YURG_STAGE_ONE] = 'y';
      myURG.stage [YURG_STAGE_TWO] = 'y';
      myURG.stage [YURG_STAGE_THR] = 'y';
      myURG.stage [YURG_STAGE_FOU] = 'y';
      myURG.stage [YURG_STAGE_FIV] = 'y';
      return 0;
   }
   for (i = YURG_STAGE_ONE; i <= YURG_STAGE_FIV; ++i) {
      if (myURG.stage [i] == 'y') myURG.stage [YURG_STAGE_MAIN] = 'y';
   }
   return 0;
}

char
yURG_stage_check        (char a_stage)
{
   char        rc          =   -1;
   char        s           [LEN_RECD];
   char        t           [LEN_RECD];
   yLOGS_unmute ();
   sprintf (t, "%s : checking %d, ", __FUNCTION__, a_stage);
   switch (a_stage) {
   case YURG_STAGE_INIT :  strlcpy (s, "initialization"  , LEN_RECD);   break;
   case YURG_STAGE_INPT :  strlcpy (s, "file/pipe input" , LEN_RECD);   break;
   case YURG_STAGE_MAIN :  strlcpy (s, "main loop"       , LEN_RECD);   break;
   case YURG_STAGE_OUTP :  strlcpy (s, "file/pipe output", LEN_RECD);   break;
   case YURG_STAGE_WRAP :  strlcpy (s, "wrap_up"         , LEN_RECD);   break;
   case YURG_STAGE_ONE  :  strlcpy (s, "user stage 1"    , LEN_RECD);   break;
   case YURG_STAGE_TWO  :  strlcpy (s, "user stage 2"    , LEN_RECD);   break;
   case YURG_STAGE_THR  :  strlcpy (s, "user stage 3"    , LEN_RECD);   break;
   case YURG_STAGE_FOU  :  strlcpy (s, "user stage 4"    , LEN_RECD);   break;
   case YURG_STAGE_FIV  :  strlcpy (s, "user stage 5"    , LEN_RECD);   break;
   default              :  strlcpy (s, "UNKNOWN stage"   , LEN_RECD);   break;
   }
   strlcat (t, s, LEN_RECD);
   if (myURG.stage [a_stage] == 'y') {
      strlcat (t, ", UNMUTING", LEN_RECD);
      yLOG_note (t);
      rc = 1;
   } else {
      strlcat (t, ", MUTING", LEN_RECD);
      yLOG_note (t);
      yLOGS_mute   ();
      rc = 0;
   }
   return rc;
}



/*====================------------------------------------====================*/
/*===----                    unit testing accessor                     ----===*/
/*====================------------------------------------====================*/
static void      o___UNITTEST________________o (void) {;}

char*            /* [------] unit test accessor ------------------------------*/
yurg_stage__unit        (char *a_question, int a_num)
{
   char        t           [LEN_RECD];
   int         c           = 0;
   /*---(initialize)---------------------*/
   snprintf (unit_answer, LEN_RECD, "STAGE            : request not understood");
   /*---(string testing)-----------------*/
   if      (strncmp (a_question, "settings"  , 20)  == 0) {
      snprintf (unit_answer, LEN_RECD, "STAGE settings   : [%s]", myURG.stage);
   }
   /*---(complete)-----------------------*/
   return unit_answer;
}


