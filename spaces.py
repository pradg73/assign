sent = "bloombergisfun"
words=set (["bloom", "berg", "bloomberg","is","funx"])

l = ""
while sent != "":
    if l == sent:
        print "no match"
        break

    l = sent
    for i in range(0,len(sent)+1):
        s = l[:i]
        if s in words:
            print s,' '
            sent = sent[i:]
            break
