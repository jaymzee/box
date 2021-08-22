## FreeDOS
- FreeDOS 1.2
- Turbo C++ 3.0
- Borland C++ 5.0
- MASM 6.11
- DJGPP
- UCOS
- PROCOMM

## FreeDOS 1.2

### VirtualBox
if you get invalid opcode when running the FD12 installer
at the initial boot menu press tab and add raw to the command line

### Network
enable networking by installing FDNET with FDIMPLES

## FreeDOS 1.2 DJGPP
```
SET DJGPP=C:\DEVEL\DJGPP\DJGPP.ENV
```
GCC shipped with FreeDOS 1.2 does not work in VirtualBox unless
VT-x is enabled for the virtual machine.

## FreeDOS 1.3 Networking with virtualbox
install CRYNWR packet drivers with FDIMPLES
add to autoexec.bat
```
SET MTCPCFG=C:\FDOS\MTCP.CFG
C:\FDOS\DRIVERS\CRYNWR\PCNTPK.COM int=0x60
C:\NET\MTCP\DHCP.EXE
```
MTCP.CFG should have at least
```
PACKETINT 0x60
```

# other things
CTTY changes the TTY to another device such as COM1
