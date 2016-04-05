FROM ubuntu:14.04
#FROM python
ADD apt.conf /etc/apt/apt.conf
#RUN apt-get update
#RUN apt-get install -y python2.7
RUN apt-get install -y openssh-client openssh-server
#RUN apt-get install  --fix-missing  -y python2.7.6
#CMD ["y"]
ENV PATH "$PATH:/:./:"
RUN export PATH
ADD client.py /client.py
ADD server.py /server.py
RUN /bin/ln -s /usr/bin/python2.7 python
#CMD ["/bin/ln -s", "/usr/bin/python2.7 python"]
#CMD ["/bin/bash"]
