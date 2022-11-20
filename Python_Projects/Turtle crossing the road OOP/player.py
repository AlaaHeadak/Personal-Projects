from turtle import Turtle

Position=(0,-280)
Move=25
Finish_line_y=290


class Player(Turtle):
    def __init__(self):
        super().__init__()
        self.shape("turtle")
        self.color("black")
        self.penup()
        self.goto(Position)
        self.setheading(90)

    def go_up(self):
        self.forward(Move)

    def finish_line(self):
        if self.ycor()>Finish_line_y:
            return Turtle
        else:
            return False

    def start(self):
        self.goto(Position)
