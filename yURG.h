/*===[[ HEADER GUARD ]]=======================================================*/
#ifndef YURG_HGUARD
#define YURG_HGUARD loaded



#define        YURG_OFF        '-'
#define        YURG_ON         'y'
#define        YURG_MAS        'Y'

#define        YURG_MSG        "/tmp/console.txt"
#define        YURG_LEVEL0     '>'
#define        YURG_LEVEL1     '-'
#define        YURG_LEVEL2     '+'
#define        YURG_ERR        "/tmp/errors.txt"
#define        YURG_FATAL0     'F'
#define        YURG_FATAL1     'f'
#define        YURG_FATAL2     'ü'
#define        YURG_WARN0      'W'
#define        YURG_WARN1      'w'
#define        YURG_WARN2      'ÿ'


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
   /*---(overall)------------------------*/  /* abcde_ghi__lmnopqrstuvwxyz    */
   /* f = full urgents turns on all standard urgents                          */
   /* k = kitchen sink and turns everything on, i mean everything on          */
   /* q = quiet turns all urgents off including the log itself                */
   char        tops;                   /* t) broad structure and context      */
   char        rptg;                   /* r) report/dump, analytics, stats    */
   char        view;                   /* v) view direct to stdout            */
   /*---(startup/shutdown)---------------*/
   char        args;                   /* a) command line args and urgents    */
   char        conf;                   /* c) configuration handling           */
   char        prog;                   /* p) specific program setup/wrapup    */
   /*---(file processing)----------------*/
   char        inpt;                   /* i) text and data file input         */
   char        outp;                   /* o) text and data file output        */
   char        sqls;                   /* q) sql and database accesses        */
   /*---(event handling)-----------------*/
   char        loop;                   /* l) main program event loop          */
   char        norm;                   /* n) normal execution (catch-all)     */
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
   char        trav;                   /* y) data searching and traversal     */
   char        mems;                   /* m) memory, registers, storing       */
   /*---(stages)-------------------------*/
   char        stage    [20];          /* stages for active logging           */
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
   char        ystr;                   /* ySTR string library                 */
   char        ydlst;                  /* yDLST quad-double linked list       */
   char        ysched;                 /* ySCHED kernighan sched grammar      */
   char        yexec;                  /* yEXEC process dispatch and control  */
   char        ysec;                   /* ySEC system access logging          */
   /*---(record parsing)-----------------*/
   char        yparse;                 /* yPARSE parsing to queue libarary    */
   /*---(robotics)-----------------------*/
   char        ygolem;                 /* yGOLEM robotics controller          */
   /*---(regular expressions)------------*/
   char        yregex;                 /* yREGEX library                      */
   /*---(windows)------------------------*/
   char        desk;                   /* desktop/window control              */
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
   /*---(done)---------------------------*/
};
extern    tURG_DEBUG      myURG;



