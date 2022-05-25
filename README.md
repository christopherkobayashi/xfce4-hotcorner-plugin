# XFCE4 HotCorner Panel Plugin

## Introduction

Allow users to set AfterDark-like hot corner actions.

The following operations are supported on the primary display:

- xfdashboard
- toggle desktop
- start screensaver
- turn off monitor
- run custom command

## Screenshot
 ![Screenshot](doc/screenshot.png?raw=true "Screenshot")

## Prerequisites

- CMake
- libgtk+-3
- libwnck >= 3.14.0
- xfce4-panel >= 4.12.0
- libnotify

##  Notes
- Use "Turn off monitor" to trigger lock event for xss-lock

## Installation from source
```console
git clone git://github.com/christopherkobayashi/xfce4-hotcorner-plugin.git
cd xfce4-hotcorner-plugin
cmake -DCMAKE_INSTALL_PREFIX=/usr .
make install
```

## AUR package

- https://archlinux.org/packages/xfce4-hotcorner-plugin

## License

Licensed under GNU GPL v2 or (at your option) any later version.
