FROM debian:buster

RUN apt-get update
RUN apt-get install -y mariadb-server

EXPOSE 3306

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY ./tools /var/www/
# RUN chmod +x /var/www/db.sh
# RUN chmod +x /var/www/initial_db.sql

# ENTRYPOINT [ "/var/www/db.sh" ]
RUN service mysql start && mysql < /var/www/initial_db.sql && rm -f /var/www/initial_db.sql;

CMD ["mysqld"]
