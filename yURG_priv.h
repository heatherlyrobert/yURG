/*===[[ HEADER GUARD ]]=======================================================*/
#ifndef YURG_priv_hguard
#define YURG_priv_hguard loaded

#include    <stdio.h>
#include    <stdlib.h>                  /* getenv()                            */
#include    <string.h>

#include    "yURG.h"
#include    <yLOG.h>         /* CUSTOM : heatherly program logging            */
#include    <ySTR.h>         /* CUSTOM : heatherly string handling            */




typedef   struct  cYURG_INFO   tYURG_INFO;
struct cYURG_INFO
{
   char        abbr;                        /* single letter name             */
   char        full        [LEN_LABEL];     /* full name                      */
   char        desc        [LEN_DESC ];     /* explanation                    */
   char        type;                        /* universal, mas, special        */
   char       *point;                       /* universal, mas, special        */
};


char*       yURG__unit         (char *a_question, int a_num);
char        yURG__testquiet    (void);
char        yURG__testloud     (void);
char        yURG__testend      (void);


#endif
