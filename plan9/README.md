## rio
black background add -b to rio in lib/profile
scrolling behavior add -s to rio in lib/profile
```
font=/lib/font/bit/fixed/unicode.9x15.font
rio -b -s -i riostart
```

## boot config
```
% 9fs 9fat
% sam /n/9fat/plan9.ini
```

## audio
in plan9.ini
```
% audio0=type=sb16 port=0x220 irq=5 dma=5
```
if that doesn't work, try Intel HD audio instead
no configuration is needed

```
% audio/oggdec < music.ogg > /dev/audio
% echo pin 10 > /dev/audioctl
% cat /dev/audiostat
```

## disk management
disk usage
```
% echo statw >>/srv/cwfs.cmd && cat /srv/cwfs.cmd
```
trigger dump
```
% echo dump >>/srv/cwfs.cmd
```
mount dump
```
mount /srv/boot /n/dump dump
```

## serial
COM1 and COM2 are /dev/eia0 and /dev/eia1 respectively

### serial console
plan9.ini
```
console=0 b19200
```

$home/bin/rc/riostart
```
# run a system shell on the serial console
~ $#console 0 || window -scroll console
```

## sysinfo
lspci
```
% pci -v
```

list vesa modes
```
% aux/vga -p
```

mac addr and stats
```
% cat '#'l0/ether0/addr
% cat '#'l0/ether0/stats
% cat '#'l0/ether0/ifstats
```

lscpu
```
% aux/cpuid
```

```
% cat '#'c/config
```

ioaddr
```
% cat '#'P/ioalloc
```

irq
```
% cat '#'P/irqalloc
```

listing with line numbers
```
% sed '=' file | sed 'N;s/\n/: /'
```

## dmesg
```
% cat /dev/kmesg
```

## golang go
install 1.4.3
```
% hget -o go1.4.3.tar.gz https://github.com/golang/go/archive/go1.4.3.tar.gz
% tar xvf go1.4.3.tar.gz
% cd go-go1.4.3/src
% rc.all
```

## hexdump
```
xd file
```
