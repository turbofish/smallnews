#!/bin/sh
grep -R VERSION_STRING version.h | awk '{ print $3 }' | sed -e 's/"//g'
