from turtle import Turtle

Font=("Arial",15,"normal")






class Score(Turtle):
    def __init__(self):
        super().__init__()
        self.penup()
        self.score=0
        self.color("white")
        self.goto(0,250)
        self.write(f"Score: {self.score}",align="center",font=Font)
        self.hideturtle()

    def counting_score(self):
        self.clear()
        self.score+=1
        self.write(f"Score: {self.score}", align="center", font=Font)

    def game_over(self):
        self.goto(0,0)
        self.write("Game Over", align="center", font=Font)
