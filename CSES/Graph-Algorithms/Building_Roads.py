n,m = map(int,input().split())

roots = [i for i in range(n)]
ranks = [1 for i in range(n)]

def find_root(x):
    global roots, ranks
    if roots[x] == x:
        return x
    else:
        roots[x] = find_root(roots[x])
        return roots[x]

def unite(u,v):
    global roots, ranks
    u = find_root(u)
    v = find_root(v)
    if u == v:
        return False
    if ranks[u] >= ranks[v]:
        ranks[u] += ranks[v]
        roots[v] = u
    else:
        ranks[v] += ranks[u]
        roots[u] = v
    return True

for i in range(m):
    u,v = map(int,input().split())
    u -= 1
    v -= 1
    unite(u,v)

s = set()
for i in range(n):
    s.add(find_root(i))
print(len(s)-1)
sl = []
for e in s:
    sl.append(e)

for i in range(1,len(sl)):
    print(sl[i-1]+1, sl[i]+1)

