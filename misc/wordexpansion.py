def isInt(s):
    try:
        int(s)
        return True
    except ValueError:
        return False

def ex(e):
    print "e ",e
    r = ""
    i = 0
    N = len(e)
    while i < N:
        if isInt(e[i]):
            m = int(e[i])
            i = i+1
            assert(e[i]=='[')
            c = 1
            j = i + 1
            while c != 0:
                if e[j] == ']':
                    c = c - 1
                elif e[j] == '[':
                    c = c + 1
                j = j + 1
            r += m*ex(e[i+1:j-1])
            i = j
        else:
            r += e[i]
            i = i + 1
    return r

if __name__ == "__main__":
    import sys
    e = sys.argv[1]
    print ex(e)
