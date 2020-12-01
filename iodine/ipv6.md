# disable ipv6 on linux

There are two ways to disable IPV6 in debian/ubuntu

## first method
add the following lines to /etc/sysctl.conf

    net.ipv6.conf.all.disable_ipv6 = 1
    net.ipv6.conf.default.disable_ipv6 = 1
    net.ipv6.conf.lo.disable_ipv6 = 1

## second method
add the kernel parameter `ipv6.disable=1` in /etc/default/grub

    GRUB_CMDLINE_LINUX="ipv6.disable=1"

then run:

    sudo update-grub
