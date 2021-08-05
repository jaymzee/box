## Ubuntu 20.04.2 LTS (Focal Fossa)
packages installed:
- xorg
- openbox
- kitty
- LXTerminal
- awesome
- w3m
- fim
- dependencies for pygame 1.9.6
    - python3-dev libfreetype-dev libportmidi-dev
    - libsdl-dev libsdl-ttf2.0-dev libsdl-mixer1.2-dev libsdl-image1.2-dev

## Set Console Resolution
Add the lines below to /etc/default/grub and then execute `update-grub`.
```
GRUB_CMDLINE_LINUX_DEFAULT="nomodeset"
GRUB_GFXMODE=1280x1024
GRUB_GFXPAYLOAD_LINUX=keep
```

Start the X server from the console with `startx`

The X server will use the current console resolution. It seems grub does not 
support resolutions such as 1920x1080 for the console (it does not appear
in any of the VESA video modes listed). You should be able to override the
resolution that X uses. You'll need to generate an `xorg.conf` file using
`X -configure`.

In the Screen section Display subsection add a modes line such as
`modes "1920x1080"` and copy the xorg.conf to /etc/X11

## videoinfo (vbeinfo)
Instead of running videoinfo (vbeinfo) from the grub command line, there is a
utility https://github.com/wfeldt/mdt that provides the same info as vbeinfo.
You need libx86emu-dev to be installed.
