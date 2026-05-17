#include "ft_ping.h"
#include <unistd.h>

int init_ping(int ac, char **av, t_ping *ping)
{
    int opt;

    memset(ping, 0, sizeof(t_ping));

    while ((opt = getopt(ac, av, ":v?")) != -1)
    {
        if (opt == 'v')
            ping->flags |= OPT_VERBOSE;
        else if (opt == '?')
        {
            if (optopt == 0)
            {
                print_help();
                exit(0);
            }
            fprintf(stderr, "ft_ping: invalid option -- '%c'\n", optopt);
            fprintf(stderr, "Usage: ft_ping [-v] [-?] <host>\n");
            return (1);
        }
    }

    if (optind >= ac)
    {
        fprintf(stderr, "ft_ping: missing host operand\n");
        fprintf(stderr, "Usage: ft_ping [-v] [-?] <host>\n");
        return (1);
    }

    ping->host = av[optind];
    return (0);
}
