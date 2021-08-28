## rio
black background add -b to rio in lib/profile
scrolling behavior add -s to rio in lib/profile
```
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

## play ogg file
```
% audio/oggdec < music.ogg > /dev/audio
```

## disk management
```
% echo statw >>/srv/cwfs.cmd && cat /srv/cwfs.cmd
```

listing with line numbers
```
sed '=' file | sed 'N;s/\n/: /'
```
