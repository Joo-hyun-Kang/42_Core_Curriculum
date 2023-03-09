LOCAL_VOLUME_DB = /Users/jinhyeok/Desktop/42inception/data/mariadb
LOCAL_VOLUME_WP = /Users/jinhyeok/Desktop/42inception/data/wordpress

all: up

up:
	@mkdir -p $(LOCAL_VOLUME_DB)
	@mkdir -p $(LOCAL_VOLUME_WP)
	# @bash -c "echo '127.0.0.1       jokang.42.fr' >> /etc/hosts"  # localhost와 jokang@42.fr 연동
	@docker-compose -f ./srcs/docker-compose.yml up

down:
	@docker-compose -f ./srcs/docker-compose.yml down

re:
	@docker-compose -f srcs/docker-compose.yml up --build

clean:
	@docker stop $$(docker ps -qa);\
	docker rm $$(docker ps -qa);\
	docker rmi -f $$(docker images -qa);\
	docker volume rm $$(docker volume ls -q);\
	docker network rm $$(docker network ls -q);\

fclean:
	@docker stop $$(docker ps -qa);\
	docker rm $$(docker ps -qa);\
	docker rmi -f $$(docker images -qa);\
	docker volume rm $$(docker volume ls -q);\
	docker network rm $$(docker network ls -q);\
	rm -rf ./data

.PHONY: all re down clean
