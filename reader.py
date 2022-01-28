#! /usr/bin/python3

import os

print('opening...')
f = open('/dev/helloworld', 'r')
print('reading lines...')
lines = f.readline()
print(lines)
