#include "ft_ping.h"

int create_socket(void)
{
    int sock;

    LOG("Creating raw socket (AF_INET, SOCK_RAW, IPPROTO_ICMP)");
    sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if (sock < 0)
    {
        perror("Socket creation failed (Are you root?)");
        return (-1);
    }

    LOG("Socket created successfully fd=%d", sock);
    return (sock);
}

void close_socket(int sock)
{
    LOG("Closing socket fd=%d", sock);
    close(sock);
    LOG("Socket closed");
}