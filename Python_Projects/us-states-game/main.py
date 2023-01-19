import turtle
import pandas

screen=turtle.Screen()
screen.title("U.S. States Game")

image="blank_states_img.gif"
screen.addshape(image)
turtle.shape(image)

data = pandas.read_csv("50_states.csv")
all_states= data.state.to_list()

guess_state=[]
while len(guess_state)<50:
    answer=screen.textinput(title=f"{len(guess_state)}/50 states correct",prompt="what's another state name?").title()
    print(answer)

    if answer =="Exit":
        missing_states=[]
        for state in all_states:
            if state not in guess_state:
                missing_states.append(state)
        new_data= pandas.DataFrame(missing_states)
        new_data.to_csv("States_to_learn.csv")
        break
    if answer in all_states:
        guess_state.append(answer)
        t=turtle.Turtle()
        t.hideturtle()
        t.penup()
        state_data=data[data.state==answer]
        t.goto(int(state_data.x),int(state_data.y))
        t.write(answer)

