import random
import time
from turtle import  Screen
from player import Player
from car_manager import CarManager
from score import Score
from turtle import Turtle
import random


screen=Screen()
screen.setup(width=600,height=600)
screen.title("Turtle crossing the road")
screen.tracer(0)

player= Player()
car_manager=CarManager()
score=Score()

screen.listen()
screen.onkey(player.go_up,"Up")

game_on=True

while game_on:
    time.sleep(0.2)
    screen.update()
    car_manager.create_cars()
    car_manager.move_cars()



    for car in car_manager.Cars:
        if car.distance(player)<20:
            game_on = False
            score.game_over()

    if player.finish_line():
        player.start()
        car_manager.speedy()
        score.increase_level()




screen.exitonclick()