#include "ft_ping.h"

void print_help(void)
{
    printf("Usage: ft_ping [-v] [-?] <host>\n");
    printf("Send ICMP ECHO_REQUEST packets to network hosts.\n\n");
    printf("Options:\n");
    printf("  -v    verbose output\n");
    printf("  -?    give this help list\n");
}