#!/bin/bash

if [ ! -f /etc/ssl/certs/nginx.crt ]; then
openssl req -x509 -nodes -days 365 -newkey rsa:4096 -keyout /etc/ssl/private/nginx.key -out /etc/ssl/certs/nginx.crt -subj "/C=KR/ST=Seoul/L=Seoul/O=wordpress/CN=jokang.42.fr";
echo "NGINX SSL SET UP";
fi

# openssl : TLS/SSL 구현한 오픈소스
# req : 인증 생성 요청을 처리하는 커맨드
# -x509 : X.509 standard로 만든 self-signed 인증서 생성
# -nodes : 생성한 개인키를 암호화하지 않음
# -newkey : arg 형식에 맞는 개인키 생성
# rsa:4096 : RSA 개인키 크기 설정
# -days : 인증서의 유효기간 (기본 30일)
# -subj : 인증서 내 정보를 인자로 입력
# -keyout, -out : 개인키를 적을 파일 지정, 인증서 저장 파일 지정

exec nginx -g 'daemon off;'
