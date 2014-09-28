/**
 * 
 *
 * vim: set fdm=marker fileencoding=utf-8 ts=4 sw=4 expandtab :
*/

#ifndef ENTRY_H_DEFINED
#define ENTRY_H_DEFINED

typedef struct entry_s {
    char* title;
    char* description;
    char* author;
    char* updated;
    char* guid;

    struct entry_s* next;
} entry_t;

entry_t* entry_new(char* title);

void entry_delete(entry_t* e);

#endif /* ENTRY_H_DEFINED */

