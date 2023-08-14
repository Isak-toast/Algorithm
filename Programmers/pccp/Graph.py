
# 인접 리스트 만들기
graph = [[] for _ in range(5)]

for a, b in edges:
    graph[a].append(b)
    graph[b].append(a)

