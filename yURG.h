/*===[[ HEADER GUARD ]]=======================================================*/
#ifndef YURG_HGUARD
#define YURG_HGUARD loaded



#define        YURG_OFF        '-'
#define        YURG_ON         'y'
#define        YURG_MAS        'Y'

#define        YURG_MSG        "/tmp/console.txt"
#define        YURG_BASE       '>'
#define        YURG_LEVEL0     '>'
#define        YURG_LEVEL1     '-'
#define        YURG_LEVEL2     '+'
#define        YURG_ERR        "/tmp/errors.txt"
#define        YURG_FATAL      'F'
#define        YURG_FATAL0     'F'
#define        YURG_FATAL1     'f'
#define        YURG_FATAL2     'ü'
#define        YURG_WARN       'W'
#define        YURG_WARN0      'W'
#define        YURG_WARN1      'w'
#define        YURG_WARN2      'ÿ'
#define        YURG_LASTLINE   999

/*
 *    DEBUG_PROG   yLOG_enter   (__FUNCTION__);
 *    DEBUG_PROG   yLOG_value   ("testing"   , x_test);
 *    DEBUG_PROG   yLOG_note    ("all is well";
 *    DEBUG_PROG   yLOG_exit    (__FUNCTION__);
 *
 *
 *    yLOG_enter   (YURG_PROG, __FUNCTION__);
 *    yLOG_value   (YURG_PROG, "testing"   , x_test);
 *    yLOG_note    (YURG_PROG, "all is well";
 *    yLOG_exit    (YURG_PROG, __FUNCTION__);
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */


/*  real fla   vol
 *
 *    ´  p  prog   -   general program startup and shutdown
 *    ´  a  args   -   evaluating args and urgs
 *
 *    ·  ·  file   -   shared inpt/outp opens, closes, error handling, ...
 *    ´  i  inpt   -   data source files/db (non-conf) and database queries
 *    ´  o  outp   -   data output files/db (non-conf) and database insert, ...
 *    ´  c  conf   -   configuration handling, updating, etc
 *    ´  r  rptg   -   reporting, export, and import handling
 *
 *    ´  l  loop   y   main looping, highly repetitive
 *    ´  u  user   -   user input handling
 *    ´  g  graf   y   graphics handling, highly repetitive, specific
 *    ´  e  envi   -   apis, signals, os, shell
 *
 *    ´  s  sort   y   sorting and ordering data structures
 *    ´  f  find   y   searching for matches in major data structures
 *    ´  w  walk   y   walking major data structures for various purposes
 *    ´  t  tabl   y   data table input, update, searching, and output
 *
 *    ´  d  data   y   pure data chewing, reviewing, gathering
 *
 *    ´  ylog   -   yLOG
 *    ´  yurg   -   yURG
 *    ´  yunit  -   yUNIT
 *    ´  yvar   -   yVAR
 *    ´  ystr   -   ySTR
 *
 *    ´  ycmd   C   yCMD
 *    ´  ymark  M   yMARK
 *    ´  yfile  F   yFILE
 *    ´  ygod   G   yGOD
 *    ´  ykeys  K   yKEYS
 *    ´  ymacro B   yMACRO (batch)
 *    ´  ymap   P   yMAP
 *    ´  ymode  M   yMODE
 *    ´  ysrc   S   ySRC
 *    ´  yview  V   yVIEW
 *    ´  yviop  Y   yVIOPENGL
 *    ´  yvicu  Y   yVICURSES
 *
 *    ´  ycalc  ý   yCALC
 *    ´  ycolor ò   yCOLOR
 *    ´  ydlst  ë   yDLST
 *    ´  yexec  ì   yEXEC
 *    ´  yfont  ü   yFONT
 *    ´  ygltex ê   yGLTEX
 *    ´  ygolem ó   yGOLEM
 *    ·  yhub   ·   yHUBLIN
 *    ´  yjobs  ö   yJOBS
 *    ´  ykine  ñ   yKINE
 *    ´  yparse ÷   yPARSE
 *    ´  yregex ø   yREGEX
 *    ´  yrpn   ô   yRPN
 *    ´  ysced  ù   ySCHED
 *    ´  ysec   è   ySEC    (argus)
 *    ´  ysort  ú   ySORT   (troll)
 *    ´  yx11   õ   yX11
 *
 *
 *    0 - 9   custom for a program (not library)
 *
 */

