SRCS = fetch.c
BIN = fetch

LIBXML  = `pkg-config libxml-2.0 --libs`
LIBCURL = `pkg-config libcurl --libs`
LIBNCURSES = `pkg-config ncursesw --libs`
LIBS = ${LIBXML} ${LIBCURL} ${LIBNCURSES}
VERSION = `sh version.sh`

CFLAGS_LIBXML  = `pkg-config libxml-2.0 --cflags`
CFLAGS_LIBCURL = `pkg-config libcurl --cflags`
CFLAGS_NCURSES = `pkg-config ncursesw --cflags`
CFLAGS = ${CFLAGS_LIBXML} ${CFLAGS_LIBCURL} ${CFLAGS_NCURSES} -D_GNU_SOURCE

CFLAGS += -Wall --std=c99 -g3 -DDEBUG

all:
	$(CC) $(CFLAGS) $(SRCS) $(LIBS) -o $(BIN)

dist:
	echo $(VERSION)

