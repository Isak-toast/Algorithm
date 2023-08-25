def solution(command):
    dxy = [[0,1], [1,0], [0,-1], [-1,0]]
    x = y = d = 0
    for c in command:
        if c == 'R':
            d = (d+1)%4
        elif c == 'L':
            d = (d-1)%4
        elif c == 'G':
            x = x + dxy[d][0]
            y = y + dxy[d][1]
        elif c == 'B':
            x = x - dxy[d][0]
            y = y - dxy[d][1]
            
    return [x,y]