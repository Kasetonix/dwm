#!/bin/zsh

# Setting variables for scripts
scrDir="/home/kasetonix/.scripts"
statusbar="$scrDir/statusbar"

/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1 &
xrandr --output eDP-1 --primary --mode 1920x1080 --refresh 60 --output HDMI-A-1-0 --mode 1920x1080 --refresh 75 --same-as eDP-1 & 
feh --bg-fill /home/kasetonix/pics/walls/defwall --no-fehbg &
DRI_PRIME=0 picom &
/usr/bin/dunst &
xset s off

while [[ $(pidof dwm) != "" ]]; do
    setxkbmap pl &
    sh ~/.xprofile &
    sleep 20
done &

while [[ $(pidof dwm) != "" ]]; do
    xsetroot -name "$($statusbar)"
    sleep 0.1
done

exit 0
