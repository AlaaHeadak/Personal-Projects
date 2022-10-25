from menue import Menu, MenuItems
from coffee_maker import CoffeeMaker
from money import Money

money = Money()
coffee_maker = CoffeeMaker()
menu = MenuItems()

on = True

while on:
    options = menu.get_items()
    choice = input(f"What would you like? ({options}): ")
    if choice == "off":
        on = False
    elif choice == "report":
        coffee_maker.report()
        money.report()
    else:
        drink = menu.drink_found(choice)

        if coffee_maker.is_resource_sufficient(drink) and money.accept_deny_payment(drink.cost):
            coffee_maker.make_coffee(drink)
