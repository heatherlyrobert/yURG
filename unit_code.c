#include    "yURG.h"
#include    "yURG_priv.h"



char       /*----: set up programgents/debugging -----------------------------*/
yURG__unit_quiet        (void)
{
   char       *x_args [2]  = { "yURG_unit","@@quiet" };
   myURG_priv.curr = -1;   
   yURG_logger (2, x_args);
   return 0;
}

char       /*----: set up programgents/debugging -----------------------------*/
yURG__unit_loud         (void)
{
   char       *x_args [2]  = { "yURG_unit","@@kitchen" };
   myURG_priv.curr = -1;   
   yURG_logger (2, x_args);
   return 0;
}

char       /*----: set up program urgents/debugging --------------------------*/
yURG__unit_end          (void)
{
   DEBUG_ARGS   yLOGS_end     ();
   return 0;
}


