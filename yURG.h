/*===[[ START HDOC ]]=========================================================*/


/*===[[ HEADER GUARD ]]=======================================================*/
#ifndef YURG_HGUARD
#define YURG_HGUARD loaded



#define        LEN_LABEL        20
#define        LEN_DESC         80
#define        LEN_STR         200
#define        MAX_URGS        500

#define        YURG_ON         'y'
#define        YURG_OFF        '-'


typedef     struct   cURG_DEBUG       tURG_DEBUG;

/*===[[ DEBUGGING SETUP ]]====================================================*/
/* this is my latest standard format, vars, and urgents                       */
/* v3.0b : added signal handling                                (2014-feb-01) */
struct cURG_DEBUG
{
   /*---(handle)-------------------------*/
   int         logger;                 /* log file so that we don't close it  */
   int         mode;                   /* quiet '-' vs logging 'y'            */
   /*---(overall)------------------------*/  /* abcdefghi_kl__opq_stu__x__    */
   /* f = full urgents turns on all standard urgents                          */
   /* k = kitchen sink and turns everything, i mean everything on             */
   /* q = quiet turns all urgents off including the log itself                */
   char        tops;                   /* t) broad structure and context      */
   char        tops_mas;               /* t) broad structure and context      */
   char        summ;                   /* r) statistics and analytical output */
   char        summ_mas;               /* R) statistics and analytical output */
   char        verb;                   /* v) statistics and analytical output */
   char        verb_mas;               /* V) tracing on terminal output       */
   /*---(startup/shutdown)---------------*/
   char        args;                   /* a) command line args and urgents    */
   char        args_mas;               /* A) command line args and urgents    */
   char        conf;                   /* c) configuration handling           */
   char        conf_mas;               /* C) configuration handling           */
   char        prog;                   /* p) program setup and teardown       */
   char        prog_mas;               /* P) program setup and teardown       */
   /*---(file processing)----------------*/
   char        inpt;                   /* i) text and data file input         */
   char        inpt_mas;               /* I) text/data file input   (mas/more)*/
   char        outp;                   /* o) text and data file output        */
   char        outp_mas;               /* O) text/data file output  (mas/more)*/
   char        sqls;                   /* q) sql and database accesses        */
   char        sqls_mas;               /* Q) sql and database accesses        */
   /*---(event handling)-----------------*/
   char        loop;                   /* l) main program event loop          */
   char        loop_mas;               /* L) main program event loop          */
   char        user;                   /* u) user input and handling          */
   char        user_mas;               /* U) user input and handling          */
   char        apis;                   /* z) interprocess communication       */
   char        apis_mas;               /* Z) interprocess communication       */
   char        sign;                   /* x) os signal handling               */
   char        sign_mas;               /* X) os signal handling               */
   char        scrp;                   /* b) scripts and batch operations     */
   char        scrp_mas;               /* B) scripts and batch operations     */
   char        hist;                   /* h) history, undo, redo              */
   char        hist_mas;               /* H) history, undo, redo              */
   /*---(program)------------------------*/
   char        graf;                   /* g) grahpics, drawing, and display   */
   char        graf_mas;               /* G) grahpics, drawing, and display   */
   char        data;                   /* d) complex data structure handling  */
   char        data_mas;               /* D) complex data structure handling  */
   char        envi;                   /* e) environment processing           */
   char        envi_mas;               /* E) environment processing (mas/more)*/
   char        sort;                   /* s) data sorting and ordering        */
   char        sort_mas;               /* S) data sorting and ordering        */
   /*---(hermes)-------------------------*/
   char        dirs;                   /* hermes locations                    */
   char        dirs_mas;               /* hermes locations                    */
   char        pkgs;                   /* hermes packages                     */
   char        pkgs_mas;               /* hermes packages                     */
   char        cmds;                   /* hermes commands                     */
   char        cmds_mas;               /* hermes commands                     */
   char        gentoo;                 /* hermes gentoo/portage access        */
   char        gentoo_mas;             /* hermes gentoo/portage access        */
   char        cache;                  /* hermes cached database              */
   char        cache_mas;              /* hermes cached database              */
   /*---(spreadsheet)--------------------*/
   char        locs;
   char        locs_mas;
   char        cell;
   char        cell_mas;
   /*---(calculations)-------------------*/
   char        rpn;
   char        rpn_mas;
   char        calc;
   char        calc_mas;
   char        exec;
   char        exec_mas;
   /*---(dependencies)-------------------*/
   char        deps;
   char        deps_mas;
   /*---(selections)---------------------*/
   char        visu;                   /* gyges_visu : visual selection       */
   char        visu_mas;               /* gyges_visu : visual selection       */
   char        ssel;                   /* gyges_visu : source selection       */
   char        ssel_mas;               /* gyges_visu : source selection       */
   char        mark;                   /* gyges_visu : location/object marks  */
   char        mark_mas;               /* gyges_visu : location/object marks  */
   /*---(registers)----------------------*/
   char        regs;                   /* s_sel  : copy and paste registers   */
   char        regs_mas;               /* s_sel  : copy and paste registers   */
   /*---(other)--------------------------*/
   char        adjs;                   /* small, configurable adjustments     */
   char        adjs_mas;               /* small, configurable adjustments     */
   char        s;
   char        sylk;
   char        gnome;
   char        dtree;          /* displays the dependency tree and exits      */
   /*---(safe-strings)-------------------*/
   char        ystr;                   /* ySTR string library                 */
   char        ystr_mas;               /* ySTR string library                 */
   /*---(kinematics)---------------------*/
   char        ykine_calc;                  /* yKINE kinematics library            */
   char        ykine_calc_mas;              /* yKINE kinematics library            */
   char        ykine_data;                  /* yKINE kinematics library            */
   char        ykine_data_mas;              /* yKINE kinematics library            */
   char        ykine_scrp;                  /* yKINE kinematics library            */
   char        ykine_scrp_mas;              /* yKINE kinematics library            */
   /*---(vi-keys)------------------------*/
   char        yvikeys_keys;                /* yVIKEYS vi-keys library        */
   char        yvikeys_keys_mas;            /* yVIKEYS vi-keys library        */
   char        yvikeys_mode;                /* yVIKEYS vi-keys library        */
   char        yvikeys_mode_mas;            /* yVIKEYS vi-keys library        */
   char        yvikeys_scale;               /* yVIKEYS vi-keys library        */
   char        yvikeys_scale_mas;           /* yVIKEYS vi-keys library        */
   /*---(fonts)--------------------------*/
   char        yfont;                  /* yFONT texture mapped font library   */
   char        yfont_mas;              /* yFONT texture mapped font library   */
   char        yfont_file;             /* yFONT file creation and access      */
   char        yfont_calc;             /* yFONT layout and vertex calculation */
   char        yfont_map;              /* yFONT texture mapping and access    */
   /*---(textures)-----------------------*/
   char        ygltex;                 /* yFONT opengl texture handling       */
   char        ygltex_mas;             /* yFONT opengl texture handling       */
   /*---(colors)-------------------------*/
   char        ycolor;                 /* yFONT opengl color handling         */
   char        ycolor_mas;             /* yFONT opengl color handling         */
   /*---(hyleoroi)-----------------------*/
   char        format;                 /* formatting options                  */
   char        format_mas;             /* formatting options                  */
   char        color;                  /* color formatting options            */
   char        color_mas;              /* color formatting options            */
   /*---(done)---------------------------*/
};
extern    tURG_DEBUG      yURG_debug;



