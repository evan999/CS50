from cs50 import get_float

while True:
    dollars = get_float("Change owed: ")
    if (dollars > 0):
        break

cents = round(dollars * 100)

quarter = 25
dime = 10
nickel = 5
penny = 1

quarters = cents//quarter
change = cents % quarter

dimes = change//dime
change = change % dime

nickels = change//nickel
change = change % nickel

pennies = change//penny
change = change % penny


total_coins = quarters + dimes + nickels + pennies
print(total_coins)

