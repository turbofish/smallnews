/**
 *
 *
 *
 * vim: set fdm=marker fileencoding=utf-8 ts=4 sw=4 expandtab :
*/

#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "entry.h"
#include "log.h"

entry_t* entry_new(char* title) {
    /* {{{ */
    entry_t* e;

    e = (entry_t*) malloc(sizeof(entry_t));
    if (e == NULL) {
        log_crash("Cannot allocate entry");
        return NULL;
    }

    e->title = title;

    return e;
    /* }}} */
}

void entry_delete(entry_t* e) {
    /* {{{ */
    assert(e != NULL);

    free(e);
    /* }}} */
}

