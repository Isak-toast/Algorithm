import math

def solution(fees, records):
    answer = []
    inTime = [0]*10000
    isIn = [0]*10000
    sumT = [0]*10000

    # 입력을 tokenizer로 split
    for record in records:
        time, np, con = record.split()
        h, m = time.split(":")

        if con == "IN": # 입차
            inTime[int(np)] = int(h)*60 + int(m)
            isIn[int(np)] = 1
        else:           # 출차
            sumT[int(np)] += (int(h)*60 + int(m)) - inTime[int(np)] # result time 나타내는 구역
            isIn[int(np)] = 0
    
    for i in range(10000):
        if isIn[i] == 1: # 입차가 남았다면 최종 시간을 넣어 구하기
            sumT[i] += (23*60 + 59) - inTime[i]
    
    for i in range(10000):
        if sumT[i] > 0:
            answer.append(fees[1] + max(math.ceil((sumT[i] - fees[0])/fees[2]), 0)*fees[3])

    return answer

fees = [180, 5000, 10, 600]
records = ["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"]
solution(fees, records)