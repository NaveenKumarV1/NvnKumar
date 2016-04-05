# NvnKumar
Simple Socket communication between the Docker Containers.

Generally to establish the socket communication, Client need the Server address and port number.
So server has to be running under specific Address and port number which client has to aware or it.

If we want to establish communication between the Server container and Client container, we have run them in to One network space.

>For that we have to create a docker network with a gateway, subnet and range of IP addresses to be added to docker container.

$ docker network create --gateway=172.17.26.1 --ip-range=172.17.18.0/24 --subnet=172.17.0.0/16 mynet

>Start building the Docker image.

$ docker build -t <Docker_Tag> .


>Run the docker image with the new network name (--net=mynet) and a new IpAddress to be assigned to docker as Server container (--name=server)

$ docker run --name=server --net=mynet --ip=172.17.18.5 --rm -it <Docker_Tag>


>Run the another docker image with the new Network name (--net=mynet) as Client container (--name=client) in other terminal

$ docker run --name=client --net=mynet --rm -it <Docker_Tag>


> Now the connection between the Server Container and Client Container has established. 

> Client can able to send any message to Server. And server will reply the same message by making the text to upper case. Replied upperecase message will be seen in Client Terminal.

