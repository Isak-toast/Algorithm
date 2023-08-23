import collections
def solution(input_string):
    answer = ''
    sH = collections.defaultdict(int)
    prev = None
    for cur in input_string:
        if cur != prev:
            sH[cur] += 1
        prev = cur
    
    for [key, val] in sH.items():
        if val >= 2:
            answer += key
    if len(answer) == 0:
        return "N"
    return "".join(sorted(answer)) # "bac" string -> ['a', 'b', 'c'] 정렬 리스트로 반환

