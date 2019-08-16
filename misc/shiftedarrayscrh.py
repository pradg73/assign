def pivot(a):
  l = 0
  r = len(a)-1
  while (l <= r):
    m = l + (r-l)/2
    if a[m] >= a[l] and a[m] > a[r]:
      if a[m+1] < a[m]:
        return m
      else:
        l = m + 1
    elif a[m] < a[l] and a[m] <= a[r]:
      r = m - 1
    else: # this is sorted
      if a[l] >= a[r]:
        return l # largest
      else:
        return r

def bs(a, n):
  print "bs dbg params ", a, ", ",n
  l = 0
  r = len(a)-1
  while (l <= r):
    m = l + (r-l)/2
    if a[m] == n:
      return m
    elif a[m] > n:
      r = m -1
    else:
      l = m + 1
  return -1

def shifted_arr_search(shiftArr, num):
  p = pivot(shiftArr)
  print "pivot ", p
  i = bs(shiftArr[0:p+1], num)
  if i == -1:
    j = bs(shiftArr[p+1:], num)
    if j == -1:
      return -1
    else:
      return p+j+1
  else:
    return i

if __name__ == "__main__":
  import csv
  import sys
  a = map (lambda x: int(x), sys.argv[1].split(','))
  print a
  n = int(sys.argv[2])
  print "bs ", bs(a,n)
  print shifted_arr_search(a, n)
