/*
 * ██████╗ ██╗    ██╗███╗   ███╗
 * ██╔══██╗██║    ██║████╗ ████║
 * ██║  ██║██║ █╗ ██║██╔████╔██║
 * ██║  ██║██║███╗██║██║╚██╔╝██║
 * ██████╔╝╚███╔███╔╝██║ ╚═╝ ██║
 * ╚═════╝  ╚══╝╚══╝ ╚═╝     ╚═╝
*/ 

/* appearance */
static const unsigned int borderpx  = 3;  /* border pixel of windows */
static const unsigned int snap      = 15; /* snap pixel */
static const int swallowfloating    = 0;  /* 1 means swallow floating windows by default */
static const Gap default_gap        = {.isgap = 1, .realgap = 15, .gappx = 20};
static const int showbar            = 1;  /* 0 means no bar */
static const int topbar             = 1;  /* 0 means bottom bar */
static const int barheight          = 32;

/* colors */
static const char fgnorm[]             = "#5c6370";
static const char fgsel[]              = "#31343f";
//static const char bgnorm[]             = "#262b32";
static const char bgnorm[]             = "#000000";
//static const char bgsel[]              = "#56b6c2";
static const char bgsel[]              = "#5c6370";
static const char bdnorm[]             = "#262b32";
//static const char bdsel[]              = "#56b6c2";
static const char bdsel[]              = "#5c6370";
static const unsigned int fgalphanorm  = OPAQUE;
static const unsigned int fgalphasel   = OPAQUE;
//static const unsigned int bgalphanorm  = OPAQUE;
static const unsigned int bgalphanorm  = 0x33;
static const unsigned int bgalphasel   = OPAQUE;
static const unsigned int bdalphanorm  = OPAQUE;
static const unsigned int bdalphasel   = OPAQUE;

static const char *colors[][3] = {
    /*               fg      bg      border   */
	[SchemeNorm] = { fgnorm, bgnorm, bdnorm },
	[SchemeSel]  = { fgsel,  bgsel,  bdsel  },
};

static const unsigned int alphas[][3] = {
	/*               fg           bg           border  */
	[SchemeNorm] = { fgalphanorm, bgalphanorm, bdalphanorm },
	[SchemeSel]  = { fgalphasel,  bgalphasel,  bdalphasel  },
};

/* fonts */
//static const char *fonts[]    = { "mononoki Nerd Font:size=14", "monospace:size=14" };
static const char *fonts[]    = { "JetBrains Mono Nerd Font:size=14", "monospace:size=13" };
//static const char dmenufont[] = "mononoki Nerd Font:size=14";
static const char dmenufont[] = "JetBrains Mono Nerd Font:size=14";

/* tagging */
// static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const char *tags[] = { "1", "2", "3", "4", "5" };
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class       instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
	{ "Alacritty", NULL,     NULL,           0,         0,          1,           0,        -1 },
	{ "lplan",     NULL,     NULL,           0,         1,          0,           0,        -1 },
	{ "todo",      NULL,     NULL,           0,         1,          1,           0,        -1 },
	{ NULL,        NULL,     "Event Tester", 0,         0,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact        = 0.5;  /* factor of master area size [0.05..0.95] */
static const int nmaster        = 1;    /* number of clients in master area */
static const int resizehints    = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1;    /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile    }, /* first entry is default */
	{ "[]_",      bstack  },  /* tile with slaves at the bottom */
	{ "><>",      NULL    }, /* no layout function means floating behavior */
	{ "[F]",      monocle }, /* basically a fullscreen layout */
};

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
static const char *dmenucmd[]   = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", bgnorm, "-nf", fgnorm, "-sb", bgsel, "-sf", fgsel, NULL };
static const char *roficmd[]    = { "rofi", "-show", "drun", "-display-drun", "Search", "-show-icons", "-scroll-method", "1", NULL };
static const char *termcmd[]    = { "alacritty", NULL };
static const char *rangercmd[]  = { "alacritty", "-e", "ranger", NULL };
static const char *btopcmd[]    = { "alacritty", "-e", "btop", NULL };
static const char *viscmd[]     = { "alacritty", "-e", "vis", NULL };
static const char *todocmd[]    = { "alacritty", "--class", "todo", "-e", "glow", "/home/kasetonix/todo.md", "-p", NULL };
static const char *lplancmd[]   = { "feh", "-xZN", "--geometry", "1000x682", "--class", "lplan", /*"--zoom", "75%",*/ "--image-bg", "'#ffffff'", "/home/kasetonix/pics/lplan-current.png", NULL };
static const char *scrotcmd[]   = { "scrot", "scrot-%H.%M.%S.png", "-s", "-p", "-l", "width=2,color=#56b6c2,opacity=0,mode=edge;", "mv", "/home/kasetonix/scrot*", "/home/kasetonix/pics/screens", NULL };
static const char *altwallcmd[] = { "feh", "--bg-fill", "/home/kasetonix/pics/walls/altwall", "--no-fehbg", NULL };
static const char *defwallcmd[] = { "feh", "--bg-fill", "/home/kasetonix/pics/walls/defwall", "--no-fehbg", NULL };
static const char *jpvidscmd[]  = { "alacritty", "-e", "ranger", "/home/kasetonix/vids/jp", NULL };
static const char *poweroff[]   = { "poweroff", NULL };
static const char *reboot[]     = { "reboot", NULL };
static const char *restart[]    = { "/home/kasetonix/.dwm/autostart.sh", NULL };

