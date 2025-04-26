/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 15;        /* gaps between windows */
static const unsigned int snap      = 30;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh            = 38;        /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const int vertpad            = 15;       /* vertical padding of bar */
static const int sidepad            = 15;       /* horizontal padding of bar */
static const char *fonts[]          = { "Source Code Pro:style=Medium,Regular,Solid:size=12",
	"Hack Nerd Font:style=Regular:size=12",
	"Material Design Icons:style=Regular:size=12"};
static const char dmenufont[]       = "Source Code Pro:style=Medium:size=10";
static const char dmenulines[]      = "10";
static const char col_gray1[]       = "#1E1E2E";
static const char col_gray2[]       = "#14151d";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#cccccc";
static const char col_cat_gray[]    = "#CDD6F4";
static const char col_orange[]      = "#f2cdcd";
static const char col_cyan[]        = "#DDB6F2";
static const char col_dmenu[]       = "#a885dd";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
	[SchemeTags] = { col_gray2, col_gray1, col_gray2 },
	[SchemeLout] = { col_orange, col_gray1, col_gray2 },
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;

const char *spcmd1[] = {"st", "-n", "spterm_u", "-g", "71x20+163+162", NULL };
const char *spcmd2[] = {"st", "-n", "spfm", "-g", "144x41", "-e", "ranger", NULL };
const char *spcmd3[] = {"keepassxc", NULL };
const char *spcmd4[] = {"st", "-n", "scrcpy", "-g", "109x24", "-e", "scrcpy.sh", NULL };
const char *spcmd5[] = {"st", "-n", "spterm_w", "-g", "71x20+163+162", NULL };
const char *spcmd6[] = {"st", "-n", "spterm_gu", "-g", "71x20+163+162", "-e", "tss", "utils:general", NULL };
//const char *spcmd6[] = {"nitrogen", NULL };
const char *spcmd7[] = {"st", "-n", "spterm_clip", "-g", "71x20+150+162", "-e", "nvim", "+TZMinimalist", "notes/index.norg", NULL };

static Sp scratchpads[] = {
	/* name                   cmd  */
	{"spterm_u",             spcmd1},
	{"spranger",             spcmd2},
	{"keepassxc",            spcmd3},
	{"scrcpy",               spcmd4},
	{"spterm_w",             spcmd5},
	{"spterm_gu",            spcmd6},
	{"spterm_clip",          spcmd7},
};

static AttRule attrule[] = {

    /* comment() {
     *
     *     if (att_pos) {
     *         x_axis = gap from the closest edge parallel to x axis;
     *         y_axis = gap from the closest edge parallel to y axis;
     *         ie, if (att_pos == 5) {
     *                 x_axis = gap from top edge to window;
     *                 y_axis = gap from left edge to window;
     *             }
     *         if (you_are_confused) {
     *             see the diagram below;
     *             the closest edges are the ones closest to each number;
     *         }
     *     } else {
     *         x_axis = x co-ordinate of top left corner of window;
     *         y_axis = y co-ordinate of top left corner of window;
     *     }
     *
     *     if (att_pos == any of the edges) {
     *     begining:
     *         if (you_are_lazy)
     *             x_axis = y_axis = the gap you want;
     *         else {
     *             you_are_lazy = 1;
     *             goto begining;
     *         }
     *     }
     *
     *     if (att_pos = 9)
     *         x_axis and y_axis will be ignored;
     *
     *     if (ispinned)
     *         dwm won't let you move it;
     *
     *     if (ismoulded)
     *         dwm won't let you resize it;
     *
     *     if (stickall)
     *         ispinned and ismoulded will be ignored
     * }                                            +---------------------+
     *                                              | 1        2        3 |
     * 1 -> Top Edge      5 -> Top-Left Corner      |                     |
     * 2 -> Bottom Edge   6 -> Bottom-Right Corner  | 8        9        4 |
     * 3 -> Right Edge    7 -> Top-Right Corner     |                     |
     * 4 -> Left Edge     8 -> Bottom-Left Corner   | 7        6        5 |
     *                                              +---------------------+
     * */
   /* att_pos  x_axis  y_axis  width  height  ispinned  ismoulded  ressizehint  stickall  linked */
	{ 3,       30,      30,      650,   410,    1,        0,         1,           1,        NULL },
};


/* attached window toggle animation */
static const int jumplen = 4; /* actually its the distance */
static const int bouncelen = 1;
static const int bouncerange = 30;

/* tagging */
static const char *tags[] = { "󰟡", "󰐤", "󰈹", "󰨆", "󰌲", "󰇮", "󰈚" };

/* monocle mode layouts icons for <=10 */
static const char *monocle_layout[] = { "󰎤", "󰎧", "󰎪", "󰎭", "󰎱", "󰎳", "󰎶", "󰎹", "󰎼", "󰽽", "󰞋" };
//󰎤󰎧󰎪󰎭󰎱󰎳󰎶󰎹󰎼󰽽

/* os */
//static const char *os_icon[] = { "󰕈" };

static const char *tagsel[][2] = {
	{ "#F28FAD", "#1E1E2E" },
	{ "#F5C2E7", "#1E1E2E" },
	{ "#FAE3B0", "#1E1E2E" },
	{ "#ABE9B3", "#1E1E2E" },
	{ "#96CDFB", "#1E1E2E" },
	{ "#89DCEB", "#1E1E2E" },
	{ "#DDB6F2", "#1E1E2E" },
	{ "#F8BD96", "#1E1E2E" },
	{ "#B5E8E0", "#1E1E2E" },
};

static const unsigned int ulinepad = 3;     /* horizontal padding between the underline and tag */
static const unsigned int ulinestroke = 2;  /* thickness / height of the underline */
static const unsigned int ulinevoffset = 0; /* how far above the bottom of the bar the line should appear */
static const int ulineall = 0;              /* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class           instance          title           tags mask  isfloating  isterminal  noswallow  monitor   attach_rule */
	{ "Gimp",          NULL,             NULL,           0,         0,          0,           0,         -1,      NULL },
	{ "qutebrowser",   "qutebrowser",    NULL,           1 << 2,    0,          0,           1,         -1,      NULL },
	{ "st-256color",   "main_terminal",  NULL,           1 << 0,    0,          0,           1,         -1,      NULL },
	{ "st-256color",   NULL,             NULL,           0,         0,          1,           0,         -1,      NULL },
	{ NULL,            NULL,             "Event Tester", 0,         0,          0,           1,         -1,      NULL }, /* xev */
	{ "st-256color",   "spterm_u",       NULL,           SPTAG(0),  1,          1,           0,         -1,      NULL },
	{ NULL,            "spfm",           NULL,           SPTAG(1),  1,          0,           0,         -1,      NULL },
	{ NULL,            "keepassxc",      NULL,           SPTAG(2),  0,          0,           0,         -1,      NULL },
	{ "st-256color",   "scrcpy",         NULL,           SPTAG(3),  1,          1,           0,         -1,      NULL },
	{ "st-256color",   "spterm_w",       NULL,           SPTAG(4),  1,          1,           0,         -1,      NULL },
	{ "st-256color",   "spterm_gu",      NULL,           SPTAG(5),  1,          1,           0,         -1,      &attrule[0] },
	{ "st-256color",   "spterm_clip",    NULL,           SPTAG(6),  1,          1,           0,         -1,      &attrule[0] },

};

/* layout(s) */
static const float mfact     = 0.60; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "󱕍",      tile },    /* first entry is default */
	{ "󰇟",      NULL },    /* no layout function means floating behavior */
	{ "󰄮",      monocle },
};

/* 󱔓 tiled dock
 19 󱂬 float
 18 󱅶 tile
 17 󰄮 tile
    󰄮
 16 󰄱 tile
 15 󰟈 fib
 14 󰣆 tile
 13 󰘔 tile
 12 󰾢 spiral
 11 󰿠 hikn
 10 󰥟 lamp
  9 󰟁 dip switch
  8 󰂵 blur
  7 󰩁 dlna
  6 󰇟 draw
  5 󱉟 bookshelf
  4 󰮐 drag
  3 󰈀 ethernet
  2 󰑨 rotate
  1 󰢰 inbox
104 󰚗 djdj
*/

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, "-c", "-i", "-l", dmenulines, "-sf", col_gray1, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *dmenuterm[]  = { "dmenuterm", NULL };


