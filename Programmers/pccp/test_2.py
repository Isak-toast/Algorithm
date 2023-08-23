answer = 0
def DFS(L, sum, ability, ch):
    global answer
    n = len(ability) # 학생 수
    m = len(ability[0]) # 종목 수
    
    if L == m:
        answer = max(answer, sum)
    else:
        for i in range(n):
            if ch[i] == 0:
                ch[i] = 1
                DFS(L+1, sum+ability[i][L], ability, ch)
                ch[i] = 0

def solution(ability):
    ch = [0]*len(ability) # 방문 배열
    DFS(0, 0, ability, ch)
    return answer