#Love Calculator

yourName=input("Please enter your name\n").lower()
#print(yourName)


partnerName=input("Please enter your partner name\n").lower()
#print(partnerName)

compine=yourName+" "+partnerName

t = compine.count("t")
r = compine.count("r")
u = compine.count("u")
e = compine.count("e")
first_digit = t + r + u + e

l = compine.count("l")
o = compine.count("o")
v = compine.count("v")
e = compine.count("e")
second_digit = l + o + v + e

score = int(str(first_digit) + str(second_digit))
print(score)
if (score < 10) or (score > 90):
  print(f"Your score is {score}, you go together like coke and mentos.")
elif (score >= 40) and (score <= 50):
  print(f"Your score is {score}, you are alright together.")
else:
  print(f"Your score is {score}.")