'''
Generators are more alike Functions but the main difference is that generators don't compute the all at once its save the stages for that we yield instead of return and to resume the process where it was left is by using the next() i.e next(gen()).

'''


# Definition of the generator to produce even numbers.
def all_even():
    n = 0
    while True:
        yield n
        n += 2

my_gen = all_even()

# Generate the first 5 even numbers.
for i in range(5):
    print(next(my_gen))

# Now go and do some other processing.
do_something = 4
do_something += 3
print(do_something)

# Now go back to generating more even numbers.
for i in range(100):
    print(next(my_gen))