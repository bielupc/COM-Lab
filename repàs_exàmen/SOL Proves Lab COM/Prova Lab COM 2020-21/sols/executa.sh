#!/bin/bash

if [ x$1 == x ]; then
   echo Us: $0 '<station-code>'
else

# implementeu aquesta execució
   station=$1
   ./do-gen-plot ${station}.val >${station}.html

fi
