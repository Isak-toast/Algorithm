# https://campus.programmers.co.kr/tryouts/92269/challenges
def solution(serial):
    answer = ''
    gender = serial[:2]
    part = serial[2:4]
    team = serial[4:6]
    vnum = serial[6:]

    info = {
        '01' : 'male',
        '02' : 'female',
        '10' : 'operation',
        '11' : 'sales',
        '12' : 'develop',
        '13' : 'finance',
        '14' : 'law',
        '15' : 'research'
    }

    # gender
    answer += info[gender]
    answer += '/'

    # part
    answer += info[part]
    answer += '/'

    # team
    answer += str(int(team)) + 'team'
    answer += '/'

    # vnum
    chk_sum = 0
    for i in serial[:6]:
        chk_sum += int(i)
    
    if chk_sum % 13 == int(vnum):
        answer += 'valid'
    else:
        answer += 'invalid'
        
    return answer