/*---(base)-----------------*/
#define  YURG_ARGS    'a'     /* command line args/urgs                       */
#define  YURG_PROG    'p'     /* one-time startup/shutdown                    */
/*---(input-output)---------*/
#define  YURG_FILE    '+'    /* shared inpt/outp opens, errors, ...           */
#define  YURG_INPT    'i'    /* data source files/db (non-conf)               */
#define  YURG_OUTP    'o'    /* data output files/db (non-conf)               */
#define  YURG_CONF    'c'    /* configuration handling, updating, etc         */
#define  YURG_RPTG    'r'    /* reporting, export, and import handling        */
/*---(volume)---------------*/
#define  YURG_LOOP    'l'    /* main loop processing, highly repetitve        */
#define  YURG_USER    'u'    /* user input handling                           */
#define  YURG_GRAF    'g'    /* graphics handling, highly repetitve           */
#define  YURG_ENVI    'e'    /* directories, signals, apis, shell, o/s        */
/*---(data)-----------------*/
#define  YURG_SORT    's'    /* sorting and ordering data structures          */
#define  YURG_SRCH    'h'    /* searching in major data structures            */
#define  YURG_WALK    'w'    /* walking major data structures                 */
#define  YURG_DATA    'd'    /* pure data chewing, reviewing, gathering       */
#define  YURG_TABLE   't'    /* data table input, update, and output          */
/*---(vi-keys fund)---------*/
#define  YURG_YMODE   'O'
#define  YURG_YKEYS   'K'
#define  YURG_YFILE   'F'
#define  YURG_YVIEW   'V'
/*---(vi-keys extend)-------*/
#define  YURG_YMAP    'P'
#define  YURG_YCMD    'C'
#define  YURG_YMACRO  'B'
#define  YURG_YSRC    'S'
#define  YURG_YMARK   'M'
/*---(vi-keys graph)--------*/
#define  YURG_YGOD    'G'
#define  YURG_YVICU   'Y'
#define  YURG_YVIOP   'Y'
/*---(other libs)-----------*/
#define  YURG_YCALC   'ý'
#define  YURG_YCOLOR  'ò'
#define  YURG_YDLST   'ë'
#define  YURG_YEXEC   'ì'
#define  YURG_YFONT   'ü'
#define  YURG_YGLTEX  'ê'
#define  YURG_YGOLEM  'û'
#define  YURG_YJOBS   'ö'
#define  YURG_YKINE   'ñ'
#define  YURG_YPARSE  '÷'
#define  YURG_YREGEX  'ø'
#define  YURG_YRPN    'ô'
#define  YURG_YSCHED  'ù'
#define  YURG_YSEC    'è'
#define  YURG_YSORT   'ú'
#define  YURG_YDESK   'õ'    /* x-windows, w-windows, etc.                    */



