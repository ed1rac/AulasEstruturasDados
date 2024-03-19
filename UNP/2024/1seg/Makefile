#all: main
#$(CC) $(SRCS) -o "$@ $(CFLAGS)

CC = clang
override CFLAGS += -g -Wno-everything -pthread -lm -Wno-unused-result -lcs50
#override CFLAGS += -lcs50

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.c' -print)
#HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)
OBJS = $(SRCS:.c=.out)

# Regra para compilar cada arquivo .c para .out
%.out: %.c
	$(CC) $< -o $@ $(CFLAGS)

main: $(SRCS) #$(HEADERS)	
	$(CC) $(SRCS) -o "$@ $(CFLAGS)

main-debug: $(SRCS) $(HEADERS)
	$(CC) -O0 $(SRCS) -o "$@" $(CFLAGS)

clean:
	rm -f *.out