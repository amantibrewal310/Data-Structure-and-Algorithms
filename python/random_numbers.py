import random

print(random.choice(range(100))) #Select random number from 0-100.

print(random.randrange(1,100,2))

print(random.random()) # Genrate the random number between 0-1. 

# Their is no such thing random actually behind the random an algo is implemented from which we can predict the number.

random.seed(10) # For controlling the random value i.e random value will genrate for the first time then its value gets fixed. For example random.seed(10) will give 0.57140 and seed(2) will give 0.9560 everytime.
print(random.random())

list_numbers = [22, 56, 487, 4489]

random.shuffle(list_numbers) # shuffle the list own its memory itself not require extraspace.

print(list_numbers)