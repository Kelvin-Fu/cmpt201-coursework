#!/bin/bash

RAND=$RANDOM

word=$( head -n "$RAND" /usr/share/dict/words| tail -1 )

echo "$word"
