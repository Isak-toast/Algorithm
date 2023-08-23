def solution(queries):
    answer = []
    child = ["RR", "Rr", "Rr", "rr"]
    
    def back(gen, x):
        if gen == 1:
            return "Rr"
        parent = back(gen-1, x//4) # 부모 세대를 가져온다. x를 4로 나눈 몫
        if parent == "Rr":
            return child[x%4]
        else:
            return parent # 부모가 순종이라면 자식도 순종
    
    for q in queries:
        n, p = q
        result = back(n, p-1)
        answer.append(result)
        
    return answer