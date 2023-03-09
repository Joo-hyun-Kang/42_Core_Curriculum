FROM debian:buster

RUN apt-get update
RUN apt-get install -y nginx openssl

EXPOSE 443

COPY ./conf/nginx.conf /etc/nginx/sites-enabled/nginx.conf
COPY ./tools/nginx_setup.sh /var/www

RUN chmod +x /var/www/nginx_setup.sh

ENTRYPOINT [ "var/www/nginx_setup.sh" ]
