#!/usr/bin/env bash
# install apache
yum -y install httpd
# install mysql
yum -y install mariadb-server
# install php
yum -y install php php-mysqlnd
