#!/usr/local/python
import socket
import sys
HOST='172.17.18.5'
PORT=5005
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM,0)
s.connect((HOST,PORT))
while 1:
        data=raw_input()
        s.send(data,1024)
        data=s.recv(104)
        if (data =="BY"):
               s.close()
        print data;
