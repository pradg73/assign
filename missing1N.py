#!/usr/bin/python
import sys
a = [1,3,4,5,6]
N = 6

a = map(lambda x:int(x), sys.argv[1:])
print a

Na = len(a)
N = Na + 1
if N == Na:
    print -1
    exit(0)
if a[0] != 1:
    print 1
    exit(0)
if a[Na-1] != N:
    print N
    exit(0)
#now missing number is not at either end

l = 0
r = Na-1
hiddennum = -1

while (l <= r):
    m = l + (r-l)/2

    if a[m] == m+1: # 1..m is a seq
        if a[m] != a[m+1]-1:
            hiddennum = m+2
            break
        else:
            l = m+1 # missing number is m+1..N
    elif a[m] > m+1: # missing num in 1..m
        if a[m] != a[m-1]+1:
            hiddennum = m+1
            break
        r = m -1
print hiddennum,'was the missing number.'
