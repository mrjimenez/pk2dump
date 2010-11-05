#! /bin/bash

gcc -Wall -g -o pk2dump pk2dump.c pickit2dat.c && \
valgrind --db-attach=yes ./pk2dump > dump1.txt && \
diff -u dump.txt dump1.txt && \
rsync -auvz . /mnt/d/a/$(pwd)

