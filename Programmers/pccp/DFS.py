def DFS(n):
    if n > 0:
        print(n, end=' ') # 3 2 1
        DFS(n-1)
        print(n, end=' ') # 1 2 3

DFS(3)