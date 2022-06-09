from cs50 import get_float

co = 0
coin_count = 0
while (co <= 0):
    co = get_float("Change owed: ")
    
co = co * 100
while co >= 25:
    co -= 25
    coin_count += 1
while co >= 10:
    co -= 10
    coin_count += 1
while co >= 5:
    co -= 5
    coin_count += 1
while co >= 1:
    co -= 1
    coin_count += 1

print(f"{coin_count}")