/*---(silent)-----------------*/
#define     NOT_DEBUG              if (myURG.use                == '-')
/*---(overall)----------------*/
#define     DEBUG_TOPS             if (myURG.tops               != '-')
#define     DEBUG_TOPS_M           if (myURG.tops               == 'Y')
#define     DEBUG_RPTG             if (myURG.rptg               != '-')
#define     DEBUG_RPTG_M           if (myURG.rptg               == 'Y')
#define     DEBUG_VIEW             if (myURG.view               != '-')
#define     DEBUG_VIEW_M           if (myURG.view               == 'Y')
/*---(startup/shutdown)-------*/
#define     DEBUG_ARGS             if (myURG.args               != '-')
#define     DEBUG_ARGS_M           if (myURG.args               == 'Y')
#define     DEBUG_CONF             if (myURG.conf               != '-')
#define     DEBUG_CONF_M           if (myURG.conf               == 'Y')
#define     DEBUG_PROG             if (myURG.prog               != '-')
#define     DEBUG_PROG_M           if (myURG.prog               == 'Y')
/*---(file/pipe)--------------*/
#define     DEBUG_INPT             if (myURG.inpt               != '-')
#define     DEBUG_INPT_M           if (myURG.inpt               == 'Y')
#define     DEBUG_OUTP             if (myURG.outp               != '-')
#define     DEBUG_OUTP_M           if (myURG.outp               == 'Y')
#define     DEBUG_FILE             if (myURG.inpt != '-' && myURG.outp != '-')
#define     DEBUG_FILE_M           if (myURG.inpt == 'Y' || myURG.outp == 'Y')
/*---(event handling)---------*/
#define     DEBUG_LOOP             if (myURG.loop               != '-')
#define     DEBUG_LOOP_M           if (myURG.loop               == 'Y')
#define     DEBUG_NORM             if (myURG.norm               != '-')
#define     DEBUG_NORM_M           if (myURG.norm               == 'Y')
#define     DEBUG_USER             if (myURG.user               != '-')
#define     DEBUG_USER_M           if (myURG.user               == 'Y')
#define     DEBUG_APIS             if (myURG.apis               != '-')
#define     DEBUG_APIS_M           if (myURG.apis               == 'Y')
#define     DEBUG_SIGN             if (myURG.sign               != '-')
#define     DEBUG_SIGN_M           if (myURG.sign               == 'Y')
#define     DEBUG_SCRP             if (myURG.scrp               != '-')
#define     DEBUG_SCRP_M           if (myURG.scrp               == 'Y')
#define     DEBUG_HIST             if (myURG.hist               != '-')
#define     DEBUG_HIST_M           if (myURG.hist               == 'Y')
/*---(program)----------------*/
#define     DEBUG_GRAF             if (myURG.graf               != '-')
#define     DEBUG_GRAF_M           if (myURG.graf               == 'Y')
#define     DEBUG_WIND             if (myURG.wind               != '-')
#define     DEBUG_WIND_M           if (myURG.wind               == 'Y')
#define     DEBUG_DATA             if (myURG.data               != '-')
#define     DEBUG_DATA_M           if (myURG.data               == 'Y')
#define     DEBUG_ENVI             if (myURG.envi               != '-')
#define     DEBUG_ENVI_M           if (myURG.envi               == 'Y')
#define     DEBUG_SORT             if (myURG.sort               != '-')
#define     DEBUG_SORT_M           if (myURG.sort               == 'Y')
#define     DEBUG_TRAV             if (myURG.trav               != '-')
#define     DEBUG_TRAV_M           if (myURG.trav               == 'Y')
#define     DEBUG_MEMS             if (myURG.mems               != '-')
#define     DEBUG_MEMS_M           if (myURG.mems               == 'Y')
/*---(gregg)-----------------------------*/
#define     DEBUG_TOUCH            if (myURG.touch              != '-')
#define     DEBUG_TOUCH_M          if (myURG.touch              == 'Y')
#define     DEBUG_RAW              if (myURG.raw                != '-')
#define     DEBUG_RAW_M            if (myURG.raw                == 'Y')
#define     DEBUG_SIMP             if (myURG.simple             != '-')
#define     DEBUG_SIMP_M           if (myURG.simple             == 'Y')
#define     DEBUG_AVG              if (myURG.average            != '-')
#define     DEBUG_AVG_M            if (myURG.average            == 'Y')
#define     DEBUG_CRIT             if (myURG.critical           != '-')
#define     DEBUG_CRIT_M           if (myURG.critical           == 'Y')
#define     DEBUG_CIRC             if (myURG.circle             != '-')
#define     DEBUG_CIRC_M           if (myURG.circle             == 'Y')
#define     DEBUG_CURV             if (myURG.curve              != '-')
#define     DEBUG_CURV_M           if (myURG.curve              == 'Y')
#define     DEBUG_LINE             if (myURG.line               != '-')
#define     DEBUG_LINE_M           if (myURG.line               == 'Y')
#define     DEBUG_MATCH            if (myURG.match              != '-')
#define     DEBUG_MATCH_M          if (myURG.match              == 'Y')
#define     DEBUG_DICT             if (myURG.dict               != '-')
#define     DEBUG_DICT_M           if (myURG.dict               == 'Y')
/*---(stages)----------------------------*/
#define     YURG_STAGE_INIT        0
#define     YURG_STAGE_INPT        1
#define     YURG_STAGE_MAIN        2
#define     YURG_STAGE_OUTP        3
#define     YURG_STAGE_WRAP        4
#define     YURG_STAGE_ONE         6
#define     YURG_STAGE_TWO         7
#define     YURG_STAGE_THR         8
#define     YURG_STAGE_FOU         9
#define     YURG_STAGE_FIV         10
/*---(hermes)----------------------------*/
#define     DEBUG_DIRS             if (myURG.dirs               != '-')
#define     DEBUG_DIRS_M           if (myURG.dirs               == 'Y')
#define     DEBUG_PKGS             if (myURG.pkgs               != '-')
#define     DEBUG_PKGS_M           if (myURG.pkgs               == 'Y')
#define     DEBUG_CMDS             if (myURG.cmds               != '-')
#define     DEBUG_CMDS_M           if (myURG.cmds               == 'Y')
#define     DEBUG_GENTOO           if (myURG.gentoo             != '-')
#define     DEBUG_GENTOO_M         if (myURG.gentoo             == 'Y')
#define     DEBUG_CACHE            if (myURG.cache              != '-')
#define     DEBUG_CACHE_M          if (myURG.cache              == 'Y')
/*---(graph/helios)----------------------*/
#define     DEBUG_MASS             if (myURG.mass               != '-')
#define     DEBUG_MASS_M           if (myURG.mass               == 'Y')
#define     DEBUG_NODE             if (myURG.node               != '-')
#define     DEBUG_NODE_M           if (myURG.node               == 'Y')
#define     DEBUG_EDGE             if (myURG.edge               != '-')
#define     DEBUG_EDGE_M           if (myURG.edge               == 'Y')
#define     DEBUG_STATS            if (myURG.stats              != '-')
#define     DEBUG_STATS_M          if (myURG.stats              == 'Y')
/*---(dependencies)----------------------*/
#define     DEBUG_DEPS             if (myURG.deps               != '-')
#define     DEBUG_DEPS_M           if (myURG.deps               == 'Y')
/*---(cells)-----------------------------*/
#define     DEBUG_LOCS             if (myURG.locs               != '-')
#define     DEBUG_LOCS_M           if (myURG.locs               == 'Y')
#define     DEBUG_CELL             if (myURG.cell               != '-')
#define     DEBUG_CELL_M           if (myURG.cell               == 'Y')
/*---(formulas)--------------------------*/
#define     DEBUG_RPN              if (myURG.rpn                != '-')
#define     DEBUG_RPN_M            if (myURG.rpn                == 'Y')
#define     DEBUG_CALC             if (myURG.calc               != '-')
#define     DEBUG_CALC_M           if (myURG.calc               == 'Y')
#define     DEBUG_EXEC             if (myURG.exec               != '-')
#define     DEBUG_EXEC_M           if (myURG.exec               == 'Y')
#define     DEBUG_ADJS             if (myURG.adjs               != '-')
#define     DEBUG_ADJS_M           if (myURG.adjs               == 'Y')
/*---(yVIKEYS)---------------------------*/
#define     DEBUG_VISU             if (myURG.visu               != '-')
#define     DEBUG_VISU_M           if (myURG.visu               == 'Y')
#define     DEBUG_SSEL             if (myURG.ssel               != '-')
#define     DEBUG_SSEL_M           if (myURG.ssel               == 'Y')
#define     DEBUG_MARK             if (myURG.mark               != '-')
#define     DEBUG_MARK_M           if (myURG.mark               == 'Y')
#define     DEBUG_HINT             if (myURG.hint               != '-')
#define     DEBUG_HINT_M           if (myURG.hint               == 'Y')
#define     DEBUG_SRCH             if (myURG.srch               != '-')
#define     DEBUG_SRCH_M           if (myURG.srch               == 'Y')
#define     DEBUG_MAP              if (myURG.map                != '-')
#define     DEBUG_MAP_M            if (myURG.map                == 'Y')
#define     DEBUG_MODE             if (myURG.mode               != '-')
#define     DEBUG_MODE_M           if (myURG.mode               == 'Y')
#define     DEBUG_EDIT             if (myURG.edit               != '-')
#define     DEBUG_EDIT_M           if (myURG.edit               == 'Y')
/*---(registers)-------------------------*/
#define     DEBUG_REGS             if (myURG.regs               != '-')
#define     DEBUG_REGS_M           if (myURG.regs               == 'Y')
#define     DEBUG_TREG             if (myURG.treg               != '-')
#define     DEBUG_TREG_M           if (myURG.treg               == 'Y')
/*---(ySTR)------------------------------*/
#define     DEBUG_YSTR             if (myURG.ystr               != '-')
#define     DEBUG_YSTR_M           if (myURG.ystr               == 'Y')
#define     DEBUG_YDLST            if (myURG.ydlst              != '-')
#define     DEBUG_YDLST_M          if (myURG.ydlst              == 'Y')
#define     DEBUG_YSCHED           if (myURG.ysched             != '-')
#define     DEBUG_YSCHED_M         if (myURG.ysched             == 'Y')
#define     DEBUG_YEXEC            if (myURG.yexec              != '-')
#define     DEBUG_YEXEC_M          if (myURG.yexec              == 'Y')
#define     DEBUG_YSEC             if (myURG.ysec               != '-')
#define     DEBUG_YSEC_M           if (myURG.ysec               == 'Y')
/*---(yPARSE)----------------------------*/
#define     DEBUG_YPARSE           if (myURG.yparse             == 'y')
/*---(yGOLEM)----------------------------*/
#define     DEBUG_YGOLEM           if (myURG.ygolem             == 'y')
/*---(yREGEX)----------------------------*/
#define     DEBUG_YREGEX           if (myURG.yregex             != '-')
#define     DEBUG_YREGEX_M         if (myURG.yregex             == 'Y')
/*---(windows)---------------------------*/
#define     DEBUG_DESK             if (myURG.desk               != '-')
#define     DEBUG_DESK_M           if (myURG.desk               != 'Y')
/*---(kinematics)------------------------*/
#define     DEBUG_YKINE            if (myURG.ykine              != '-')
#define     DEBUG_YKINE_M          if (myURG.ykine              == 'Y')
#define     DEBUG_YKINE_CALC       if (myURG.ykine_calc         != '-')
#define     DEBUG_YKINE_TICK       if (myURG.ykine_tick         != '-')
#define     DEBUG_YKINE_MOVE       if (myURG.ykine_move         != '-')
#define     DEBUG_YKINE_DATA       if (myURG.ykine_data         != '-')
#define     DEBUG_YKINE_SCRP       if (myURG.ykine_scrp         != '-')
#define     DEBUG_YKINE_EXACT      if (myURG.ykine_exact        != '-')
/*---(vi-keys)---------------------------*/
#define     DEBUG_YVIKEYS          if (myURG.yvikeys            == 'y')
#define     DEBUG_YVIKEYS_KEYS     if (myURG.yvikeys_keys       != '-')
#define     DEBUG_YVIKEYS_KEYS_M   if (myURG.yvikeys_keys       == 'Y')
#define     DEBUG_YVIKEYS_MODE     if (myURG.yvikeys_mode       != '-')
#define     DEBUG_YVIKEYS_MODE_M   if (myURG.yvikeys_mode       == 'Y')
#define     DEBUG_YVIKEYS_SCALE    if (myURG.yvikeys_scale      != '-')
#define     DEBUG_YVIKEYS_SCALE_M  if (myURG.yvikeys_scale      == 'Y')
/*---(yFONT)-----------------------------*/
#define     DEBUG_YFONT            if (myURG.yfont              != '-')
#define     DEBUG_YFONT_M          if (myURG.yfont              == 'Y')
#define     DEBUG_YFONT_FILE       if (myURG.yfont_file         == 'y')
#define     DEBUG_YFONT_CALC       if (myURG.yfont_calc         == 'y')
#define     DEBUG_YFONT_MAP        if (myURG.yfont_map          == 'y')
/*---(yGLTEX)----------------------------*/
#define     DEBUG_YGLTEX           if (myURG.ygltex             != '-')
#define     DEBUG_YGLTEX_M         if (myURG.ygltex             == 'Y')
/*---(yCOLOR)----------------------------*/
#define     DEBUG_YCOLOR           if (myURG.ycolor             != '-')
#define     DEBUG_YCOLOR_M         if (myURG.ycolor             == 'Y')
/*---(hyleoroi)--------------------------*/
#define     DEBUG_FORMAT           if (myURG.format             != '-')
#define     DEBUG_FORMAT_M         if (myURG.format             == 'Y')
#define     DEBUG_COLOR            if (myURG.color              != '-')
#define     DEBUG_COLOR_M          if (myURG.color              == 'Y')


typedef     const char         cchar;


char*       yURG_version            (void);
char        yURG_debugmode          (void);

char        yURG_orig               (char *a_orig);
char        yURG_curr               (char *a_curr);

char        yURG_mass               (cchar  a_set , cchar a_extra);
char        yURG_logger             (int    a_argc, char *a_argv[]);
char        yURG_urgs               (int    a_argc, char *a_argv[]);

char        yURG_summ               (void);
char        yURG_list               (void);

char        yURG_abbr               (cchar  a_abbr, cchar a_on);
char        yURG_name               (cchar *a_name, cchar a_on);

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
char*       yURG_mute_status        (void);

int         yURG_peek               (cchar *a_name, int n, char *a_recd);
char        yURG_touch              (cchar *a_file, cchar *a_own, cchar *a_grp, cchar *a_perms);
char        yURG_rm                 (cchar *a_file);
char        yURG_mkdir              (cchar *a_dir, cchar *a_own, cchar *a_grp, cchar *a_perms);
char        yURG_rmdir              (cchar *a_dir);


#endif
/*===[[ END ]]================================================================*/
