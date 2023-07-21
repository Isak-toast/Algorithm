# https://campus.programmers.co.kr/tryouts/92258/challenges

def solution(text, anagram, sw):
    answer = ''
    arr = ['0'] * len(text)
    if sw == True:
        for i in range(len(anagram)):
            arr[anagram[i]] = text[i] # 문자 리스트를 만들어서 원하는 위치에 넣고 join 해버리겠다
    else:
        for i in range(len(anagram)):
            arr[i] = text[anagram[i]]
    answer = ''.join(arr)
    return answer