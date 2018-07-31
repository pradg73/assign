import sys
s = map(lambda k: int(k),sys.argv[1].split(','))
print s

wf = 0
while sum(s) != 0:
    r = [] # one row
    news = [] # new s
    for i in s:
        if i != 0:
            r = r + [1]
            news = news + [i - 1]
        else:
            r = r + [0]
            news = news + [0]
    print "s ",s
    print "r ",r
    print "news ",news
    # count # of zeros between 1
    l = False # did we find a left 1
    w = 0
    wif = 0
    for i in r:
        if l == False:
            if i == 1:
                l = True
        else:
            if i == 0:
                wif+= 1
            else:
                w += wif
                wif = 0
    print "w ",w
    s = news
    wf += w
print "wf ",wf

'''
Calculate the volume of water that will be caught between towers.

Imagine a row of three towers:

#
# #
###
If water is poured over the towers, water will be caught between the two towers on the edges. If each # is 1 unit by 1 unit, then 1 unit of water will be caught.

  #
  #  #
# #  ##
#########
In this example there are two troughs. The first on the left captures 1 unit of water, while the other trough captures 4 units for a total of 5 units of water.

Write a function that will perform this calculation.
'''
