from queue import PriorityQueue
def solution(program):
    answer = [0]*10
    program.sort(key = lambda x : x[1]) # 호출된 시간으로 정렬
    pQ = PriorityQueue()
    cur = 0
    # 현재 시간을 기준으로 프로그램을 호출
    def call_program():
        while len(program) > 0 and program[0][1] <= cur:
            pQ.put(program.pop(0)) # 리스트 0번을 pQ에 삽입
    
    while len(program) > 0 or not pQ.empty():
        if pQ.empty():
            cur = program[0][1] # 호출된 시간을 현재 시간으로 획득
            call_program()
        execute = pQ.get()
        answer[execute[0]-1]+=(cur-execute[1])
        cur += execute[2]
        call_program()
        
    return [cur]+answer