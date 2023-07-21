# https://campus.programmers.co.kr/tryouts/92270/challenges

delta = [[-1,-1], [0,-1], [1,-1],
        [-1, 0],         [1, 0],
        [-1, 1], [0, 1], [1, 1]]


def isLiveOrDie(board, position):
    sum = 0
    h = len(board)
    w = len(board[0])
    x = position[1]
    y = position[0]
    
    cur = board[y][x]
    for dx, dy in delta:
        nx = dx + x
        ny = dy + y
        
        if(nx >= w or ny >= h or nx < 0 or ny < 0):
            continue
        sum += board[ny][nx]
    
    # 유지 + 토글
    if cur==1 and (sum >= 5 or sum <= 2):
        return 0
    elif cur==0 and sum == 2:
        return 1
    else:
        return cur
     

def solution(n, board, position):
    answer = []
    h = len(board)
    w = len(board[0])
    
    new_board = [[0]*w for _ in range(h)]
    for i in range(h):
        for j in range(w):
            new_board[i][j] = isLiveOrDie(board, list([i,j]))

    for i in range(n):
        x = position[i][1]
        y = position[i][0]
        answer.append(new_board[y][x])
    return answer
