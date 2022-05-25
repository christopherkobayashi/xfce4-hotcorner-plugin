# Xfce4 HotCorner Panel Plugin

## Introduction

This Xfce4 panel implements screen hot corner actions.

This functionality was used historically by AfterDark (and workalikes) to invoke the screensaver by moving the mouse pointer to the designated screen corner.

The HotCorner panel plugin supports the following operations on the primary display:

- [xfdashboard](https://docs.xfce.org/apps/xfdashboard/start)
- toggle desktop view (via [libwnck](https://gitlab.gnome.org/GNOME/libwnck))
- start screensaver (via "xset s activate")
- turn off monitor (via "xset dpms force off")
- run a custom command

## Screenshot
 ![Screenshot](doc/screenshot.png?raw=true "Screenshot")

## Build requirements

- libgtk+-3
- libwnck >= 3.14.0
- xfce4-panel >= 4.12.0
- libnotify

## Installation from source
```console
./configure --prefix=/usr
make && make install
```

## Credits
xfce4-hotcorner-plugin was originally written by Brian Hsu (<brianhsu.hsu@gmail.com>)
It is currently maintained by Christopher Kobayashi (<software+github@disavowed.jp>)

## License

Licensed under GNU GPL v2 or (at your option) any later version.

