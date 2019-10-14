import sys

def crush(seq):
    crushed = True
    newseq = []
    while crushed:
        crushed = False

        N = len(seq)
        i = 1
        while i < N:
            while seq[i] == seq[i-1] and i < N:
                i = i +1
                crushed = True
            if crushed == False:
                newseq = newseq + [seq[i-1]]

        seq = newseq
        newseq = []
    return seq

seq = sys.argv[1]
print seq
print crush(seq)
