#!/bin/sh

service mysql start && mysql < /var/www/initial_db.sql && rm -f /var/www/initial_db.sql

exec mysqld
