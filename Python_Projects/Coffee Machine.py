MENU = {
    "espresso": {
        "ingredients": {
            "water": 50,
            "coffee": 18,
        },
        "cost": 1.5,
    },
    "latte": {
        "ingredients": {
            "water": 200,
            "milk": 150,
            "coffee": 24,
        },
        "cost": 2.5,
    },
    "cappuccino": {
        "ingredients": {
            "water": 250,
            "milk": 100,
            "coffee": 24,
        },
        "cost": 3.0,
    }
}

resources = {
    "water": 300,
    "milk": 200,
    "coffee": 100,
}
profit = 0


def is_resource_sufficient(order_ingredients):
    for items in order_ingredients:
        if order_ingredients[items]>resources[items]:
            print(f"⚠ Sorry! not enough {items}")
            return 0
    return 1

def measuring_coins():
    print("Please insert coins.")
    total = int(input("how many quarters?: ")) * 0.25
    total += int(input("how many dimes?: ")) * 0.1
    total += int(input("how many nickles?: ")) * 0.05
    total += int(input("how many pennies?: ")) * 0.01
    return total

def not_enough_money(payment,drink_cost):
    if payment>drink_cost:
        remaining= round(payment-drink_cost,2)
        print(f"Here is the change ${remaining} ")
        global profit
        profit=profit+drink_cost
        return 1
    else:
        print("Sorry that's not enough money. Money refunded.")
        return 0

def Coffee(your_drink,order_ingredients):
    for items in order_ingredients:
        resources[items]-=order_ingredients[items]
    print(f"Here is your {your_drink} ☕️. Enjoy!")

on = True

while on:
    choice = input("What would you like? (espresso 1.5$ /latte 2.5$ /cappuccino 3$): ")
    if choice == "off":
        on = False
    elif choice == "report":
        print(f"Water: {resources['water']}ml")
        print(f"Milk: {resources['milk']}ml")
        print(f"Coffee: {resources['coffee']}g")
        print(f"Money: ${profit}")
    else:
        drink = MENU[choice]
        if is_resource_sufficient(drink["ingredients"]):
            payment = measuring_coins()
            if not_enough_money(payment, drink["cost"]):
                Coffee(choice, drink["ingredients"])