typedef     unsigned char             uchar;
typedef     struct   cURG_DEBUG       tURG_DEBUG;
/*===[[ DEBUGGING SETUP ]]====================================================*/
/* this is my latest standard format, vars, and urgents                       */
/* v3.0b : added signal handling                                (2014-feb-01) */
struct cURG_DEBUG
{
   /*---(handle)-------------------------*/
   int         logger;                 /* log file so that we don't close it  */
   char        use;                    /* (-) normal, (d)ebug, or (u)nit      */
   char        loud;                   /* quiet '-' vs logging 'y'            */
   uchar       curr;
   char        mute;                   /* silent mode                         */
   /*---(overall)------------------------*/  /* abcde_ghi__lmnopqrstuvwxyz    */
   /* f = full urgents turns on all standard urgents                          */
   /* k = kitchen sink and turns everything on, i mean everything on          */
   /* q = quiet turns all urgents off including the log itself                */
   char        view;                   /* v) view direct to stdout            */
   /*---(startup/shutdown)---------------*/
   char        prog;                   /* p) specific program setup/wrapup    */
   char        args;                   /* a) command line args and urgents    */
   /*---(file processing)----------------*/
   char        inpt;                   /* i) text and data file input         */
   char        outp;                   /* o) text and data file output        */
   char        conf;                   /* c) configuration handling           */
   char        rptg;                   /* r) report/dump, analytics, stats    */
   /*---(event handling)-----------------*/
   char        loop;                   /* l) main program event loop          */
   char        user;                   /* u) user input and handling          */
   char        graf;                   /* g) grahpics setup and config        */
   char        envi;                   /* e) environment processing           */
   /*---(program)------------------------*/
   char        sort;                   /* s) data sorting and ordering        */
   char        find;                   /* y) data searching and traversal     */
   char        walk;                   /* y) data searching and traversal     */
   char        tabl;                   /* y) data searching and traversal     */
   char        data;                   /* d) complex data structure handling  */
   /*---(stages)-------------------------*/
   char        stage    [20];          /* stages for active logging           */
   char        cstage;                 /* current stage                       */
   /*---(data input)---------------------*/
   char        touch;                  /* data point -- touch interface       */
   char        raw;                    /* data point -- raw input             */
   char        simple;                 /* data point -- simplification        */
   char        average;                /* data point -- averaging             */
   char        critical;               /* data point -- critical points       */
   char        circle;                 /* data point -- circle marking        */
   char        curve;                  /* data point -- curve marking         */
   char        line;                   /* data point -- line straightening    */
   char        match;                  /* data point -- match processing      */
   char        dict;                   /* dictionary processssing             */
   /*---(hermes)-------------------------*/
   char        dirs;                   /* hermes locations                    */
   char        pkgs;                   /* hermes packages                     */
   char        cmds;                   /* hermes commands                     */
   char        gentoo;                 /* hermes gentoo/portage access        */
   char        cache;                  /* hermes cached database              */
   /*---(helios)-------------------------*/
   char        mass;                   /* grouging of nodes, like disk drive  */
   char        node;                   /* individual nodes                    */
   char        edge;                   /* connections between nodes           */
   char        stats;                  /* collections of statistics           */
   /*---(spreadsheet)--------------------*/
   char        locs;
   char        cell;
   /*---(calculations)-------------------*/
   char        yrpn;
   char        calc;
   char        exec;
   /*---(dependencies)-------------------*/
   char        deps;
   /*---(yVIKEYS)------------------------*/
   char        visu;                   /* yVIKEYS : visual selection          */
   char        ssel;                   /* yVIKEYS : text selection            */
   char        mark;                   /* yVIKEYS : location marks            */
   char        hint;                   /* yVIKEYS : location hinting          */
   char        srch;                   /* yVIKEYS : searching                 */
   char        map;                    /* yVIKEYS : screen mapping            */
   char        mode;                   /* yVIKEYS : mode handling             */
   char        keys;                   /* yVIKEYS : key handling              */
   char        edit;                   /* yVIKEYS : source editing            */
   /*---(vi-keys libraries)--------------*/
   char        yvihub;                 /* yVIHUB vi-keys coordination         */
   char        ymode;                  /* yMODE  vi-keys mode processing      */
   char        ykeys;                  /* yKEYS  vi-keys keyboard handling    */
   char        ymacro;                 /* yMACRO vi-keys script handling      */
   char        yview;                  /* yVIEW  vi-keys layout management    */
   char        ycmd;                   /* yCMD   vi-keys command processor    */
   char        ymark;                  /* yMARK  vi-keys search and marking   */
   char        ysrc;                   /* ySRC   vi-keys content editing      */
   char        ysrc_user;              /* ySRC   vi-keys content editing      */
   char        yfile;                  /* yFILE  vi-keys file management      */
   char        ymap;                   /* yMAP   vi-keys map mode handling    */
   char        ymap_user;              /* yMAP   vi-keys map mode handling    */
   char        ymap_graf;              /* yMAP   vi-keys map mode handling    */
   /*---(registers)----------------------*/
   char        regs;                   /* s_sel  : copy and paste registers   */
   /*---(other)--------------------------*/
   char        adjs;                   /* small, configurable adjustments     */
   char        s;
   char        sylk;
   char        gnome;
   char        dtree;          /* displays the dependency tree and exits      */
   /*---(safe-strings)-------------------*/
   char        ystr;                   /* ySTR string library                 */
   char        ydlst;                  /* yDLST quad-double linked list       */
   char        ysched;                 /* ySCHED kernighan sched grammar      */
   char        yexec;                  /* yEXEC process dispatch and control  */
   char        yjobs;                  /* yJOBS job execution and control     */
   char        ysec;                   /* ySEC system access logging          */
   char        ycalc;                  /* yCALC calculation engine            */
   char        ysort;                  /* ySORT data ordering                 */
   /*---(record parsing)-----------------*/
   char        yparse;                 /* yPARSE parsing to queue libarary    */
   /*---(robotics)-----------------------*/
   char        ygolem;                 /* yGOLEM robotics controller          */
   /*---(regular expressions)------------*/
   char        yregex;                 /* yREGEX library                      */
   /*---(windows)------------------------*/
   char        desk;                   /* desktop/window control              */
   char        yxwin;                  /* x11 control                         */
   /*---(kinematics)---------------------*/
   char        ykine;                  /* yKINE kinematics library -- main    */
   char        ykine_calc;             /* yKINE kinematics library -- sub     */
   char        ykine_tick;             /* yKINE kinematics library -- sub     */
   char        ykine_data;             /* yKINE kinematics library -- sub     */
   char        ykine_scrp;             /* yKINE kinematics library -- sub     */
   char        ykine_move;             /* yKINE kinematics library -- sub     */
   char        ykine_exact;            /* yKINE kinematics library -- sub     */
   /*---(vi-keys)------------------------*/
   char        yvikeys;                     /* yVIKEYS vi-keys library        */
   char        yvikeys_keys;                /* yVIKEYS vi-keys library        */
   char        yvikeys_mode;                /* yVIKEYS vi-keys library        */
   char        yvikeys_scale;               /* yVIKEYS vi-keys library        */
   /*---(fonts)--------------------------*/
   char        yfont;                  /* yFONT texture mapped font library   */
   char        yfont_file;             /* yFONT file creation and access      */
   char        yfont_calc;             /* yFONT layout and vertex calculation */
   char        yfont_map;              /* yFONT texture mapping and access    */
   /*---(textures)-----------------------*/
   char        ygltex;                 /* yFONT opengl texture handling       */
   /*---(colors)-------------------------*/
   char        ycolor;                 /* yFONT opengl color handling         */
   /*---(hyleoroi)-----------------------*/
   char        format;                 /* formatting options                  */
   char        color;                  /* color formatting options            */
   /*---(ascii)--------------------------*/
   char        yascii;                 /* yASCII font and art                 */
   /*---(done)---------------------------*/
};
extern    tURG_DEBUG      myURG;



