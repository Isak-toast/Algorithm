import collections


def solution(id_list, report, k):
    answer = []
    report = list(set(report)) # 중복을 제거하자
    reportHash = collections.defaultdict(set)
    stoped = collections.defaultdict(int)

    for x in report: # 중복을 제거했기 때문에 counting 바로 가능
        _from, _to = x.split(' ') # string split
        reportHash[_from].add(_to) # 중복 신고는 없는 신고 내용
        stoped[_to]+=1 # 신고받은 사람 counting

    for name in id_list:
        mail = 0
        for user in reportHash[name]:
            if stoped[user] >= k: 
                mail += 1
        answer.append(mail)
    return answer