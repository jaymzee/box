#!/usr/bin/env bash

yum -y install httpd
yum -y install php

# below doesn't work on SELinux enabled kernels (Centos 7)
# since you can't set permissions of any sort on vbox shared folders
# probably NFS would be better and is recommended by the Centos 7 vagrant image project
#if ! [ -L /var/www ]; then
#  rm -rf /var/www
#  ln -fs /vagrant /var/www
#fi

# so just create /var/www in the root filesystem instead
# and then set SELinux security context with
chcon  --user system_u --type httpd_sys_content_t -Rv /var/www/html

# then use rsync to copy the html folder over
# the files should inherit the security context of html folder set with chcon above
rsync -r /vagrant/html/ /var/www/html/

# start the httpd server
# ** doesn't seem to start from this script
# but it does start if i ssh into the box and start it
# apachectl start