/*---(silent)-----------------*/
#define     NOT_DEBUG              if (myURG.use                == '-')
#define     DEBUG_ANY              yLOG_curr (myURG.cstage, '¢');  
/*---(overall)----------------*/
#define     DEBUG_VIEW             yLOG_curr (myURG.cstage, 'v');  if (myURG.view    != '-')
#define     DEBUG_VIEW_M           yLOG_curr (myURG.cstage, 'v');  if (myURG.view    == 'Y')
/*---(startup/shutdown)-------*/
#define     DEBUG_PROG             yLOG_curr (myURG.cstage, 'p');  if (myURG.prog    != '-')
#define     DEBUG_PROG_M           yLOG_curr (myURG.cstage, 'p');  if (myURG.prog    == 'Y')
#define     DEBUG_ARGS             yLOG_curr (myURG.cstage, 'a');  if (myURG.args    != '-')
#define     DEBUG_ARGS_M           yLOG_curr (myURG.cstage, 'a');  if (myURG.args    == 'Y')
/*---(input/output)-----------*/
#define     DEBUG_FILE             yLOG_curr (myURG.cstage, 'f');  if (myURG.inpt != '-' || myURG.outp != '-')
#define     DEBUG_FILE_M           yLOG_curr (myURG.cstage, 'f');  if (myURG.inpt == 'Y' || myURG.outp == 'Y')
#define     DEBUG_INPT             yLOG_curr (myURG.cstage, 'i');  if (myURG.inpt    != '-')
#define     DEBUG_INPT_M           yLOG_curr (myURG.cstage, 'i');  if (myURG.inpt    == 'Y')
#define     DEBUG_OUTP             yLOG_curr (myURG.cstage, 'o');  if (myURG.outp    != '-')
#define     DEBUG_OUTP_M           yLOG_curr (myURG.cstage, 'o');  if (myURG.outp    == 'Y')
#define     DEBUG_CONF             yLOG_curr (myURG.cstage, 'c');  if (myURG.conf    != '-')
#define     DEBUG_CONF_M           yLOG_curr (myURG.cstage, 'c');  if (myURG.conf    == 'Y')
#define     DEBUG_RPTG             yLOG_curr (myURG.cstage, 'r');  if (myURG.rptg    != '-')
#define     DEBUG_RPTG_M           yLOG_curr (myURG.cstage, 'r');  if (myURG.rptg    == 'Y')
/*---(event/volume)-----------*/
#define     DEBUG_LOOP             yLOG_curr (myURG.cstage, 'l');  if (myURG.loop    != '-')
#define     DEBUG_LOOP_M           yLOG_curr (myURG.cstage, 'l');  if (myURG.loop    == 'Y')
#define     DEBUG_USER             yLOG_curr (myURG.cstage, 'u');  if (myURG.user    != '-')
#define     DEBUG_USER_M           yLOG_curr (myURG.cstage, 'u');  if (myURG.user    == 'Y')
#define     DEBUG_GRAF             yLOG_curr (myURG.cstage, 'g');  if (myURG.graf    != '-')
#define     DEBUG_GRAF_M           yLOG_curr (myURG.cstage, 'g');  if (myURG.graf    == 'Y')
#define     DEBUG_ENVI             yLOG_curr (myURG.cstage, 'e');  if (myURG.envi    != '-')
#define     DEBUG_ENVI_M           yLOG_curr (myURG.cstage, 'e');  if (myURG.envi    == 'Y')


