from turtle import Screen,Turtle
from racket import Racket
from ball import Ball
from score import Score
import time

screen=Screen()
screen.bgcolor("black")
screen.setup(width=800,height=600)
screen.title("Pong Game OOP")
screen.tracer(0)

r_racket = Racket((350, 0))
l_racket = Racket((-350, 0))
ball = Ball()
score=Score()


screen.listen()
screen.onkey(r_racket.go_up,"Up")
screen.onkey(r_racket.go_down,"Down")
screen.onkey(l_racket.go_up,"w")
screen.onkey(l_racket.go_down,"s")

Pong_on = True
while Pong_on:
    time.sleep(ball.speedy)
    screen.update()
    ball.move()


    if ball.ycor()>280 or ball.ycor()<-280:
        ball.bounce_y()


    if ball.distance(r_racket)<50 and ball.xcor()>320 or ball.distance(l_racket)<50 and ball.xcor()<-320:
        ball.bounce_x()

    if ball.xcor() > 380:
        ball.reset_position()
        score.l_point()

    if ball.xcor() < -380:
        ball.reset_position()
        score.r_point()





screen.exitonclick()