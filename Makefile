SRCS = entry.c error.c feed.c fetch.c log.c main.c
OBJS = $(SRCS:.c=.o)
BIN = smallnews

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

LD = gcc
LDFLAGS = 

DEPFLAGS = -MM
DEPFILE = .deps

JUNK = core a.out *.log *.tar.gz *.md5

TAR = tar
TARFLAGS = cfz 
TARTRANSFORM = --transform 's,^,smallnews/,'
DISTFILES = $(SRCS) Makefile README.md LICENSE *.sh *.h *.xml *.xsd


.PHONY: all clean dist dep
.DEFAULT: all

all: clean dep binary

binary: $(OBJS)
	$(LD) $(LDFLAGS) $(LIBS) $(OBJS) -o $(BIN) 

dist:
	$(TAR) $(TARFLAGS) $(BIN)-$(VERSION).tar.gz $(TARTRANSFORM) $(DISTFILES)
	md5sum $(BIN)-$(VERSION).tar.gz > $(BIN)-$(VERSION).md5

dep:
	@$(CC) $(DEPFLAGS) $(SRCS) > $(DEPFILE)

clean:
	@$(RM) -rf $(BIN) $(OBJS) $(JUNK)


-include $(DEPFILE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

