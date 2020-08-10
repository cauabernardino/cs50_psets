from cs50 import get_float

change = 0
while change <= 0:
    change = get_float("Change owed: ")

cents = change * 100
coins = 0

while cents > 0:
    if cents >= 25:
        cents -= 25
        coins += 1
    elif cents >= 10 and cents < 25:
        cents -= 10
        coins += 1
    elif cents >= 5 and cents < 10:
        cents -= 5
        coins += 1
    elif cents >= 0 and cents < 5:
        cents -= 1
        coins += 1

print(coins)