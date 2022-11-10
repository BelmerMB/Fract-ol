FLAGS	= -lm -lmlx -lX11 -lXext

SRCS	= ./src/draw.c ./src/handle_keys.c ./src/window_init.c
all:
	cc main.c  ${SRCS} ${FLAGS}