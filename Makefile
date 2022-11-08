FLAGS = -lm -lmlx -lX11 -lXext

all:
	cc test.c ${FLAGS}