/*---(program)----------------*/
#define     DEBUG_DATA             yLOG_curr (myURG.cstage, 'd');  if (myURG.data    != '-')
#define     DEBUG_DATA_M           yLOG_curr (myURG.cstage, 'd');  if (myURG.data    == 'Y')
#define     DEBUG_SORT             yLOG_curr (myURG.cstage, 's');  if (myURG.sort    != '-')
#define     DEBUG_SORT_M           yLOG_curr (myURG.cstage, 's');  if (myURG.sort    == 'Y')
#define     DEBUG_TRAV             yLOG_curr (myURG.cstage, 'y');  if (myURG.trav    != '-')
#define     DEBUG_TRAV_M           yLOG_curr (myURG.cstage, 'y');  if (myURG.trav    == 'Y')
/*---(gregg)-----------------------------*/
#define     DEBUG_TOUCH            yLOG_curr (myURG.cstage, '¢');  if (myURG.touch              != '-')
#define     DEBUG_TOUCH_M          yLOG_curr (myURG.cstage, '¢');  if (myURG.touch              == 'Y')
#define     DEBUG_RAW              yLOG_curr (myURG.cstage, '¢');  if (myURG.raw                != '-')
#define     DEBUG_RAW_M            yLOG_curr (myURG.cstage, '¢');  if (myURG.raw                == 'Y')
#define     DEBUG_SIMP             yLOG_curr (myURG.cstage, '¢');  if (myURG.simple             != '-')
#define     DEBUG_SIMP_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.simple             == 'Y')
#define     DEBUG_AVG              yLOG_curr (myURG.cstage, '¢');  if (myURG.average            != '-')
#define     DEBUG_AVG_M            yLOG_curr (myURG.cstage, '¢');  if (myURG.average            == 'Y')
#define     DEBUG_CRIT             yLOG_curr (myURG.cstage, '¢');  if (myURG.critical           != '-')
#define     DEBUG_CRIT_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.critical           == 'Y')
#define     DEBUG_CIRC             yLOG_curr (myURG.cstage, '¢');  if (myURG.circle             != '-')
#define     DEBUG_CIRC_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.circle             == 'Y')
#define     DEBUG_CURV             yLOG_curr (myURG.cstage, '¢');  if (myURG.curve              != '-')
#define     DEBUG_CURV_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.curve              == 'Y')
#define     DEBUG_LINE             yLOG_curr (myURG.cstage, '¢');  if (myURG.line               != '-')
#define     DEBUG_LINE_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.line               == 'Y')
#define     DEBUG_MATCH            yLOG_curr (myURG.cstage, '¢');  if (myURG.match              != '-')
#define     DEBUG_MATCH_M          yLOG_curr (myURG.cstage, '¢');  if (myURG.match              == 'Y')
#define     DEBUG_DICT             yLOG_curr (myURG.cstage, '¢');  if (myURG.dict               != '-')
#define     DEBUG_DICT_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.dict               == 'Y')
/*---(stages)----------------------------*/
#define     YURG_BEG               0
#define     YURG_MID               1
#define     YURG_END               2
#define     YURG_ONE               4
#define     YURG_TWO               5
#define     YURG_THR               6
#define     YURG_FOU               7
#define     YURG_FIV               8  
/*---(hermes)----------------------------*/
#define     DEBUG_DIRS             yLOG_curr (myURG.cstage, '¢');  if (myURG.dirs               != '-')
#define     DEBUG_DIRS_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.dirs               == 'Y')
#define     DEBUG_PKGS             yLOG_curr (myURG.cstage, '¢');  if (myURG.pkgs               != '-')
#define     DEBUG_PKGS_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.pkgs               == 'Y')
#define     DEBUG_CMDS             yLOG_curr (myURG.cstage, '¢');  if (myURG.cmds               != '-')
#define     DEBUG_CMDS_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.cmds               == 'Y')
#define     DEBUG_GENTOO           yLOG_curr (myURG.cstage, '¢');  if (myURG.gentoo             != '-')
#define     DEBUG_GENTOO_M         yLOG_curr (myURG.cstage, '¢');  if (myURG.gentoo             == 'Y')
#define     DEBUG_CACHE            yLOG_curr (myURG.cstage, '¢');  if (myURG.cache              != '-')
#define     DEBUG_CACHE_M          yLOG_curr (myURG.cstage, '¢');  if (myURG.cache              == 'Y')
/*---(graph/helios)----------------------*/
#define     DEBUG_MASS             yLOG_curr (myURG.cstage, '¢');  if (myURG.mass               != '-')
#define     DEBUG_MASS_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.mass               == 'Y')
#define     DEBUG_NODE             yLOG_curr (myURG.cstage, '¢');  if (myURG.node               != '-')
#define     DEBUG_NODE_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.node               == 'Y')
#define     DEBUG_EDGE             yLOG_curr (myURG.cstage, '¢');  if (myURG.edge               != '-')
#define     DEBUG_EDGE_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.edge               == 'Y')
#define     DEBUG_STATS            yLOG_curr (myURG.cstage, '¢');  if (myURG.stats              != '-')
#define     DEBUG_STATS_M          yLOG_curr (myURG.cstage, '¢');  if (myURG.stats              == 'Y')
/*---(dependencies)----------------------*/
#define     DEBUG_DEPS             yLOG_curr (myURG.cstage, '¢');  if (myURG.deps               != '-')
#define     DEBUG_DEPS_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.deps               == 'Y')
/*---(cells)-----------------------------*/
#define     DEBUG_LOCS             yLOG_curr (myURG.cstage, '¢');  if (myURG.locs               != '-')
#define     DEBUG_LOCS_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.locs               == 'Y')
#define     DEBUG_CELL             yLOG_curr (myURG.cstage, '¢');  if (myURG.cell               != '-')
#define     DEBUG_CELL_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.cell               == 'Y')
/*---(formulas)--------------------------*/
#define     DEBUG_YRPN             yLOG_curr (myURG.cstage, '¢');  if (myURG.yrpn               != '-')
#define     DEBUG_YRPN_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.yrpn               == 'Y')
#define     DEBUG_CALC             yLOG_curr (myURG.cstage, '¢');  if (myURG.calc               != '-')
#define     DEBUG_CALC_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.calc               == 'Y')
#define     DEBUG_EXEC             yLOG_curr (myURG.cstage, '¢');  if (myURG.exec               != '-')
#define     DEBUG_EXEC_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.exec               == 'Y')
#define     DEBUG_ADJS             yLOG_curr (myURG.cstage, '¢');  if (myURG.adjs               != '-')
#define     DEBUG_ADJS_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.adjs               == 'Y')
/*---(yVIKEYS)---------------------------*/
#define     DEBUG_VISU             yLOG_curr (myURG.cstage, '¢');  if (myURG.visu               != '-')
#define     DEBUG_VISU_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.visu               == 'Y')
#define     DEBUG_SSEL             yLOG_curr (myURG.cstage, '¢');  if (myURG.ssel               != '-')
#define     DEBUG_SSEL_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.ssel               == 'Y')
#define     DEBUG_MARK             yLOG_curr (myURG.cstage, '¢');  if (myURG.mark               != '-')
#define     DEBUG_MARK_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.mark               == 'Y')
#define     DEBUG_HINT             yLOG_curr (myURG.cstage, '¢');  if (myURG.hint               != '-')
#define     DEBUG_HINT_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.hint               == 'Y')
#define     DEBUG_MAP              yLOG_curr (myURG.cstage, '¢');  if (myURG.map                != '-')
#define     DEBUG_MAP_M            yLOG_curr (myURG.cstage, '¢');  if (myURG.map                == 'Y')
#define     DEBUG_MODE             yLOG_curr (myURG.cstage, '¢');  if (myURG.mode               != '-')
#define     DEBUG_MODE_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.mode               == 'Y')
#define     DEBUG_KEYS             yLOG_curr (myURG.cstage, '¢');  if (myURG.keys               != '-')
#define     DEBUG_KEYS_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.keys               == 'Y')
#define     DEBUG_EDIT             yLOG_curr (myURG.cstage, '¢');  if (myURG.edit               != '-')
#define     DEBUG_EDIT_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.edit               == 'Y')
/*---(registers)-------------------------*/
#define     DEBUG_REGS             yLOG_curr (myURG.cstage, '¢');  if (myURG.regs               != '-')
#define     DEBUG_REGS_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.regs               == 'Y')
#define     DEBUG_TREG             yLOG_curr (myURG.cstage, '¢');  if (myURG.treg               != '-')
#define     DEBUG_TREG_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.treg               == 'Y')
/*---(ySTR)------------------------------*/
#define     DEBUG_YSTR             yLOG_curr (myURG.cstage, '¢');  if (myURG.ystr               != '-')
#define     DEBUG_YSTR_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.ystr               == 'Y')
#define     DEBUG_YDLST            yLOG_curr (myURG.cstage, '¢');  if (myURG.ydlst              != '-')
#define     DEBUG_YDLST_M          yLOG_curr (myURG.cstage, '¢');  if (myURG.ydlst              == 'Y')
#define     DEBUG_YSCHED           yLOG_curr (myURG.cstage, '¢');  if (myURG.ysched             != '-')
#define     DEBUG_YSCHED_M         yLOG_curr (myURG.cstage, '¢');  if (myURG.ysched             == 'Y')
#define     DEBUG_YEXEC            yLOG_curr (myURG.cstage, '¢');  if (myURG.yexec              != '-')
#define     DEBUG_YEXEC_M          yLOG_curr (myURG.cstage, '¢');  if (myURG.yexec              == 'Y')
#define     DEBUG_YCALC            yLOG_curr (myURG.cstage, '¢');  if (myURG.ycalc              != '-')
#define     DEBUG_YCALC_M          yLOG_curr (myURG.cstage, '¢');  if (myURG.ycalc              == 'Y')
#define     DEBUG_YSORT            yLOG_curr (myURG.cstage, '¢');  if (myURG.ysort              != '-')
#define     DEBUG_YSORT_M          yLOG_curr (myURG.cstage, '¢');  if (myURG.ysort              == 'Y')
#define     DEBUG_YJOBS            yLOG_curr (myURG.cstage, '¢');  if (myURG.yjobs              != '-')
#define     DEBUG_YJOBS_M          yLOG_curr (myURG.cstage, '¢');  if (myURG.yjobs              == 'Y')
#define     DEBUG_YSEC             yLOG_curr (myURG.cstage, '¢');  if (myURG.ysec               != '-')
#define     DEBUG_YSEC_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.ysec               == 'Y')
/*---(vi-keys libraries)-----------------*/
#define     DEBUG_YVIHUB           yLOG_curr (myURG.cstage, '¢');  if (myURG.yvihub             != '-')
#define     DEBUG_YVIHUB_M         yLOG_curr (myURG.cstage, '¢');  if (myURG.yvihub             == 'Y')
#define     DEBUG_YMODE            yLOG_curr (myURG.cstage, '¢');  if (myURG.ymode              != '-')
#define     DEBUG_YMODE_M          yLOG_curr (myURG.cstage, '¢');  if (myURG.ymode              == 'Y')
#define     DEBUG_YKEYS            yLOG_curr (myURG.cstage, '¢');  if (myURG.ykeys              != '-')
#define     DEBUG_YKEYS_M          yLOG_curr (myURG.cstage, '¢');  if (myURG.ykeys              == 'Y')
#define     DEBUG_YMACRO           yLOG_curr (myURG.cstage, '¢');  if (myURG.ymacro             != '-')
#define     DEBUG_YMACRO_M         yLOG_curr (myURG.cstage, '¢');  if (myURG.ymacro             == 'Y')
#define     DEBUG_YVIEW            yLOG_curr (myURG.cstage, '¢');  if (myURG.yview              != '-')
#define     DEBUG_YVIEW_M          yLOG_curr (myURG.cstage, '¢');  if (myURG.yview              == 'Y')
#define     DEBUG_YCMD             yLOG_curr (myURG.cstage, '¢');  if (myURG.ycmd               != '-')
#define     DEBUG_YCMD_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.ycmd               == 'Y')
#define     DEBUG_YMARK            yLOG_curr (myURG.cstage, '¢');  if (myURG.ymark              != '-')
#define     DEBUG_YMARK_M          yLOG_curr (myURG.cstage, '¢');  if (myURG.ymark              == 'Y')
#define     DEBUG_YSRC             yLOG_curr (myURG.cstage, '¢');  if (myURG.ysrc               != '-')
#define     DEBUG_YSRC_U           yLOG_curr (myURG.cstage, '¢');  if (myURG.ysrc_user          != '-')
#define     DEBUG_YSRC_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.ysrc               == 'Y')
#define     DEBUG_YMAP             yLOG_curr (myURG.cstage, '¢');  if (myURG.ymap               != '-')
#define     DEBUG_YMAP_U           yLOG_curr (myURG.cstage, '¢');  if (myURG.ymap_user          != '-')
#define     DEBUG_YMAP_G           yLOG_curr (myURG.cstage, '¢');  if (myURG.ymap_graf          != '-')
#define     DEBUG_YMAP_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.ymap               == 'Y')
#define     DEBUG_YFILE            yLOG_curr (myURG.cstage, '¢');  if (myURG.yfile              != '-')
#define     DEBUG_YFILE_M          yLOG_curr (myURG.cstage, '¢');  if (myURG.yfile              == 'Y')
/*---(yPARSE)----------------------------*/
#define     DEBUG_YPARSE           yLOG_curr (myURG.cstage, '¢');  if (myURG.yparse             == 'y')
/*---(yGOLEM)----------------------------*/
#define     DEBUG_YGOLEM           yLOG_curr (myURG.cstage, '¢');  if (myURG.ygolem             == 'y')
/*---(yREGEX)----------------------------*/
#define     DEBUG_YREGEX           yLOG_curr (myURG.cstage, '¢');  if (myURG.yregex             != '-')
#define     DEBUG_YREGEX_M         yLOG_curr (myURG.cstage, '¢');  if (myURG.yregex             == 'Y')
/*---(windows)---------------------------*/
#define     DEBUG_DESK             yLOG_curr (myURG.cstage, '¢');  if (myURG.desk               != '-')
#define     DEBUG_DESK_M           yLOG_curr (myURG.cstage, '¢');  if (myURG.desk               != 'Y')
#define     DEBUG_YXWIN            yLOG_curr (myURG.cstage, '¢');  if (myURG.yxwin              != '-')
#define     DEBUG_YXWIN_M          yLOG_curr (myURG.cstage, '¢');  if (myURG.yxwin              != 'Y')
/*---(kinematics)------------------------*/
#define     DEBUG_YKINE            yLOG_curr (myURG.cstage, '¢');  if (myURG.ykine              != '-')
#define     DEBUG_YKINE_M          yLOG_curr (myURG.cstage, '¢');  if (myURG.ykine              == 'Y')
#define     DEBUG_YKINE_CALC       yLOG_curr (myURG.cstage, '¢');  if (myURG.ykine_calc         != '-')
#define     DEBUG_YKINE_TICK       yLOG_curr (myURG.cstage, '¢');  if (myURG.ykine_tick         != '-')
#define     DEBUG_YKINE_MOVE       yLOG_curr (myURG.cstage, '¢');  if (myURG.ykine_move         != '-')
#define     DEBUG_YKINE_DATA       yLOG_curr (myURG.cstage, '¢');  if (myURG.ykine_data         != '-')
#define     DEBUG_YKINE_SCRP       yLOG_curr (myURG.cstage, '¢');  if (myURG.ykine_scrp         != '-')
#define     DEBUG_YKINE_EXACT      yLOG_curr (myURG.cstage, '¢');  if (myURG.ykine_exact        != '-')
/*---(vi-keys)---------------------------*/
#define     DEBUG_YVIKEYS          yLOG_curr (myURG.cstage, '¢');  if (myURG.yvikeys            == 'y')
#define     DEBUG_YVIKEYS_KEYS     yLOG_curr (myURG.cstage, '¢');  if (myURG.yvikeys_keys       != '-')
#define     DEBUG_YVIKEYS_KEYS_M   yLOG_curr (myURG.cstage, '¢');  if (myURG.yvikeys_keys       == 'Y')
#define     DEBUG_YVIKEYS_MODE     yLOG_curr (myURG.cstage, '¢');  if (myURG.yvikeys_mode       != '-')
#define     DEBUG_YVIKEYS_MODE_M   yLOG_curr (myURG.cstage, '¢');  if (myURG.yvikeys_mode       == 'Y')
#define     DEBUG_YVIKEYS_SCALE    yLOG_curr (myURG.cstage, '¢');  if (myURG.yvikeys_scale      != '-')
#define     DEBUG_YVIKEYS_SCALE_M  yLOG_curr (myURG.cstage, '¢');  if (myURG.yvikeys_scale      == 'Y')
/*---(yFONT)-----------------------------*/
#define     DEBUG_YFONT            yLOG_curr (myURG.cstage, '¢');  if (myURG.yfont              != '-')
#define     DEBUG_YFONT_M          yLOG_curr (myURG.cstage, '¢');  if (myURG.yfont              == 'Y')
#define     DEBUG_YFONT_FILE       yLOG_curr (myURG.cstage, '¢');  if (myURG.yfont_file         == 'y')
#define     DEBUG_YFONT_CALC       yLOG_curr (myURG.cstage, '¢');  if (myURG.yfont_calc         == 'y')
#define     DEBUG_YFONT_MAP        yLOG_curr (myURG.cstage, '¢');  if (myURG.yfont_map          == 'y')
/*---(yGLTEX)----------------------------*/
#define     DEBUG_YGLTEX           yLOG_curr (myURG.cstage, '¢');  if (myURG.ygltex             != '-')
#define     DEBUG_YGLTEX_M         yLOG_curr (myURG.cstage, '¢');  if (myURG.ygltex             == 'Y')
/*---(yCOLOR)----------------------------*/
#define     DEBUG_YCOLOR           yLOG_curr (myURG.cstage, '¢');  if (myURG.ycolor             != '-')
#define     DEBUG_YCOLOR_M         yLOG_curr (myURG.cstage, '¢');  if (myURG.ycolor             == 'Y')
/*---(hyleoroi)--------------------------*/
#define     DEBUG_FORMAT           yLOG_curr (myURG.cstage, '¢');  if (myURG.format             != '-')
#define     DEBUG_FORMAT_M         yLOG_curr (myURG.cstage, '¢');  if (myURG.format             == 'Y')
#define     DEBUG_COLOR            yLOG_curr (myURG.cstage, '¢');  if (myURG.color              != '-')
#define     DEBUG_COLOR_M          yLOG_curr (myURG.cstage, '¢');  if (myURG.color              == 'Y')
/*---(yascii)----------------------------*/
#define     DEBUG_YASCII           yLOG_curr (myURG.cstage, '¢');  if (myURG.yascii             != '-')


