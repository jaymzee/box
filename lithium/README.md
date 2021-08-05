/etc/default/grub
```
GRUB_CMDLINE_LINUX_DEFAULT="nomodeset"
GRUB_GFXMODE=1280x1024
GRUB_GFXPAYLOAD_LINUX=keep
```

Ubuntu 20.04.2 LTS (Focal Fossa)
packages installed:
xorg, openbox, kitty
w3m, fim
numpy
pygame 1.9.6 dependencies (sdl1.2, mixer, fonts, etc)

```
startx
```

to force a particular resolution, generate a xorg.conf
```
X -configure
```
then in the Screen section, Display subsection add
```
modes "1920x1080"
```
put the generated file in /etc/X11
