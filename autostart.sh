#!/bin/bash

# Setting variables for scripts
scrDir="/home/kasetonix/.scripts"

scrCapsL="$scrDir/capsl"
scrBright="$scrDir/brightness"
scrVolume="$scrDir/volume"
scrBattery="$scrDir/battery"
scrClock="$scrDir/clock"

/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1 &
xrandr --output eDP-1 --primary --mode 1920x1080 --refresh 60 --output HDMI-A-1-0 --mode 1920x1080 --refresh 75 --same-as eDP-1 & 
feh --bg-fill /home/kasetonix/pics/walls/defwall --no-fehbg &
DRI_PRIME=0 picom &
/usr/bin/dunst &
xset s off

while [[ $(pidof dwm) != "" ]]; do
    setxkbmap pl &
    sh ~/.xprofile
    sleep 30
done &

while [[ $(pidof dwm) != "" ]]; do
    xsetroot -name "$($scrCapsL)$($scrVolume)$($scrBright)$($scrBattery)$($scrClock)"
    sleep 0.1
done &
