number = int( input("Enter the number:") )
factorial = 1
if number >= 0:
    for i in range(1,number+1):
        factorial *= i
    else:
        print(factorial)
else:
    print(0)