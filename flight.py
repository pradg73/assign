#!/usr/bin/python
edges = { 'A' : ['B','C','D'],
         'B' : ['A','C','D'],
         'C' : ['A','B'],
         'D':['A','B']
}

visited = {}

for key in edges:
    visited[key] = False

start = 'C'
end = 'D'

paths=[]
def traverse(path, r):
   # print path, r, visited[r]
    if r == end:
        paths.append(path)
        return

    l = edges[r]

    for v in l:
        if visited[v] == False:
            visited[v] = True
            traverse(path+v,v)
            visited[v] = False

visited[start] = True
traverse(start,start)

for p in paths:
    print p
