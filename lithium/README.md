## Ubuntu 20.04.2 LTS (Focal Fossa)
packages installed:
- build-essential linux-headers-$(uname -r)
- xorg w3m fim pulseaudio inxi
- openbox awesome kitty LXTerminal
- dependencies for pygame 1.9.6
    - python3-dev libfreetype-dev libportmidi-dev
    - libsdl-dev libsdl-ttf2.0-dev libsdl-mixer1.2-dev libsdl-image1.2-dev

## Set Console Resolution
Add these lines to /etc/default/grub and update grub with `update-grub`.
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

## OpenGL Renderer
To use LLVMpipe (software rasterizer) instead of SVGA3D add nomodeset to the
kernel cmdline in grub.

## vboxvideo, vmwgfx, vmware, and OpenGL
This driver is used for the VirtualBox VBoxSVGA and VMSVGA Graphics
Controllers.

VMSVGA is the controller that should be used since it's the only one that
supports 3D acceleration in VirtualBox 6.1, However, it is using an older
OpenGL and kitty does not support OpenGL < 3.3.

VBoxSVGA is supposed to support 3D acceleration in VirtualBox 6.0 but I found
the kernel still falls back to using the LLVMpipe (software rasterizer) for
OpenGL instead of SVGA3D. I got okay frame rates with SDL (simple 2D line
drawing) using this controller and kitty will work but the performance isn't
great because it's using OpenGL with the software rasterizer. I also can't
get the console screen resolution to remain at the value set in GRUB with
this controller - it switches back to 800x600 during boot.

To make sure X starts with any controller selected and the resulting OpenGL
rendering mode, change the update-alternatives priorty of kitty to be lower
than one of the other terminals so you can still bring up a terminal with the
menu.

## query audio
```
inxi -A
lshw -C multimedia
```
## query display
```
inxi -G
lshw -C display
glxinfo | grep OpenGL
glxgears -info
lspci
lsmod
```
