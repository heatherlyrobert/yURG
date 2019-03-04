/*===[[ HEADER GUARD ]]=======================================================*/
#ifndef YURG_HGUARD
#define YURG_HGUARD loaded



#define        YURG_OFF        '-'
#define        YURG_ON         'y'
#define        YURG_MAS        'Y'



typedef     struct   cURG_DEBUG       tURG_DEBUG;
/*===[[ DEBUGGING SETUP ]]====================================================*/
/* this is my latest standard format, vars, and urgents                       */
/* v3.0b : added signal handling                                (2014-feb-01) */
struct cURG_DEBUG
{
   /*---(handle)-------------------------*/
   int         logger;                 /* log file so that we don't close it  */
   int         loud;                   /* quiet '-' vs logging 'y'            */
   /*---(overall)------------------------*/  /* abcdefghi_kl__opqrstuvwx_z    */
   /* f = full urgents turns on all standard urgents                          */
   /* k = kitchen sink and turns everything, i mean everything on             */
   /* q = quiet turns all urgents off including the log itself                */
   char        tops;                   /* t) broad structure and context      */
   char        rptg;                   /* r) report/dump, analytics, stats    */
   char        view;                   /* v) view direct to stdout            */
   /*---(startup/shutdown)---------------*/
   char        args;                   /* a) command line args and urgents    */
   char        conf;                   /* c) configuration handling           */
   char        prog;                   /* p) program setup and teardown       */
   /*---(file processing)----------------*/
   char        inpt;                   /* i) text and data file input         */
   char        outp;                   /* o) text and data file output        */
   char        sqls;                   /* q) sql and database accesses        */
   /*---(event handling)-----------------*/
   char        loop;                   /* l) main program event loop          */
   char        user;                   /* u) user input and handling          */
   char        apis;                   /* z) interprocess communication       */
   char        sign;                   /* x) os signal handling               */
   char        scrp;                   /* b) scripts and batch operations     */
   char        hist;                   /* h) history, undo, redo              */
   /*---(program)------------------------*/
   char        graf;                   /* g) grahpics setup and config        */
   char        wind;                   /* w) window drawing                   */
   char        data;                   /* d) complex data structure handling  */
   char        envi;                   /* e) environment processing           */
   char        sort;                   /* s) data sorting and ordering        */
   /*---(data input)---------------------*/
   char        touch;                  /* data point -- touch interface       */
   char        raw;                    /* data point -- raw input             */
   char        simple;                 /* data point -- simplification        */
   char        average;                /* data point -- averaging             */
   char        critical;               /* data point -- critical points       */
   char        circle;                 /* data point -- circle marking        */
   char        curve;                  /* data point -- curve marking         */
   char        line;                   /* data point -- line straightening    */
   char        dict;                   /* dictionary processssing             */
   /*---(hermes)-------------------------*/
   char        dirs;                   /* hermes locations                    */
   char        pkgs;                   /* hermes packages                     */
   char        cmds;                   /* hermes commands                     */
   char        gentoo;                 /* hermes gentoo/portage access        */
   char        cache;                  /* hermes cached database              */
   /*---(spreadsheet)--------------------*/
   char        locs;
   char        cell;
   /*---(calculations)-------------------*/
   char        rpn;
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
   char        edit;                   /* yVIKEYS : source editing            */
   /*---(registers)----------------------*/
   char        regs;                   /* s_sel  : copy and paste registers   */
   /*---(other)--------------------------*/
   char        adjs;                   /* small, configurable adjustments     */
   char        s;
   char        sylk;
   char        gnome;
   char        dtree;          /* displays the dependency tree and exits      */
   /*---(safe-strings)-------------------*/
   char        ylogs;                  /* yLOG process monitoring library     */
   char        ystr;                   /* ySTR string library                 */
   char        ydlst;                  /* yDLST quad-double linked list       */
   char        ysched;                 /* ySCHED kernighan sched grammar      */
   char        yexec;                  /* yEXEC process dispatch and control  */
   /*---(record parsing)-----------------*/
   char        yparse;                 /* yPARSE parsing to queue libarary    */
   /*---(robotics)-----------------------*/
   char        ygolem;                 /* yGOLEM robotics controller          */
   /*---(regular expressions)------------*/
   char        yregex;                 /* yREGEX library                      */
   /*---(kinematics)---------------------*/
   char        ykine_calc;                  /* yKINE kinematics library            */
   char        ykine_data;                  /* yKINE kinematics library            */
   char        ykine_scrp;                  /* yKINE kinematics library            */
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
   /*---(rpn)----------------------------*/
   char        yrpn;                   /* yRPN reverse polish notation        */
   /*---(hyleoroi)-----------------------*/
   char        format;                 /* formatting options                  */
   char        color;                  /* color formatting options            */
   /*---(done)---------------------------*/
};
extern    tURG_DEBUG      yURG_debug;



