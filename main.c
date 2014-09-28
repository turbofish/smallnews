/**
 * 
 *
 * vim: set fdm=marker fileencoding=utf-8 ts=4 sw=4 expandtab :
*/

#include "feed.h"

int main(int argc, char** argv) {
    feed_t* f;
    entry_t* e1;
    entry_t* e2;

    f = feed_new("fnord");

    e1 = entry_new("fnorder");
    e2 = entry_new("fnordest");

    feed_add_entry(f, e1);
    feed_add_entry(f, e2);

    feed_print(f);

    return 0;
}

