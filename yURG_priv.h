/*===[[ HEADER GUARD ]]=======================================================*/
#ifndef YURG_priv_hguard
#define YURG_priv_hguard loaded

#include    <stdio.h>        /* C_ANSI : strcpy, strlen, strchr, strcmp, ...  */
#include    <string.h>       /* C_ANSI : printf, snprintf, fgets, fopen, ...  */
#include    <stdlib.h>       /* C_ANSI : exit                                 */
#include    <ctype.h>        /* C_ANSI : tolower, toupper, ...                */

#include    <yLOG.h>         /* CUSTOM : heatherly program logging            */
#include    <ySTR.h>         /* CUSTOM : heatherly string handling            */

#include    "yURG.h"


/* rapidly evolving version number to aid with visual change confirmation     */
#define YURG_VER_NUM   "0.3q"
#define YURG_VER_TXT   "created debugging entries for yGOLEM library"


typedef   struct  cYURG_TYPE   tYURG_TYPE;
struct cYURG_TYPE
{
   char        type;                        /* matches urgent types           */
   char        subtype;                     /* matches urgent sub-types;      */
   char        desc        [LEN_LABEL];     /* description of type            */
};

typedef   struct  cYURG_INFO   tYURG_INFO;
struct cYURG_INFO
{
   char        abbr;                        /* single letter name             */
   char        fast;                        /* must evaluate with logging     */
   char        full        [LEN_LABEL];     /* full name                      */
   char        desc        [LEN_DESC ];     /* explanation                    */
   char        type;                        /* universal, mas, special        */
   char        subtype;                     /* universal, mas, special        */
   char       *point;                       /* universal, mas, special        */
};


char*       yURG__unit         (char *a_question, int a_num);
char        yURG__testquiet    (void);
char        yURG__testloud     (void);
char        yURG__testend      (void);


#endif
