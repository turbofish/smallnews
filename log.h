/**
 * 
 *
 * vim: set fdm=marker fileencoding=utf-8 ts=4 sw=4 expandtab :
*/

#ifndef LOG_H_DEFINED
#define LOG_H_DEFINED

#define crash(...) log_crash(...)

void log_crash(const char* msg);

#endif /* LOG_H_DEFINED */

