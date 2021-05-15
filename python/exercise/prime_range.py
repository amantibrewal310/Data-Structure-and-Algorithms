lower_range = int(input("Enter the lower bound:"))
upper_range = int(input("Enter the upper bound: "))

for n in range(lower_range, upper_range):
    if n > 1:
        for i in range(2, n):
            if(n%i == 0):
                break
        else:
            print(n)