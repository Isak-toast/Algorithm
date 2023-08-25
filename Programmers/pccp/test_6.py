import heapq
def solution(ability, number):
    answer = 0
    pQ = []
    for x in ability:
        heapq.heappush(pQ, x)
        
    for i in range(number):
        a = heapq.heappop(pQ)
        b = heapq.heappop(pQ)
        heapq.heappush(pQ, a+b)
        heapq.heappush(pQ, a+b)
    answer = sum(pQ)
    return answer