#! /bin/bash

gcc -D_GNU_SOURCE -ansi -Wconversion -Wchar-subscripts -Wall -W -Wpointer-arith -Wwrite-strings -Wformat-security -Wmissing-format-attribute -fno-common -g -o pk2dump pk2dump.c pickit2dat.c && \
valgrind --db-attach=yes ./pk2dump > dump1.txt && \
diff -u dump.txt dump1.txt && \
rsync -auvz . /mnt/d/a/$(pwd)

