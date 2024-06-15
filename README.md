# **DWM**
My suckless's **DWM** (Dynamic Window Manager) build, based on dwm 6.3

# **PATCHES**
Explanations for all patches in this build (located in ./patches)

## [actualfullscreen.diff](https://dwm.suckless.org/patches/actualfullscreen/)
> While using monocle layout the bar is disabled (The window is then in an actual fullscreen)

## [alpha.diff](https://dwm.suckless.org/patches/alpha/)
> Adds support for alpha values, useful when using a compositor

## [attachbottom.diff](https://dwm.suckless.org/patches/attachbottom/)
> Makes new windows attach to the bottom of the stack, instead of at the top

## [autostart.diff](https://dwm.suckless.org/patches/autostart/)
> dwm runs `~/.dwm/autostart.sh &` and `~/.dwm/autostart_blocking.sh` on startup

## [floatingcenter.diff](https://dwm.suckless.org/patches/alwayscenter)
> Makes windows spawn on the center of the screen while in floating layout

## [fullgaps-toggle.diff](https://dwm.suckless.org/patches/fullgaps/)
> Adds support for window gaps

## [notitle.diff](https://dwm.suckless.org/patches/notitle)
> Doesn't show the title of the window on the bar

## [pertag-perseltag.diff](https://dwm.suckless.org/patches/pertag/)
> Limits the changes to layout, mfact, barpos, and nmaster to selected tags

## [swallow.diff](https://dwm.suckless.org/patches/swallow)
> Adds swallowing windows - when running gui applications from the terminal it gets "swallowed" until the gui application has been closed
