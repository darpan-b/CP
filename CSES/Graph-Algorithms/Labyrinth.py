n,m = map(int,input().split())
grid = [input() for i in range(n)]
 
dx = [-1,1,0,0]
dy = [0,0,-1,1]
INF = int(1e18)
 
par = [['?' for j in range(m)] for i in range(n)]
dist = [[INF for j in range(m)] for i in range(n)]
 
def is_valid(x,y):
    global n,m
    return x >= 0 and x < n and y >= 0 and y < m and grid[cx][cy] != '#'
 
pq = []
for i in range(n):
    for j in range(m):
        if grid[i][j] == 'A':
            pq.append([0, (i,j)])
            dist[i][j] = 0
            break
    if pq:
        break
 
while pq:
    cur = pq[0]
    pq.pop(0)
    if dist[cur[1][0]][cur[1][1]] != cur[0]:
        continue
    for i in range(4):
        cx = cur[1][0]+dx[i]
        cy = cur[1][1]+dy[i]
        if not is_valid(cx,cy):
            continue
        if dist[cx][cy] > cur[0]+1:
            dist[cx][cy] = cur[0]+1
            pq.append([dist[cx][cy], (cx,cy)])
            if i == 0:
                par[cx][cy] = 'U'
            elif i == 1:
                par[cx][cy] = 'D'
            elif i == 2:
                par[cx][cy] = 'L'
            else:
                par[cx][cy] = 'R'
 
 
for i in range(n):
    for j in range(m):
        if grid[i][j] == 'B':
            if dist[i][j] == INF:
                print('NO')
                exit(0)
            else:
                ans = ''
                cx,cy = i,j
                while is_valid(cx,cy) and grid[cx][cy] != 'A':
                    ans += par[cx][cy]
                    if par[cx][cy] == 'U':
                        cx += 1
                    elif par[cx][cy] == 'D':
                        cx -= 1
                    elif par[cx][cy] == 'L':
                        cy += 1
                    else:
                        cy -= 1
                print('YES')
                print(dist[i][j])
                print(ans[::-1])
                exit(0)
 
