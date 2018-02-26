#!/usr/bin/python

import sys
import fileinput

for line in fileinput.input():
    raw_words = line.split(",")
    words = []
    for w in raw_words:
        raw_word = w.strip()
        word = raw_word.strip('"')
        words.append(word.lower())

    d = {}
    for c in words[0]:
        if not c.isspace() and c != "\t":
            if c not in d:
                d[c] = 1
            else:
                d[c] += 1
    
    valid = True
    for c in words[1]:
        if not c.isspace() and c != "\t":
            if c not in d:
                valid = False
                break
            elif d[c] < 1:
                valid = False
                break
            else:
                d[c] -= 1
    
    if valid:
        for c, count in d.items():
            if count != 0:
                valid = False
                break

    if valid:
        print("Valid Pattern")
    else:
        print("Invalid Pattern")