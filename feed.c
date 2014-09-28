/**
 *
 *
 *
 * vim: set fdm=marker fileencoding=utf-8 ts=4 sw=4 expandtab :
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "feed.h"
#include "log.h"

feed_t* feed_new(char* title) {
    /* {{{ */
    feed_t* f;

    f = (feed_t*) malloc(sizeof(feed_t));
    if (f == NULL) {
        log_crash("Cannot allocate feed");
    }

    f->title = title;

    return f;
    /* }}} */
}

void feed_delete(feed_t* f) {
    /* {{{ */
    assert(f != NULL);

    free(f);
    /* }}} */
}

int feed_add_entry(feed_t* f, entry_t* e) {
    /* {{{ */
    entry_t* cur;

    assert(f != NULL);
    assert(e != NULL);

    /* find last entry */
    cur = f->entries;
    if (cur == NULL) {
        /* no entries */
        f->entries = e;
    } else {
       while (cur->next != NULL) {
           cur = cur->next;
       }
       /* at the end */
       cur->next = e;
    }

    return 0;
    /* }}} */
}

int feed_print(feed_t* f) {
    entry_t* e;

    assert(f != NULL);

    fprintf(stdout,"-= %s =-\n", f->title);

    e = f->entries;

    while (e != NULL) {
        fprintf(stdout,"* %s *\n",e->title);
        e = e->next;
    }

    return 0;
}

