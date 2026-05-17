NAME    = ft_ping
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -I include -D_GNU_SOURCE

SRCS    = main.c utils.c socket.c packet.c send_recv.c parse.c stats.c signal.c resolve.c print_functions.c
OBJS    = $(addprefix obj/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

obj/%.o: %.c
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all