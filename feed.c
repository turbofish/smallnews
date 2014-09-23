/**
 *
 *
 *
 * vim: set fdm=marker fileencoding=utf-8 ts=4 sw=4 expandtab :
*/

#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "feed.h"
#include "log.h"

feed_t* feed_new(void) {
    /* {{{ */
    feed_t* f;

    f = (feed_t*) malloc(sizeof(feed_t));
    if (f == NULL) {
        log_crash("Cannot allocate feed");
    }

    return f;
    /* }}} */
}

void feed_delete(feed_t* f) {
    /* {{{ */
    assert(f != NULL);

    free(f);
    /* }}} */
}

