from collections import deque
def solution(menu, order, k):
    answer = 0
    queue = deque()
    complete = -1
    idx = 0
    for t in range(k*(len(order)-1)+1):
        if t == complete: # 다시 새로운 음료를 만들 수 있다
            queue.popleft()
            complete = -1
        if t == k*idx:
           queue.append(order[idx]) # 대기하고 있는 사람의 수
           idx+=1
        if complete == -1 and len(queue) > 0:
            complete = t+menu[queue[0]] # 완성되는 시간
        
        answer = max(answer, len(queue))
    return answer
        
        