#!/bin/bash
/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1 &
xrandr --output eDP-1 --primary --mode 1920x1080 --refresh 144 --output HDMI-1-1 --mode 1920x1080 --refresh 75 --same-as eDP-1 & 
feh --bg-fill /home/kasetonix/pics/walls/defwall --no-fehbg &
DRI_PRIME=0 picom &
/usr/bin/dunst &
xset s off

while [[ $(pidof dwm) != "" ]]; do
	setxkbmap pl &
	sleep 120
done &

while [[ $(pidof dwm) != "" ]]; do
	xsetroot -name "$(/home/kasetonix/.scripts/capsl)$(/home/kasetonix/.scripts/volume)$(/home/kasetonix/.scripts/battery)$(/home/kasetonix/.scripts/clock)"
    sleep 0.1
done &
