FROM debian:buster

RUN apt-get update
RUN apt-get -y install php7.3 php-mysql php-fpm wget mariadb-client

EXPOSE 9000

COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d
COPY ./tools /var/www/

RUN chmod +x /var/www/wordpress_setup.sh

ENTRYPOINT [ "/var/www/wordpress_setup.sh" ]
