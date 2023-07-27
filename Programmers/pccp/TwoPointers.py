import collections

def solution(gems):
    answer = [0, 0]
    sH = collections.defaultdict(int)
    k = len(set(gems))
    lt = 0
    maxL = 1000000

    # rt는 0~n까지를 끝으로 진행
    for rt in range(len(gems)):
        sH[gems[rt]] += 1
        while(len(sH) == k): # 그 과정에서 보석이 k와 동일한 지점에서 로직이 발생
            if rt - lt + 1 < maxL: # 주의, 같다고 하면 동일한 지점에서 큰 원소를 기준으로 정답이 정해진다.
                maxL = rt - lt + 1
                answer = [lt+1, rt+1]
            sH[gems[lt]] -= 1
            if sH[gems[lt]] == 0:
                del sH[gems[lt]] # dictionary에서 gems[lt] key는 삭제
            lt+=1
    return answer
