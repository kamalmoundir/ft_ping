#ifndef FT_PING_H
# define FT_PING_H

# include <stdio.h>           // printf
# include <stdlib.h>          // exit
# include <string.h>          // memset
# include <unistd.h>          // getpid, close
# include <signal.h>          // signal, SIGINT
# include <sys/socket.h>      // socket, sendto, recvfrom
# include <sys/time.h>        // gettimeofday
# include <netinet/in.h>      // sockaddr_in
# include <netinet/ip_icmp.h> // ICMP structs
# include <arpa/inet.h>       // inet_addr, inet_ntoa
# include <netdb.h>           // getaddrinfo
# include <errno.h>           // errno, perror

// struct for icmp 
typedef struct s_icmp
{

    uint8_t type;
    uint8_t code;
    uint16_t checksum;
    uint16_t id;
    uint16_t sequence;

} t_icmp;

typedef struct s_stats
{

    int sent;
    int recieved;
    double rtt_min;
    double rtt_max;
    double rtt_sum;
    double rtt_values[1000];
} t_stats;

#endif