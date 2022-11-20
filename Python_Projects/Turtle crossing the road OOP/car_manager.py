import random
from turtle import Turtle
Colors=["red","orange","yellow","green","blue","purple"]
Start_move_distance=5
Move_increment=10

class CarManager:
    def __init__(self):
        self.Cars = []
        self.car_speed=Start_move_distance
    def create_cars(self):
        random_chance=random.randint(1,6)
        if random_chance==1:
            turtle2 = Turtle(shape="square")
            turtle2.shapesize(1, 2)
            turtle2.penup()
            turtle2.color(random.choice(Colors))
            random_y=random.randint(0,300)
            turtle2.goto(x=-280, y=-100+random_y)
            self.Cars.append(turtle2)

    def move_cars(self):
        for members in self.Cars:
            if members.xcor()>280:
                members.setx(-280)
            members.forward(random.randint(30,100)+self.car_speed)

    def speedy(self):
        self.car_speed+=Move_increment
