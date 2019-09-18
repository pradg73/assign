def unhappy_partners(pref, pairs):
    retl = []
    for p1 in pairs.keys():
        p2 = pairs[p1]
        unhappy = False
        p1prefs = [] # p1's prefs above p2
        for x in pref[p1]:
            if x == p2:
                break
            p1prefs.append(x)
        for y in p1prefs:
            ypair = pairs[y]
            for k in pref[y]:
                if k == p1:
                    unhappy = True
                    break
                elif k == ypair:
                    break
        if unhappy:
            retl.append(p1)
    return retl;

if __name__ == "__main__":

    pref = {'A': ['B','C','D'],
            'B': ['C','A','D'],
            'C': ['A','B','D'],
            'D': ['A','B','C']}

    pairs = {'A':'D',
             'D':'A',
             'B':'C',
             'C':'B'}

    print(unhappy_partners(pref, pairs))