static Key keys[] = {
	/* modifier                     key           function               argument */
	{ MODKEY,                       XK_p,         spawn,                 {.v = dmenucmd }    },
	{ MODKEY,                       XK_8,         spawn,                 {.v = termcmd }     },
	{ MODKEY|ShiftMask,             XK_c,         spawn,                 {.v = dmenuterm }   },
	{ MODKEY,                       XK_n,         togglebar,             {0}                 },
	{ MODKEY,                       XK_j,         focusstack,            {.i = +1 }          },
	{ MODKEY,                       XK_k,         focusstack,            {.i = -1 }          },
	{ MODKEY,                       XK_i,         incnmaster,            {.i = +1 }          },
	{ MODKEY,                       XK_d,         incnmaster,            {.i = -1 }          },
	{ MODKEY,                       XK_h,         setmfact,              {.f = -0.05}        },
	{ MODKEY,                       XK_l,         setmfact,              {.f = +0.05}        },
	{ MODKEY,                       XK_space,     zoom,                  {0}                 },
	{ MODKEY,                       XK_Tab,       view,                  {0}                 },
	{ MODKEY|ShiftMask,             XK_q,         killclient,            {0}                 },
	{ MODKEY,                       XK_t,         setlayout,             {.v = &layouts[0]}  },
	{ MODKEY|ShiftMask,             XK_f,         setlayout,             {.v = &layouts[1]}  },
	{ MODKEY,                       XK_m,         setlayout,             {.v = &layouts[2]}  },
	{ MODKEY|ShiftMask,             XK_Return,    setlayout,             {0}                 },
	{ MODKEY|ShiftMask,             XK_space,     togglefloating,        {0}                 },
	{ MODKEY,                       XK_f,         togglefullscr,         {0}                 },
	{ MODKEY,                       XK_0,         view,                  {.ui = ~0 }         },
	{ MODKEY|ShiftMask,             XK_0,         tag,                   {.ui = ~0 }         },
	{ MODKEY,                       XK_comma,     focusmon,              {.i = -1 }          },
	{ MODKEY,                       XK_period,    focusmon,              {.i = +1 }          },
	{ MODKEY|ShiftMask,             XK_comma,     tagmon,                {.i = -1 }          },
	{ MODKEY|ShiftMask,             XK_period,    tagmon,                {.i = +1 }          },
	{ MODKEY,                       XK_u,         focusortogglescratch,  {.ui = 0 }          },
	// { MODKEY,                       XK_w,         focusortogglescratch,  {.ui = 4 }          },
	{ MODKEY,                       XK_semicolon, focusortogglescratch,  {.ui = 5 }          },
	{ MODKEY,                       XK_o,         focusortogglescratch,  {.ui = 6 }          },
	// { MODKEY,                       XK_u,         focusortogglescratch,  {.ui = 1 }          },
	{ MODKEY,                       XK_x,         focusortogglescratch,  {.ui = 2 }          },
	{ MODKEY|ShiftMask,             XK_e,         focusortogglescratch,  {.ui = 3 }          },
	{ MODKEY|ShiftMask,             XK_h,         toggleattach,          {.i = 1 }           },
	{ MODKEY|ShiftMask,             XK_j,         toggleattach,          {.i = 2 }           },
	{ MODKEY|ShiftMask,             XK_k,         toggleattach,          {.i = 3 }           },
	{ MODKEY|ShiftMask,             XK_l,         toggleattach,          {.i = 4 }           },
    /* MOD + Return will take to the first tag, where the main terminal will always be */
	TAGKEYS(                        XK_Return,                 0)
	TAGKEYS(                        XK_1,                      0)

    /* MOD + w will take to the second tag */
	TAGKEYS(                        XK_w,                      1)
	TAGKEYS(                        XK_2,                      1)

    /* MOD + b will take to the third tag, where the browser will always be */
	TAGKEYS(                        XK_b,                      2)
	TAGKEYS(                        XK_3,                      2)

	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	{ MODKEY|ShiftMask|ControlMask, XK_x,         quit,                  {0}                 },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
