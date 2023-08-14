
answer = 0
def DFS(k, cnt, dungeons, ch):
    global answer
    asnwer = max(answer, cnt)
    for i in range(len(dungeons)):
        if k >= dungeons[i][0] and ch[i] == 0:
            ch[i] = 1
            DFS(k - dungeons[i][1], cnt+1, dungeons, ch)
            ch[i] = 0
        
            
    
def solution(k, dungeons):
    ch = [0]*len(dungeons) # visit 배열
    DFS(k, 0, dungeons, ch)
    
    return answer