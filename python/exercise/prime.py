n = int(input("Enter the number: "))

if n > 1:
    for i in range(2, n):
        if(n%i == 0):
            print("This is not prime number")
            print("%d times %d is %d" %(i,n//i,n))
            break
    else:
        print("The %d is prime" %(n))