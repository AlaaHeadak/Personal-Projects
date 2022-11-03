from turtle import Turtle, Screen
import random
race_on=False
screen=Screen()
screen.setup(width=500,height=400)
guess=screen.textinput(title="Turtle Race",prompt="Guess the winner, Enter a color")
colors=["red","orange","yellow","green","blue","purple"]
position=[-100,-60,-20,20,60,100]
participants=[]


for turtles in range(0,6):
    turtle = Turtle(shape="turtle")
    turtle.color(colors[turtles])
    turtle.penup()
    turtle.goto(x=-230, y=position[turtles])
    participants.append(turtle)

if guess:
    race_on=True



while race_on:
    for members in participants:
        if members.xcor()>230:
            race_on=False
            winner=members.pencolor()
            if winner==guess:
                print(f"You win, the winning turtle is {guess}")
            else:
                print(f"You lost, the winning turtle is {winner}")
        moving_distance=random.randint(0,10)
        members.forward(moving_distance)


screen.exitonclick()