/*---(standard)--------------------------*/
#define     DEBUG_TOPS             if (yURG_debug.tops               == 'y')
#define     DEBUG_TOPS_M           if (yURG_debug.tops_mas           == 'y')
#define     DEBUG_SUMM             if (yURG_debug.summ               == 'y')
#define     DEBUG_SUMM_M           if (yURG_debug.summ_mas           == 'y')
#define     URG_VERB               if (yURG_debug.verb               == 'y')
#define     URG_VERB_M             if (yURG_debug.verb_mas           == 'y')
#define     DEBUG_ARGS             if (yURG_debug.args               == 'y')
#define     DEBUG_ARGS_M           if (yURG_debug.args_mas           == 'y')
#define     DEBUG_CONF             if (yURG_debug.conf               == 'y')
#define     DEBUG_CONF_M           if (yURG_debug.conf_mas           == 'y')
#define     DEBUG_PROG             if (yURG_debug.prog               == 'y')
#define     DEBUG_PROG_M           if (yURG_debug.prog_mas           == 'y')
#define     DEBUG_INPT             if (yURG_debug.inpt               == 'y')
#define     DEBUG_INPT_M           if (yURG_debug.inpt_mas           == 'y')
#define     DEBUG_OUTP             if (yURG_debug.outp               == 'y')
#define     DEBUG_OUTP_M           if (yURG_debug.outp_mas           == 'y')
#define     DEBUG_LOOP             if (yURG_debug.loop               == 'y')
#define     DEBUG_LOOP_M           if (yURG_debug.loop_mas           == 'y')
#define     DEBUG_USER             if (yURG_debug.user               == 'y')
#define     DEBUG_USER_M           if (yURG_debug.user_mas           == 'y')
#define     DEBUG_APIS             if (yURG_debug.apis               == 'y')
#define     DEBUG_APIS_M           if (yURG_debug.apis_mas           == 'y')
#define     DEBUG_SIGN             if (yURG_debug.sign               == 'y')
#define     DEBUG_SIGN_M           if (yURG_debug.sign_mas           == 'y')
#define     DEBUG_SCRP             if (yURG_debug.scrp               == 'y')
#define     DEBUG_SCRP_M           if (yURG_debug.scrp_mas           == 'y')
#define     DEBUG_HIST             if (yURG_debug.hist               == 'y')
#define     DEBUG_HIST_M           if (yURG_debug.hist_mas           == 'y')
#define     DEBUG_GRAF             if (yURG_debug.graf               == 'y')
#define     DEBUG_GRAF_M           if (yURG_debug.graf_mas           == 'y')
#define     DEBUG_DATA             if (yURG_debug.data               == 'y')
#define     DEBUG_DATA_M           if (yURG_debug.data_mas           == 'y')
#define     DEBUG_ENVI             if (yURG_debug.envi               == 'y')
#define     DEBUG_ENVI_M           if (yURG_debug.envi_mas           == 'y')
#define     DEBUG_SORT             if (yURG_debug.sort               == 'y')
#define     DEBUG_SORT_M           if (yURG_debug.sort_mas           == 'y')
/*---(hermes)----------------------------*/
#define     DEBUG_DIRS             if (yURG_debug.dirs               == 'y')
#define     DEBUG_DIRS_M           if (yURG_debug.dirs_mas           == 'y')
#define     DEBUG_PKGS             if (yURG_debug.pkgs               == 'y')
#define     DEBUG_PKGS_M           if (yURG_debug.pkgs_mas           == 'y')
#define     DEBUG_CMDS             if (yURG_debug.cmds               == 'y')
#define     DEBUG_CMDS_M           if (yURG_debug.cmds_mas           == 'y')
#define     DEBUG_GENTOO           if (yURG_debug.gentoo             == 'y')
#define     DEBUG_GENTOO_M         if (yURG_debug.gentoo_mas         == 'y')
#define     DEBUG_CACHE            if (yURG_debug.cache              == 'y')
#define     DEBUG_CACHE_M          if (yURG_debug.cache_mas          == 'y')
/*---(dependencies)----------------------*/
#define     DEBUG_DEPS             if (yURG_debug.deps               == 'y')
#define     DEBUG_DEPS_M           if (yURG_debug.deps_mas           == 'y')
/*---(cells)-----------------------------*/
#define     DEBUG_LOCS             if (yURG_debug.locs               == 'y')
#define     DEBUG_LOCS_M           if (yURG_debug.locs_mas           == 'y')
#define     DEBUG_CELL             if (yURG_debug.cell               == 'y')
#define     DEBUG_CELL_M           if (yURG_debug.cell_mas           == 'y')
/*---(formulas)--------------------------*/
#define     DEBUG_RPN              if (yURG_debug.rpn                == 'y')
#define     DEBUG_RPN_M            if (yURG_debug.rpn_mas            == 'y')
#define     DEBUG_CALC             if (yURG_debug.calc               == 'y')
#define     DEBUG_CALC_M           if (yURG_debug.calc_mas           == 'y')
#define     DEBUG_EXEC             if (yURG_debug.exec               == 'y')
#define     DEBUG_EXEC_M           if (yURG_debug.exec_mas           == 'y')
#define     DEBUG_ADJS             if (yURG_debug.adjs               == 'y')
#define     DEBUG_ADJS_M           if (yURG_debug.adjs_mas           == 'y')
/*---(visual)----------------------------*/
#define     DEBUG_VISU             if (yURG_debug.visu               == 'y')
#define     DEBUG_VISU_M           if (yURG_debug.visu_mas           == 'y')
#define     DEBUG_SSEL             if (yURG_debug.ssel               == 'y')
#define     DEBUG_SSEL_M           if (yURG_debug.ssel_mas           == 'y')
#define     DEBUG_MARK             if (yURG_debug.mark               == 'y')
#define     DEBUG_MARK_M           if (yURG_debug.mark_mas           == 'y')
/*---(registers)-------------------------*/
#define     DEBUG_REGS             if (yURG_debug.regs               == 'y')
#define     DEBUG_REGS_M           if (yURG_debug.regs_mas           == 'y')
/*---(ySTR)------------------------------*/
#define     DEBUG_YSTR             if (yURG_debug.ystr               == 'y')
#define     DEBUG_YSTR_M           if (yURG_debug.ystr_mas           == 'y')
/*---(kinematics)------------------------*/
#define     DEBUG_YKINE_CALC       if (yURG_debug.ykine_calc         == 'y')
#define     DEBUG_YKINE_CALC_M     if (yURG_debug.ykine_calc_mas     == 'y')
#define     DEBUG_YKINE_DATA       if (yURG_debug.ykine_data         == 'y')
#define     DEBUG_YKINE_DATA_M     if (yURG_debug.ykine_data_mas     == 'y')
#define     DEBUG_YKINE_SCRP       if (yURG_debug.ykine_scrp         == 'y')
#define     DEBUG_YKINE_SCRP_M     if (yURG_debug.ykine_scrp_mas     == 'y')
/*---(vi-keys)---------------------------*/
#define     DEBUG_YVIKEYS_KEYS     if (yURG_debug.yvikeys_keys       == 'y')
#define     DEBUG_YVIKEYS_KEYS_M   if (yURG_debug.yvikeys_keys_mas   == 'y')
#define     DEBUG_YVIKEYS_MODE     if (yURG_debug.yvikeys_mode       == 'y')
#define     DEBUG_YVIKEYS_MODE_M   if (yURG_debug.yvikeys_mode_mas   == 'y')
#define     DEBUG_YVIKEYS_SCALE    if (yURG_debug.yvikeys_scale      == 'y')
#define     DEBUG_YVIKEYS_SCALE_M  if (yURG_debug.yvikeys_scale_mas  == 'y')
/*---(yFONT)-----------------------------*/
#define     DEBUG_YFONT            if (yURG_debug.yfont              == 'y')
#define     DEBUG_YFONT_M          if (yURG_debug.yfont_mas          == 'y')
#define     DEBUG_YFONT_FILE       if (yURG_debug.yfont_file         == 'y')
#define     DEBUG_YFONT_CALC       if (yURG_debug.yfont_calc         == 'y')
#define     DEBUG_YFONT_MAP        if (yURG_debug.yfont_map          == 'y')
/*---(yGLTEX)----------------------------*/
#define     DEBUG_YGLTEX           if (yURG_debug.ygltex             == 'y')
#define     DEBUG_YGLTEX_M         if (yURG_debug.ygltex_mas         == 'y')
/*---(yCOLOR)----------------------------*/
#define     DEBUG_YCOLOR           if (yURG_debug.ycolor             == 'y')
#define     DEBUG_YCOLOR_M         if (yURG_debug.ycolor_mas         == 'y')
/*---(hyleoroi)--------------------------*/
#define     DEBUG_FORMAT           if (yURG_debug.format             == 'y')
#define     DEBUG_FORMAT_M         if (yURG_debug.format_mas         == 'y')
#define     DEBUG_COLOR            if (yURG_debug.color              == 'y')
#define     DEBUG_COLOR_M          if (yURG_debug.color              == 'y')

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




#endif
/*===[[ END ]]================================================================*/
