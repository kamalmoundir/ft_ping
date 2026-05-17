#include "ft_ping.h"

int validar_arg(int ac, char **av)
{
    int count;
    if (ac < 2)
    {
        fprintf(stderr, "Usage: ./ft_ping [-v] [-?] <host>\n");
        return (1);
    }

    if(ac == 2 && !strcmp(av[1], '?'))
    {
        print_help();
        exit(0);
    }

    count = 1;

    while (count < ac - 1)
    {
        if ((av[count][0] == '-') && av[count][1] != 'v' && av[count][1] != '?')
        {
            fprintf(stderr, "Usage: ./ft_ping [-v] [-?] <host>\n");
            return (1);
        }
        count++;
    }
    if (av[ac - 1][0] == '-')
    {
        fprintf(stderr, "Usage: ./ft_ping [-v] [-?] <host>\n");
        return (1);
    }
    return (0);
}

void init_ping(int ac, char **av, t_ping *ping)
{
    int count;

    memset(ping, 0, sizeof(t_ping));

    count = 1;
    while (count < ac - 1)
    {
        if (!strcmp(av[count], "-v"))
            ping->verbose = OPT_VERBOSE;
        else if (!strcmp(av[count], "-?"))
            ping->verbose = OPT_HELP;
        count++;
    }
    ping->host = av[ac - 1];
}

void    print_help(void)
{
    printf("Usage: ft_ping [-v] [-?] <host>\n");
    printf("Send ICMP ECHO_REQUEST packets to network hosts.\n\n");
    printf("Options:\n");
    printf("  -v    verbose output\n");
    printf("  -?    give this help list\n");
}