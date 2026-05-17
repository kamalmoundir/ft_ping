#include "ft_ping.h"

int main(int argc, char **argv)
{
    t_ping ping;

    if (init_ping(argc, argv, &ping))
        return 1;
    if (resolve_host(&ping))
        return 1;
    printf("Host: %s\n", ping.host);
    printf("IP:   %s\n", ping.ip);

    ping.sock = create_socket();
    if (ping.sock < 0)
        return (1);
    printf("Socket fd: %d\n", ping.sock);
    close_socket(ping.sock);
    return 0;
}