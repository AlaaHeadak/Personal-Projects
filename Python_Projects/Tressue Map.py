row1 = ["⬜️","⬜️","⬜️"]
row2 = ["⬜️","⬜️","⬜️"]
row3 = ["⬜️","⬜️","⬜️"]
map = [row1, row2, row3]

print(f"{row1}\n{row2}\n{row3}")

index=input("please enter the index as follows: Horizontal_Vertical\n")


Horizontal=int(index[0])
Vertical=int(index[1])

map[Horizontal-1][Vertical-1]="x"
print(f"{row1}\n{row2}\n{row3}")