/*---(overall)----------------*/
#define     DEBUG_TOPS             if (yURG_debug.tops               != '-')
#define     DEBUG_TOPS_M           if (yURG_debug.tops               == 'Y')
#define     DEBUG_RPTG             if (yURG_debug.rptg               != '-')
#define     DEBUG_RPTG_M           if (yURG_debug.rptg               == 'Y')
#define     DEBUG_VIEW             if (yURG_debug.view               != '-')
#define     DEBUG_VIEW_M           if (yURG_debug.view               == 'Y')
/*---(startup/shutdown)-------*/
#define     DEBUG_ARGS             if (yURG_debug.args               != '-')
#define     DEBUG_ARGS_M           if (yURG_debug.args               == 'Y')
#define     DEBUG_CONF             if (yURG_debug.conf               != '-')
#define     DEBUG_CONF_M           if (yURG_debug.conf               == 'Y')
#define     DEBUG_PROG             if (yURG_debug.prog               != '-')
#define     DEBUG_PROG_M           if (yURG_debug.prog               == 'Y')
/*---(file/pipe)--------------*/
#define     DEBUG_INPT             if (yURG_debug.inpt               != '-')
#define     DEBUG_INPT_M           if (yURG_debug.inpt               == 'Y')
#define     DEBUG_OUTP             if (yURG_debug.outp               != '-')
#define     DEBUG_OUTP_M           if (yURG_debug.outp               == 'Y')
/*---(event handling)---------*/
#define     DEBUG_LOOP             if (yURG_debug.loop               != '-')
#define     DEBUG_LOOP_M           if (yURG_debug.loop               == 'Y')
#define     DEBUG_USER             if (yURG_debug.user               != '-')
#define     DEBUG_USER_M           if (yURG_debug.user               == 'Y')
#define     DEBUG_APIS             if (yURG_debug.apis               != '-')
#define     DEBUG_APIS_M           if (yURG_debug.apis               == 'Y')
#define     DEBUG_SIGN             if (yURG_debug.sign               != '-')
#define     DEBUG_SIGN_M           if (yURG_debug.sign               == 'Y')
#define     DEBUG_SCRP             if (yURG_debug.scrp               != '-')
#define     DEBUG_SCRP_M           if (yURG_debug.scrp               == 'Y')
#define     DEBUG_HIST             if (yURG_debug.hist               != '-')
#define     DEBUG_HIST_M           if (yURG_debug.hist               == 'Y')
/*---(program)----------------*/
#define     DEBUG_GRAF             if (yURG_debug.graf               != '-')
#define     DEBUG_GRAF_M           if (yURG_debug.graf               == 'Y')
#define     DEBUG_WIND             if (yURG_debug.wind               != '-')
#define     DEBUG_WIND_M           if (yURG_debug.wind               == 'Y')
#define     DEBUG_DATA             if (yURG_debug.data               != '-')
#define     DEBUG_DATA_M           if (yURG_debug.data               == 'Y')
#define     DEBUG_ENVI             if (yURG_debug.envi               != '-')
#define     DEBUG_ENVI_M           if (yURG_debug.envi               == 'Y')
#define     DEBUG_SORT             if (yURG_debug.sort               != '-')
#define     DEBUG_SORT_M           if (yURG_debug.sort               == 'Y')
/*---(gregg)-----------------------------*/
#define     DEBUG_TOUCH            if (yURG_debug.touch              == 'y')
#define     DEBUG_RAW              if (yURG_debug.raw                == 'y')
#define     DEBUG_SIMP             if (yURG_debug.simple             == 'y')
#define     DEBUG_AVG              if (yURG_debug.average            == 'y')
#define     DEBUG_CRIT             if (yURG_debug.critical           == 'y')
#define     DEBUG_CIRCLE           if (yURG_debug.circle             == 'y')
#define     DEBUG_CURVE            if (yURG_debug.curve              == 'y')
#define     DEBUG_LINE             if (yURG_debug.line               == 'y')
#define     DEBUG_DICT             if (yURG_debug.dict               == 'y')
/*---(hermes)----------------------------*/
#define     DEBUG_DIRS             if (yURG_debug.dirs               != '-')
#define     DEBUG_DIRS_M           if (yURG_debug.dirs               == 'Y')
#define     DEBUG_PKGS             if (yURG_debug.pkgs               != '-')
#define     DEBUG_PKGS_M           if (yURG_debug.pkgs               == 'Y')
#define     DEBUG_CMDS             if (yURG_debug.cmds               != '-')
#define     DEBUG_CMDS_M           if (yURG_debug.cmds               == 'Y')
#define     DEBUG_GENTOO           if (yURG_debug.gentoo             != '-')
#define     DEBUG_GENTOO_M         if (yURG_debug.gentoo             == 'Y')
#define     DEBUG_CACHE            if (yURG_debug.cache              != '-')
#define     DEBUG_CACHE_M          if (yURG_debug.cache              == 'Y')
/*---(dependencies)----------------------*/
#define     DEBUG_DEPS             if (yURG_debug.deps               != '-')
#define     DEBUG_DEPS_M           if (yURG_debug.deps               == 'Y')
/*---(cells)-----------------------------*/
#define     DEBUG_LOCS             if (yURG_debug.locs               != '-')
#define     DEBUG_LOCS_M           if (yURG_debug.locs               == 'Y')
#define     DEBUG_CELL             if (yURG_debug.cell               != '-')
#define     DEBUG_CELL_M           if (yURG_debug.cell               == 'Y')
/*---(formulas)--------------------------*/
#define     DEBUG_RPN              if (yURG_debug.rpn                != '-')
#define     DEBUG_RPN_M            if (yURG_debug.rpn                == 'Y')
#define     DEBUG_CALC             if (yURG_debug.calc               != '-')
#define     DEBUG_CALC_M           if (yURG_debug.calc               == 'Y')
#define     DEBUG_EXEC             if (yURG_debug.exec               != '-')
#define     DEBUG_EXEC_M           if (yURG_debug.exec               == 'Y')
#define     DEBUG_ADJS             if (yURG_debug.adjs               != '-')
#define     DEBUG_ADJS_M           if (yURG_debug.adjs               == 'Y')
/*---(yVIKEYS)---------------------------*/
#define     DEBUG_VISU             if (yURG_debug.visu               != '-')
#define     DEBUG_VISU_M           if (yURG_debug.visu               == 'Y')
#define     DEBUG_SSEL             if (yURG_debug.ssel               != '-')
#define     DEBUG_SSEL_M           if (yURG_debug.ssel               == 'Y')
#define     DEBUG_MARK             if (yURG_debug.mark               != '-')
#define     DEBUG_MARK_M           if (yURG_debug.mark               == 'Y')
#define     DEBUG_HINT             if (yURG_debug.hint               != '-')
#define     DEBUG_HINT_M           if (yURG_debug.hint               == 'Y')
#define     DEBUG_SRCH             if (yURG_debug.srch               != '-')
#define     DEBUG_SRCH_M           if (yURG_debug.srch               == 'Y')
#define     DEBUG_MAP              if (yURG_debug.map                != '-')
#define     DEBUG_MAP_M            if (yURG_debug.map                == 'Y')
#define     DEBUG_MODE             if (yURG_debug.mode               != '-')
#define     DEBUG_MODE_M           if (yURG_debug.mode               == 'Y')
#define     DEBUG_EDIT             if (yURG_debug.edit               != '-')
#define     DEBUG_EDIT_M           if (yURG_debug.edit               == 'Y')
/*---(registers)-------------------------*/
#define     DEBUG_REGS             if (yURG_debug.regs               != '-')
#define     DEBUG_REGS_M           if (yURG_debug.regs               == 'Y')
#define     DEBUG_TREG             if (yURG_debug.treg               != '-')
#define     DEBUG_TREG_M           if (yURG_debug.treg               == 'Y')
/*---(ySTR)------------------------------*/
#define     DEBUG_YLOGS            if (yURG_debug.ylogs              == 'y')
#define     DEBUG_YSTR             if (yURG_debug.ystr               != '-')
#define     DEBUG_YSTR_M           if (yURG_debug.ystr               == 'Y')
#define     DEBUG_YDLST            if (yURG_debug.ydlst              != '-')
#define     DEBUG_YDLST_M          if (yURG_debug.ydlst              == 'Y')
#define     DEBUG_YSCHED           if (yURG_debug.ysched             != '-')
#define     DEBUG_YSCHED_M         if (yURG_debug.ysched             == 'Y')
#define     DEBUG_YEXEC            if (yURG_debug.yexec              != '-')
#define     DEBUG_YEXEC_M          if (yURG_debug.yexec              == 'Y')
/*---(yPARSE)----------------------------*/
#define     DEBUG_YPARSE           if (yURG_debug.yparse             == 'y')
/*---(yGOLEM)----------------------------*/
#define     DEBUG_YGOLEM           if (yURG_debug.ygolem             == 'y')
/*---(yREGEX)----------------------------*/
#define     DEBUG_YREGEX           if (yURG_debug.yregex             != '-')
#define     DEBUG_YREGEX_M         if (yURG_debug.yregex             == 'Y')
/*---(kinematics)------------------------*/
#define     DEBUG_YKINE_CALC       if (yURG_debug.ykine_calc         != '-')
#define     DEBUG_YKINE_CALC_M     if (yURG_debug.ykine_calc         == 'Y')
#define     DEBUG_YKINE_DATA       if (yURG_debug.ykine_data         != '-')
#define     DEBUG_YKINE_DATA_M     if (yURG_debug.ykine_data         == 'Y')
#define     DEBUG_YKINE_SCRP       if (yURG_debug.ykine_scrp         != '-')
#define     DEBUG_YKINE_SCRP_M     if (yURG_debug.ykine_scrp         == 'Y')
/*---(vi-keys)---------------------------*/
#define     DEBUG_YVIKEYS          if (yURG_debug.yvikeys            == 'y')
#define     DEBUG_YVIKEYS_KEYS     if (yURG_debug.yvikeys_keys       != '-')
#define     DEBUG_YVIKEYS_KEYS_M   if (yURG_debug.yvikeys_keys       == 'Y')
#define     DEBUG_YVIKEYS_MODE     if (yURG_debug.yvikeys_mode       != '-')
#define     DEBUG_YVIKEYS_MODE_M   if (yURG_debug.yvikeys_mode       == 'Y')
#define     DEBUG_YVIKEYS_SCALE    if (yURG_debug.yvikeys_scale      != '-')
#define     DEBUG_YVIKEYS_SCALE_M  if (yURG_debug.yvikeys_scale      == 'Y')
/*---(yFONT)-----------------------------*/
#define     DEBUG_YFONT            if (yURG_debug.yfont              != '-')
#define     DEBUG_YFONT_M          if (yURG_debug.yfont              == 'Y')
#define     DEBUG_YFONT_FILE       if (yURG_debug.yfont_file         == 'y')
#define     DEBUG_YFONT_CALC       if (yURG_debug.yfont_calc         == 'y')
#define     DEBUG_YFONT_MAP        if (yURG_debug.yfont_map          == 'y')
/*---(yGLTEX)----------------------------*/
#define     DEBUG_YGLTEX           if (yURG_debug.ygltex             != '-')
#define     DEBUG_YGLTEX_M         if (yURG_debug.ygltex             == 'Y')
/*---(yCOLOR)----------------------------*/
#define     DEBUG_YCOLOR           if (yURG_debug.ycolor             != '-')
#define     DEBUG_YCOLOR_M         if (yURG_debug.ycolor             == 'Y')
/*---(yRPN)------------------------------*/
#define     DEBUG_YRPN             if (yURG_debug.yrpn               != '-')
#define     DEBUG_YRPN_M           if (yURG_debug.yrpn               == 'Y')
/*---(hyleoroi)--------------------------*/
#define     DEBUG_FORMAT           if (yURG_debug.format             != '-')
#define     DEBUG_FORMAT_M         if (yURG_debug.format             == 'Y')
#define     DEBUG_COLOR            if (yURG_debug.color              != '-')
#define     DEBUG_COLOR_M          if (yURG_debug.color              == 'Y')

typedef     const char         cchar;


char*       yURG_version       (void);
char        yURG_debugmode     (void);

char        yURG_logger        (int    a_argc, char *a_argv[]);
char        yURG_urgs          (int    a_argc, char *a_argv[]);
char        yURG_summ          (void);

char        yURG_list          (void);
char        yURG_abbr          (cchar  a_abbr, cchar a_on);
char        yURG_name          (cchar *a_name, cchar a_on);
char        yURG_mass          (cchar  a_set , cchar a_extra);

char        yURG_lognum        (void);



#endif
/*===[[ END ]]================================================================*/
