def add(n1, n2):
  return n1 + n2

def subtract(n1, n2):
  return n1 - n2

def multiply(n1, n2):
  return n1 * n2

def divide(n1, n2):
  return n1 / n2

operations = {
  "+": add,
  "-": subtract,
  "*": multiply,
  "/": divide
}

def calculator():
    num1=float(input("Enter your 1st number "))

    for operators in operations:
        print(operators)

    should_continue = True
    while should_continue:

        operator= input("Enter your desired operation from the list above  ")
        num2=float(input("Enter your 2nd number "))

        chosen_operation=operations[operator]
        answer1=chosen_operation(num1,num2)
        print(f"{num1} {operator} {num2} = {answer1}")

        chosen_mode=int(input(" press:1 to use the last answer in another operation\n press:2 for a brand new operation\n press:3 to terminate the program \n"))
        if chosen_mode==1:
            num1=answer1
        elif chosen_mode==3:
            should_continue = False

calculator()
