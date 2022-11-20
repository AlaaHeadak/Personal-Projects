from turtle import Turtle
Font=("Courier",10,"normal")

class Score(Turtle):
    def __init__(self):
        super().__init__()
        self.level = 1
        self.hideturtle()
        self.penup()
        self.goto(-280,280)
        self.update_score()


    def update_score(self):
        self.clear()
        self.write(f"Level:{self.level}", align="left", font=Font)

    def increase_level(self):
        self.level += 1
        self.update_score()

    def game_over(self):
        self.goto(0,0)
        self.write(f"GAME OVER", align="center", font=Font)