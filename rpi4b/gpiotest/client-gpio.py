#!/usr/bin/python3

import socket
import time

HOST = '192.168.86.68'   # The remote host
PORT = 50007              # The same port as used by the server

sock=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect((HOST, PORT))

sock.sendall("start".encode())
print(sock.recv(1024))

for i in range( 5 ):
    sock.sendall("led_on".encode())
    print(sock.recv(1024))
    time.sleep( 1 )
    sock.sendall("led_off".encode())
    print(sock.recv(1024))
    time.sleep( 1 )

for i in range( 5 ):
    sock.sendall("lcd_red".encode())
    print(sock.recv(1024))
    time.sleep( 0.8 )
    sock.sendall("lcd_green".encode())
    print(sock.recv(1024))
    time.sleep( 0.8 )
    sock.sendall("lcd_blue".encode())
    print(sock.recv(1024))
    time.sleep( 0.8 )
    sock.sendall("lcd_yellow".encode())
    print(sock.recv(1024))
    time.sleep( 0.8 )
    sock.sendall("lcd_cyan".encode())
    print(sock.recv(1024))
    time.sleep( 0.8 )
    sock.sendall("lcd_purple".encode())
    print(sock.recv(1024))
    time.sleep( 0.8 )
    sock.sendall("lcd_white".encode())
    print(sock.recv(1024))
    time.sleep( 0.8 )
    sock.sendall("lcd_black".encode())
    print(sock.recv(1024))
    time.sleep( 0.8 )

sock.sendall( "Hello world !\nIt works !\n".encode() )
print(sock.recv(1024))

for i in range( 5 ):
    sock.sendall("servo_middle".encode())
    print(sock.recv(1024))
    time.sleep( 0.8 )
    sock.sendall("servo_right".encode())
    print(sock.recv(1024))
    time.sleep( 0.8 )
    sock.sendall("servo_left".encode())
    print(sock.recv(1024))
    time.sleep( 0.8 )
    sock.sendall("servo_middle".encode())
    print(sock.recv(1024))
    time.sleep( 0.8 )
    sock.sendall("servo_left".encode())
    print(sock.recv(1024))
    time.sleep( 0.8 )
    sock.sendall("servo_right".encode())
    print(sock.recv(1024))
    time.sleep( 0.8 )
    sock.sendall("servo_middle".encode())
    print(sock.recv(1024))
    time.sleep( 0.8 )
    sock.sendall("servo_left".encode())
    print(sock.recv(1024))
    time.sleep( 0.8 )

sock.sendall("servo_stop".encode())
print(sock.recv(1024))
sock.sendall("bye".encode())
print(sock.recv(1024))

sock.close()
