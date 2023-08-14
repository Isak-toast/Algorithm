cnt = 0
def DFS(v, ch, graph):
    global cnt
    ch[v] = 1
    cnt += 1
    for i in graph[v]:
        if ch[i] == 0:
            DFS(i, ch, graph)

def solution(n, wires):
    global cnt
    answer = 987654321
    # 인접 리스트
    graph = [[] for _ in range(n+1)]
    for v1, v2 in wires:
        graph[v1].append(v2)
        graph[v2].append(v1)
    
    for v1, v2 in wires:
        ch = [0]*(n+1)
        ch[v2] = 1
        cnt = 0
        DFS(v1, ch, graph)
        answer = min(answer, abs(cnt - (n-cnt)))
    
    return answer
