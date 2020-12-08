REM use something like com0com to connect two serial ports virtually
qemu-system-x86_64 -drive "format=raw,if=ide,file=C:\Users\James\QEMU VMs\sodium\sodium.img" -serial COM5 -m 256M -accel hax
