F = []
F.append([1, 2, 4, 3, 2, 2])
F.append([1, 3])
print(set(F[0]))
result = set(F[0]).issuperset(set(F[1])) # F[0]는 F[1]보다 큰 개념

print(result)