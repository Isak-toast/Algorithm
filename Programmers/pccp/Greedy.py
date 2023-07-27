def solution(routes):
    answer = 1
    routes.sort(key = lambda x : x[1])
    point = routes[0][1]

    for i in range(1, len(routes)):
        if routes[i][0] > point:
            answer+=1
            point = routes[i][1]

    return answer


routes = [[-20,-15], [-14,-5], [-18,-13], [-5,-3]]
print(solution(routes))