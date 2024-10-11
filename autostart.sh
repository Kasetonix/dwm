#!/bin/zsh

# Setting variables for scripts
scr_path="$HOME/.local/bin/scripts"
statusbar="$scr_path/statusbar"

/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1 &
feh --bg-fill /home/kasetonix/pics/walls/defwall --no-fehbg
picom &
/usr/bin/dunst &
xset s off

sleep 1; xrandr --output eDP --primary --mode 1920x1080 --refresh 60 --output HDMI-A-1-0 --mode 1920x1080 --refresh 75 --same-as eDP

while [[ $(pidof dwm) != "" ]]; do
    setxkbmap pl &
    sh ~/.xprofile &
    sleep 20
done &

while [[ $(pidof dwm) != "" ]]; do
    [ -f /home/kasetonix/discord_utils.log ] && rm /home/kasetonix/discord_utils.log
    [ -f /home/kasetonix/discord_krisp.log ] && rm /home/kasetonix/discord_krisp.log
    sleep 1
done &

while [[ $(pidof dwm) != "" ]]; do
    xsetroot -name "$($statusbar)"
    sleep 0.1
done