/* media keys */
#include <X11/XF86keysym.h>
static const char *volr[]  = { "pactl", "set-sink-volume", "@DEFAULT_SINK@", "+5%", NULL };
static const char *voll[]  = { "pactl", "set-sink-volume", "@DEFAULT_SINK@", "-5%", NULL };
static const char *volm[]  = { "pactl", "set-sink-mute", "@DEFAULT_SINK@", "toggle", NULL };
static const char *brir[]  = { "brightnessctl", "-d", "intel_backlight", "set", "+5%", NULL };
static const char *bril[]  = { "brightnessctl", "-d", "intel_backlight", "set", "5%-", NULL };

static Key keys[] = {
	/* modifier            key        function        argument */
	{ MODKEY,              XK_e,      spawn,          {.v = roficmd } },
	{ MODKEY,              XK_slash,  spawn,          {.v = roficmd } },
	{ MODKEY,              XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,              XK_r,      spawn,          {.v = rangercmd } },
	{ MODKEY,              XK_Escape, spawn,          {.v = btopcmd } },
	{ MODKEY,              XK_m,      spawn,          {.v = viscmd } },
	{ MODKEY,              XK_t,      spawn,          {.v = todocmd} },
	{ MODKEY,              XK_p,      spawn,          {.v = lplancmd } },
	{ 0,                   XK_Print,  spawn,          {.v = scrotcmd } },
	{ MODKEY,              XK_u,      spawn,          {.v = defwallcmd } },
	{ MODKEY,              XK_j,      spawn,          {.v = jpvidscmd } },
	{ MODKEY|ShiftMask,    XK_u,      spawn,          {.v = altwallcmd } },
	{ MODKEY,              XK_b,      togglebar,      {0} },
	{ MODKEY,              XK_Down,   focusstack,     {.i = +1 } },
	{ MODKEY,              XK_Right,  focusstack,     {.i = +1 } },
	{ MODKEY,              XK_Up,     focusstack,     {.i = -1 } },
	{ MODKEY,              XK_Left,   focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,    XK_Left,   incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,    XK_Right,  incnmaster,     {.i = -1 } },
	{ MODKEY,              XK_comma,  setmfact,       {.f = -0.05} },
	{ MODKEY,              XK_period, setmfact,       {.f = +0.05} },
	{ MODKEY,              XK_q,      killclient,     {0} },
	{ MODKEY,              XK_a,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,    XK_a,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,              XK_s,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,              XK_d,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ShiftMask,    XK_s,      togglefloating, {0} },
	{ MODKEY,              XK_f,      togglefullscr,  {0} },
	{ MODKEY,              XK_space,  zoom,           {0} },
	{ MODKEY,              XK_Tab,    view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,    XK_Tab,    tag,            {.ui = ~0 } },
	{ MODKEY,              XK_g,      setgaps,        {.i = GAP_TOGGLE} },
	TAGKEYS(               XK_1,                      0)
	TAGKEYS(               XK_2,                      1)
	TAGKEYS(               XK_3,                      2)
	TAGKEYS(               XK_4,                      3)
	TAGKEYS(               XK_5,                      4)
	{ MODKEY|Mod1Mask,     XK_q,      spawn,          {.v = poweroff } },
	{ MODKEY|Mod1Mask,     XK_w,      spawn,          {.v = reboot } },
	{ MODKEY|Mod1Mask,     XK_e,      quit,           {0} },
	{ MODKEY|Mod1Mask,     XK_r,      spawn,          {.v = restart } },

	/* media keys */
	{ 0, XF86XK_AudioRaiseVolume,     spawn,          {.v = volr } },
	{ 0, XF86XK_AudioLowerVolume,     spawn,          {.v = voll } },
	{ 0, XF86XK_AudioMute,            spawn,          {.v = volm } },
	{ 0, XF86XK_MonBrightnessUp,      spawn,          {.v = brir } },
	{ 0, XF86XK_MonBrightnessDown,    spawn,          {.v = bril } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,        0,              Button1,        spawn,          {.v = roficmd } },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
