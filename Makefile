SOURCES = init.c\
		Philosophers.c\
		philo_utils.c\
		philo_utils2.c\
		philo_utils3.c\
		init.c\

OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: philo

philo: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f philo

re: fclean all

.PHONY: all clean
