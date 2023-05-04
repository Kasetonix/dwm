#!/bin/bash

# Setting variables for scripts
scrCapsL="/home/kasetonix/.scripts/capsl"
scrBright="/home/kasetonix/.scripts/brightness"
scrVolume="/home/kasetonix/.scripts/volume"
scrBattery="/home/kasetonix/.scripts/battery"
scrClock="/home/kasetonix/.scripts/clock"

/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1 &
xrandr --output eDP-1 --primary --mode 1920x1080 --refresh 60 --output HDMI-2 --mode 1920x1080 --refresh 75 --same-as eDP-1 & 
feh --bg-fill /home/kasetonix/pics/walls/defwall --no-fehbg &
picom &
/usr/bin/dunst &
xset s off

while [[ $(pidof dwm) != "" ]]; do
	setxkbmap pl &
	sleep 120
done &

while [[ $(pidof dwm) != "" ]]; do
    xsetroot -name "$($scrCapsL)$($scrVolume)$($scrBright)$($scrBattery)$($scrClock)"
    sleep 0.1
done &
