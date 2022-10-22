from random import randint


Easy_Num_try=10
Hard_Num_try=5


def Num_Of_tries():
    level = input("Press E for an easy level, and H for a hard level ")
    if level.lower()=="e":
        return Easy_Num_try
    else:
        return Hard_Num_try


def game():
    print("Welcome to the Number Guessing Game")

    answer = randint(1, 100)
    print(answer)
    turns=Num_Of_tries()

    lives = 0


    while lives !=answer:
        if turns>0:
            Guess_Num = int (input("Guess a number between 1 & 100 "))
            if answer==Guess_Num:
                print("Correct guessing ✅")
                break
            elif Guess_Num<answer:
                print("Incorrect guessing ❎ You are too low")
                turns-=1
                print(f"You are left with {turns} turns")
            elif Guess_Num>answer:
                print("Incorrect guessing ❎ You are too high")
                turns-= 1
                print(f"You are left with {turns} turns")
        else:
            print("You've run out of guesses, you lose.")
            return
game()




