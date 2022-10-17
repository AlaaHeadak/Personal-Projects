import random
from words_list import word_list
from Graphics import logo


print(logo)

choice=random.choice(word_list)
lives=6

#test code
#print(f"your chose word is: {choice}")

letter = []
for i in choice:
    letter.append("_")

end=False


while not end:

    guess=input("Please Guess a letter: ").lower()

    if guess in letter:
        print(f"You've already guessed {guess}")

    for position in range(len(choice)):
        letters=choice[position]
        if letters==guess:
            letter[position]=letters

    if guess not in choice:
        print(f"You guessed {guess}, that's not in the word. You lose a life.")
        lives-=1
        if lives==0:
            end=True
            print("You Lose")

    print(letter)

    if "_" not in letter:
        print("You Win")
        end == True
        break;


    from Graphics import stages
    print(stages[lives])

