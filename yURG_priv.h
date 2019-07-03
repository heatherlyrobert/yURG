/*===[[ HEADER GUARD ]]=======================================================*/
#ifndef YURG_priv_hguard
#define YURG_priv_hguard loaded



/*===[[ BEG_HEADER ]]=========================================================*/
/*345678901-12345678901-12345678901-12345678901-12345678901-12345678901-12345678901-12345678901-*/

/*===[[ ONE_LINERS ]]=========================================================*/

#define     P_FOCUS     "RS (run-time support)"
#define     P_NICHE     "de (debugging/logging control)"
#define     P_PURPOSE   "simple, clean, incremental debugging and logging control"

#define     P_NAMESAKE  "zelus-daimon (enforcer)"
#define     P_HERITAGE  "zeal, sibling of strength (kratos), force (bia), and victory (nike)"
#define     P_IMAGERY   "angel-like being, represents zeal and dedication, enforcer of zeus"

#define     P_SYSTEM    "gnu/linux   (powerful, ubiquitous, technical, and hackable)"
#define     P_LANGUAGE  "ansi-c      (wicked, limitless, universal, and everlasting)"
#define     P_CODESIZE  "small       (appoximately 1,000 slocl)"

#define     P_AUTHOR    "heatherlyrobert"
#define     P_CREATED   "2014-10"
#define     P_DEPENDS   "none"

#define     P_VERNUM    "0.4f"
#define     P_VERTXT    "updated to handle prefix wildcard on names"

#define     P_PRIORITY  "direct, simple, brief, vigorous, and lucid (h.w. fowler)"
#define     P_PRINCIPAL "[grow a set] and build your wings on the way down (r. bradbury)"
#define     P_REMINDER  "there are many better options, but i *own* every byte of this one"

/*===[[ REASONING ]]==========================================================*/
/*345678901-12345678901-12345678901-12345678901-12345678901-12345678901-12345678901-12345678901-*/

#define     P_DEFINE    \
 "process logging and debugging is a method of observing actual program¦" \
 "behavior in order to learn, trace, identify, understand, and repair¦" \
 "non-trivial and emergent (multi-cause) run-time issues¦"
#define     P_CURRENT   \
 "my code base is growing quickly and much of that code executes either¦" \
 "continuously, frequently, or at critical moments -- big code base,¦" \
 "audacious plans, and one programmer to rule it all ;)¦"
#define     P_CONCERN   \
 "the art of logging, messaging, reporting, and creating transparent programs¦" \
 "has been replaced with massive, complex programs and expensive commercial¦" \
 "monitoring with incoherent streams of one-dimentional, ad-hoc messages.¦"
#define     P_ALTERNS   "syslog, systemd, printf, gdb"
#define     P_VALUE     \
 "process logging and debugging is a rapid way to diagnose process issues.¦" \
 "it is a huge time and resource saver in build/testing, recreating prodution¦" \
 "issues, and regaining logic/flow knowledge.¦"
#define     P_USERBASE  \
 "never confuse tailored, technical, super-user systems and general, easy-¦" \
 "to-use, zero effort required systems built to get end-users up and happy¦" \
 "as quickly as possible.  i will always chose power.¦"
#define     P_NEED      \
 "i need something run-time configurable, remain built-in, and ready for¦" \
 "immediate use.  it must include structure/flow logging as well as values¦" \
 "and state messages, and be easy to search, sort, and filter.¦"
#define     P_SUMMARY   \
 "yURG/yLOG are a pair of simple, direct, consistent, and clean libraries¦" \
 "to enable process logging, tracing, and debugging in order to speed issue¦" \
 "detection, identification, repair, and validation in my custom programs.¦"
#define     P_OBJECTIVE \
 "a) allow programs to be observed without significantly altering them¦" \
 "b) provide a forensic trail for programs to aid reproduction of issues¦" \
 "c) keep it simple so that it does not require huge learning curve¦" \
 "d) cleanly incorporated so it can remain permenantly in source code¦" \
 "e) maximize reuse so i don't have to recreate each time¦" \
 "f) standardize so data can be scanned quickly and troubles found fast¦" \
 "g) easy and automatic to remove so as to not hamper production¦" \
 "h) allows programmers to see the true program execution  path¦" \
 "i) cut significant time from tracing, debugging, and maintaining¦" \
 "j) speed education of new maintainers and unit testers (watch flow)¦" \
 "k) re-enforce a disciplined development culture and building-to-last¦" \
 "l) avoid a product that will require me to switch every few years¦"
#define     P_WARNINGS  \
 "a) logging eats up cpu, disk, and other resources¦" \
 "b) is rarely reviewed (only because existing methods are complicated)¦" \
 "c) can distract when nothing needs to be reviewed (configurable)¦" \
 "d) is one more thing that can go wrong (always funny)¦" \
 "e) must be very different for high volume apps¦" \
 "f) has to be built ahead of time and therefore can slow projects¦" \
 "g) since its shared, changes can effect all programs¦" \
 "h) drives a single method of thinking (myopia requires self-review)¦"

/*===[[ END_HEADER ]]=========================================================*/

/*345678901-12345678901-123456789-123456789-123456789-123456789-123456789-123456789-123456789-*/

#include    <stdio.h>        /* C_ANSI : strcpy, strlen, strchr, strcmp, ...  */
#include    <string.h>       /* C_ANSI : printf, snprintf, fgets, fopen, ...  */
#include    <stdlib.h>       /* C_ANSI : exit                                 */
#include    <ctype.h>        /* C_ANSI : tolower, toupper, ...                */
#include    <sys/mount.h>    /* C_ANSI : mount                                */

#include    <yLOG.h>         /* CUSTOM : heatherly program logging            */
#include    <ySTR.h>         /* CUSTOM : heatherly string handling            */

#include    "yURG.h"


#define        MAX_URGS        500

typedef   struct  cYURG_TYPE   tYURG_TYPE;
struct cYURG_TYPE
{
   char        type;                        /* matches urgent types           */
   char        sub;                         /* matches urgent sub-types;      */
   char        desc        [LEN_LABEL];     /* description of type            */
};
extern  tYURG_TYPE  yURG_type [MAX_URGS];

typedef   struct  cYURG_INFO   tYURG_INFO;
struct cYURG_INFO
{
   char        abbr;                        /* single letter name             */
   char        full        [LEN_LABEL];     /* full name                      */
   char        desc        [LEN_DESC ];     /* explanation                    */
   char        type;                        /* main type                      */
   char        sub;                         /* subtype                        */
   char       *point;                       /* pointer to normal              */
};
extern tYURG_INFO  yURG_info [MAX_URGS];


/*345678901-12345678901-12345678901-12345678901-12345678901-12345678901-123456*/

char        yurg__flip              (int i, cchar a_lower, cchar a_on);
char        yurg__multi             (cchar *a_string, cchar a_on);
char        yurg__wild              (cchar *a_string, cchar a_on);

char*       yURG__unit              (char *a_question, int a_num);
char        yURG__testquiet         (void);
char        yURG__testloud          (void);
char        yURG__testend           (void);

char        yurg_category           (cchar *a_prog, cchar a_type);
char        yurg_urgents            (cchar *a_prog);

#endif
