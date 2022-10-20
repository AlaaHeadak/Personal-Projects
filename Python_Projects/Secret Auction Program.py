from replit import clear

bid={}

def the_highest_bid (record):
    highest_bid=0
    winner=""
    for bidder in record:
        bid_amount=record[bidder]
        if bid_amount> highest_bid:
            highest_bid=bid_amount
            winner=bidder
    print(f"The winner is {winner} with a bid of ${highest_bid}")

finished=False
while not finished:
    name = input("What's your name? ")
    amount = int(input("What's your bid $"))
    bid[name] = amount
    should_continue = input("Is there another bidder(y/n)")
    if should_continue == "n":
        finished = True
        the_highest_bid(bid)
    elif should_continue=="y":
        clear()