typedef     const char         cchar;


char*       yURG_version            (void);
char        yURG_debugmode          (void);

char        yURG_orig               (char *a_orig);
char        yURG_curr               (char *a_curr);

char        yURG_logger             (int    a_argc, char *a_argv[]);
char        yURG_urgs               (int    a_argc, char *a_argv[]);

char        yURG_summ               (void);
char        yURG_list               (void);

char        yURG_by_abbr            (cchar  a_abbr, cchar a_on);
char        yURG_by_name            (cchar *a_name, cchar a_on);
char        yURG_by_debug           (cchar *a_name, char *r_abbr);

char        yURG_name               (cchar *a_name, cchar a_on); /* DEPRICATED */

char        yURG_lognum             (void);

char        yURG_stage_check        (char a_stage);

char        yURG_err_std            (void);
char        yURG_err_tmp            (void);
char        yURG_err_none           (void);
char        yURG_err_custom         (char *a_name);
char        yURG_err_live           (void);
char        yURG_err_mute           (void);
char        yURG_err                (cchar a_type, cchar *a_format, ...);
char*       yURG_err_last           (void);
char        yURG_err_clear          (void);
char        yURG_err_purge          (void);

char        yURG_msg_std            (void);
char        yURG_msg_tmp            (void);
char        yURG_msg_none           (void);
char        yURG_msg_custom         (char *a_name);
char        yURG_msg_live           (void);
char        yURG_msg_mute           (void);
char        yURG_msg                (cchar a_type, cchar *a_format, ...);
char*       yURG_msg_last           (void);
char        yURG_msg_clear          (void);
char        yURG_msg_purge          (void);

char        yURG_all_clear          (void);
char        yURG_all_tmp            (void);
char        yURG_all_none           (void);
char        yURG_all_mute           (void);
char        yURG_all_off            (void);
char        yURG_all_live           (void);
char        yURG_all_tmplive        (void);
char*       yURG_mute_status        (void);

char        yURG_touch              (cchar *a_file, cchar *a_own, cchar *a_grp, cchar *a_perms);
char        yURG_rm                 (cchar *a_file);
char        yURG_mkdir              (cchar *a_dir, cchar *a_own, cchar *a_grp, cchar *a_perms);
char        yURG_rmdir              (cchar *a_dir);
int         yURG_peek_count         (cchar *a_name);
char*       yURG_peek               (cchar *a_name, int n);
char*       yURG_peek_clear         (cchar *a_name, int n);
char        yURG_peek_exists        (cchar *a_name);
char*       yURG_peek_fill          (cchar *a_name, int n);
char*       yURG_peek_field         (cchar *a_name, int n);


#endif
/*===[[ END ]]================================================================*/
