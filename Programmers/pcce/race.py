import turtle as t1
import time
import random


# screnn size
t1.setup(width=800, height=800)
t1.bgcolor('steelblue')
t1.color('orange')

# turtle size
t1.turtlesize(3)

t1.shape('turtle')
t1.penup()

# copy turtle
t2 = t1.clone()
t2.color('tomato')


# 준비 위치
t1.goto(-400, 300)
t2.goto(-400, -300)

# 출발
while True:
    t1.forward(random.randint(1, 100))
    t2.forward(random.randint(1, 100))
    time.sleep(1)

    # 도착 체크
    if t1.xcor() > 400:
        t1.goto(0, 0)
        t1.write(" winner!", font=('Arial', 20))
        break
    elif t2.xcor() > 400:
        t2.goto(0, 0)
        t2.write(" winner!", font=('Arial', 20))
        break

t1. exitonclick() # 화면 클릭시 종료
