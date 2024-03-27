CC= clang
CFLAGS = -ferror-limit=1 -gdwarf-4 -ggdb3 -O0 -std=c11 -Wall -Wextra -Wno-gnu-folding-constant -Wno-sign-compare -Wshadow
LDLIBS = -lcrypt -lcs50 -lm

EXE = runoff

SRCS = runoff.c
OBJS = $(SRCS:.c=.o)


$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDLIBS)