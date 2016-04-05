import socket
import sys
import time

PORT=5005
HOST=None
try:
   sck= socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)
except socket.error as msg:
	print Error
sck.bind(('', PORT))
sck.listen(5)
c, addr = sck.accept();
print "client address %", addr
while 1:
	data = c.recv(104)
        print "Received string",data
	c.send((data.upper()))
        if(data.upper() == "BY"):
		time.sleep (2)
		c.close()
	

