qemu-system options
-fda floppy.img
-boot d -cdrom linux.iso
-boot order=adc
-drive format=raw,if=ide,file=linux.img
-accel hax
-nographic
-monitor stdio
-serial mon: stdio
-monitor telnet::45454,server,nowait
-device VGA,vgamem_mb=64
-curses
-m 256M

-audio-help will tell you how to convert your old audio settings
