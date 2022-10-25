class Menu:
    def __init__(self,drink,water,coffee,milk,cost):
       self.drink=drink
       self.cost=cost
       self.ingredients={"water":water,"coffee":coffee,"milk":milk}


class MenuItems:
    def __init__(self):
       self.menu = [Menu(drink="espresso", water=50, coffee=18, milk=0, cost=1.5),
                    Menu(drink="latte", water=200, coffee=24, milk=150, cost=2.5),
                    Menu(drink="cappuccino", water=250, coffee=24, milk=50, cost=3)]

    def get_items(self):
        available=[]
        for items in self.menu:
            available.append(items.drink)
        return available

    def drink_found(self,order_name):
        for items in self.menu:
            if items.drink==order_name:
                return items
        print("Sorry that item is not available.")


