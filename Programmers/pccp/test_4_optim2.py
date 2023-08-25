# from queue import PriorityQueue # thread safe하게 동작하기 때문에 처리 속도가 더딤
import heapq # thread safe하지 않음
def solution(program):
    
    answer = [0]*10
    program.sort(key = lambda x : x[1]) # 호출된 시간으로 정렬
    pQ = []
    cur = 0
    # 현재 시간을 기준으로 프로그램을 호출
    pos = 0
    n = len(program)
    def call_program():
        nonlocal pos
        while pos < n and program[pos][1] <= cur:
            heapq.heappush(pQ, program[pos]) # 리스트 0번을 pQ에 삽입
            pos+=1
    while pos < n or len(pQ) > 0:
        if len(pQ) == 0:
            cur = program[pos][1] # 호출된 시간을 현재 시간으로 획득
            call_program()
        execute = heapq.heappop(pQ)
        answer[execute[0]-1]+=(cur-execute[1])
        cur += execute[2]
        call_program()
        
    return [cur]+answer