// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h>
#include <netinet/in.h> 
#include <netdb.h>
#include <unistd.h>
#include <time.h>
#include <string.h> 
#include <stdlib.h>

#define HOST "192.168.86.67"
#define PORT 8888

int make_socket( uint16_t port )
{
    int sock;
    struct sockaddr_in serv_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons( port );

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, HOST, &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    return sock;
}
   
int led_test( int sock ) 
{ 
    int valread, i; 
    const char *led_on = "led_on";
    const char *led_off  = "led_off"; 
    char buffer[1024] = {0}; 
     
    for ( i = 0; i < 5; i++ ) {
        send(sock , led_on, strlen(led_on) , 0 ); 
        valread = read( sock, buffer, 1024 ); 
        buffer[valread] = '\0';
        printf( "%s\n", buffer );
        sleep( 1 );
        send(sock , led_off, strlen(led_off) , 0 );
        valread = read( sock, buffer, 1024 );
        buffer[valread] = '\0';
        printf( "%s\n", buffer );
        sleep( 1 );
    } 
    return 0; 
}

int lcd_test( int sock )
{
    int valread, i, j;
    char color[8][12] = {"lcd_red","lcd_green","lcd_blue","lcd_yellow","lcd_cyan","lcd_purple","lcd_white","lcd_black"};
    const char *msg = "Hello world !\nIt works !\n";
    char buffer[1024] = {0};

    for ( i = 0; i < 5; i++ ) {
        for ( j = 0; j < 8; j++ ) {
            send(sock , color[j], strlen(color[j]) , 0 );
            valread = read( sock, buffer, 1024 );
            buffer[valread] = '\0';
            printf( "%s\n", buffer );
            sleep( 1 );
        }
    }
    send(sock , msg, strlen(msg) , 0 );
    valread = read( sock, buffer, 1024 );
    buffer[valread] = '\0';
    printf( "%s\n", buffer );
    return 0;
}

int servo( int sock )
{
    int valread, i;
    const char *stop = "servo_stop";
    const char *right  = "servo_right";
    const char *middle = "servo_middle";
    const char *left = "servo_left";
    char buffer[1024] = {0};

    for ( i = 0; i < 5; i++ ) {
        send(sock , middle, strlen(middle) , 0 );
        valread = read( sock, buffer, 1024 );
        buffer[valread] = '\0';
        printf( "%s\n", buffer );
        sleep( 1 );
        send(sock , right, strlen(right) , 0 );
        valread = read( sock, buffer, 1024 );
        buffer[valread] = '\0';
        printf( "%s\n", buffer );
        sleep( 1 );
        send(sock , left, strlen(left) , 0 );
        valread = read( sock, buffer, 1024 );
        buffer[valread] = '\0';
        printf( "%s\n", buffer );
        sleep( 1 );
        send(sock , middle, strlen(middle) , 0 );
        valread = read( sock, buffer, 1024 );
        buffer[valread] = '\0';
        printf( "%s\n", buffer );
        sleep( 1 );
        send(sock , left, strlen(left) , 0 );
        valread = read( sock, buffer, 1024 );
        buffer[valread] = '\0';
        printf( "%s\n", buffer );
        sleep( 1 );
        send(sock , right, strlen(right) , 0 );
        valread = read( sock, buffer, 1024 );
        buffer[valread] = '\0';
        printf( "%s\n", buffer );
        sleep( 1 );
        send(sock , middle, strlen(middle) , 0 );
        valread = read( sock, buffer, 1024 );
        buffer[valread] = '\0';
        printf( "%s\n", buffer );
        sleep( 1 );
        send(sock , left, strlen(left) , 0 );
        valread = read( sock, buffer, 1024 );
        buffer[valread] = '\0';
        printf( "%s\n", buffer );
        sleep( 1 );
    }
    send(sock , stop, strlen(stop) , 0 );
    valread = read( sock, buffer, 1024 );
    buffer[valread] = '\0';
    printf( "%s\n", buffer );
    return 0;
}

int main(int argc, char const *argv[])
{
    int valread;
    int sock;
    const char *bye = "bye";
    const char *start = "start";
    char buffer[1024] = {0};

    sock = make_socket( PORT );
    send(sock , start, strlen(start) , 0 );
    valread = read( sock, buffer, 1024 );
    buffer[valread] = '\0';
    printf( "%s\n", buffer );

    led_test( sock );
    lcd_test( sock );
    servo( sock );

    send(sock , bye, strlen(bye) , 0 );
    valread = read( sock, buffer, 1024 );
    buffer[valread] = '\0';
    printf( "%s\n", buffer );
    return 0;
} 
