/**
 * 
 *
 * vim: set fdm=marker fileencoding=utf-8 ts=4 sw=4 expandtab :
*/

#ifndef FEED_H_DEFINED
#define FEED_H_DEFINED

#include "entry.h"

typedef struct feed_s {
    char* title;
    char* description;
    char* author;
    char* link;

    entry_t* entries;
} feed_t;

feed_t* feed_new(char* title);

int feed_add_entry(feed_t* f, entry_t* e);

int feed_print(feed_t* f);

#endif /* FEED_H_DEFINED */

