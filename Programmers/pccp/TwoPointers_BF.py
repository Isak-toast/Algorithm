# 완전탐색으로 풀이
import collections
def solution(gems):
    k=len(set(gems))
    maxL = 100000
    for i in range(len(gems)):
        sH = collections.defaultdict(int)
        for j in range(i, len(gems)):
            sH[gems[j]] += 1
            if len(sH) == k:
                if j-i+1 < maxL:
                    maxL = j - i + 1
                    answer = [i+1, j+1]
                break
    return answer