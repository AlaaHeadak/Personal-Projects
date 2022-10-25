class Money:
    COIN_VALUES = {
        "quarters": 0.25,
        "dimes": 0.10,
        "nickles": 0.05,
        "pennies": 0.01
    }

    def __init__(self):
        self.profit = 0
        self.money_received = 0

    def report(self):
        print(f"Amount available at the machine= {self.profit}$")

    def money_calculation(self):
        for coins in self.COIN_VALUES:
            self.money_received += int(input(f"How many {coins}?: ")) * self.COIN_VALUES[coins]
        return self.money_received

    def accept_deny_payment(self,cost):
        self.money_calculation()
        if self.money_received>=cost:
            change= round(self.money_received-cost,2)
            print(f"Here is {change}$ in change.")
            self.profit += cost
            self.money_received = 0
            return True
        else:
            print("Sorry that's not enough money. Money refunded.")
            self.money_received = 0
            return False
