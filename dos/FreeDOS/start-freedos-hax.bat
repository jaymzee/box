rem qemu-system-i386 -drive "format=raw,if=ide,file=C:\Users\James\QEMU VMs\FreeDOS\freedos.img" -m 64M -soundhw pcspk -accel hax
qemu-system-i386 -drive "format=raw,if=ide,file=C:\Users\James\QEMU VMs\FreeDOS\freedos.img" -m 64M -audiodev dsound,id=1 -machine pcspk-audiodev=1 -accel hax
