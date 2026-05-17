#ifndef FT_PING_H
#define FT_PING_H

#include <stdio.h>           // printf
#include <stdlib.h>          // exit
#include <string.h>          // memset
#include <unistd.h>          // getpid, close
#include <signal.h>          // signal, SIGINT
#include <sys/socket.h>      // socket, sendto, recvfrom
#include <sys/time.h>        // gettimeofday
#include <netinet/in.h>      // sockaddr_in
#include <netinet/ip_icmp.h> // ICMP structs
#include <arpa/inet.h>       // inet_addr, inet_ntoa
#include <netdb.h>           // getaddrinfo
#include <errno.h>           // errno, perror

#define OPT_VERBOSE (1 << 0)  //-v
#define OPT_HELP    (1 << 1) // -?

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
    int received;
    double rtt_min;
    double rtt_max;
    double rtt_sum;
    double rtt_values[1000];
} t_stats;

typedef struct s_ping
{

    int sock;
    struct sockaddr_in dest;
    char *host;
    char *ip;
    t_stats stats;
    int flags;
} t_ping;

// for  debuging
#define DEBUG 0

#define LOG(fmt, ...)                                            \
    do                                                           \
    {                                                            \
        if (DEBUG)                                               \
            fprintf(stderr, "[DEBUG] " fmt "\n", ##__VA_ARGS__); \
    } while (0)

// utils.c
int  init_ping(int ac, char **av, t_ping *ping);

//print_functions.c
void print_help(void);

// socket.c
int create_socket(void);
void close_socket(int sock);

// resolve.c
int resolve_host(t_ping *ping);

// packet.c
void build_packet(t_icmp *packet, int sequence);
uint16_t calculate_checksum(void *data, int len);

// send_recv.c
void send_ping(t_ping *ping, t_icmp *packet);
int recv_ping(t_ping *ping, char *buffer);

// parse.c
void parse_reply(t_ping *ping, char *buffer, double rtt);
uint8_t get_ttl(char *buffer);

// stats.c
void update_stats(t_ping *ping, double rtt);
void print_stats(t_ping *ping);

// signal.c
void handler_sigint(int sig);


#endif