#include "ft_ping.h"

int resolve_host(t_ping *ping)
{

    int ret;
    struct addrinfo hints;
    struct addrinfo *res;

    memset(&hints, 0, sizeof(hints));
    hints.ai_flags = 0;
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_RAW;
    hints.ai_protocol = IPPROTO_ICMP;

    ret= getaddrinfo(ping->host, NULL, &hints, &res);
    if (ret != 0)
    {
        fprintf(stderr, "ft_ping: %s: %s\n", ping->host, gai_strerror(ret));// perror no fucciona con getaddrinfo 
        return (-1);
    }

    //implementar ping desde result del getaddrinfo
    ping->dest =  *(struct sockaddr_in *)res->ai_addr;
    ping->ip = inet_ntoa(ping->dest.sin_addr);// convert adress form binary to string via inet_ntoa
    LOG("Resolved %s -> %s", ping->host, ping->ip);
    freeaddrinfo(res);
    
    return (0);
}