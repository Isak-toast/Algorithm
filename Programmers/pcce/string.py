# count
msg = "탑 이기고 있으니까 바텀만 가"
print(msg.count('탑'))

# find
name = "startcoding"
print(name.find('t'))

# replace
sayhello = "hello, hello, hello, what's up"
sayhi = sayhello.replace('hello', 'hi')
print(sayhi)

# split
text = "파이썬 아따 쉽구마잉~"
print(text.split())

fruits = "orange, strawberry, pineapple"
res = fruits.split(',')
print(res)


# join
text = ['Monday', 'Friday', 'Saterday']
print(''.join(text))
print(' '.join(text))
print(':'.join(text))

# 공백문자 제거
text = " 아따 날씨 좋구마이! "
print(text.strip())
print(text.rstrip())
print(text.lstrip())


