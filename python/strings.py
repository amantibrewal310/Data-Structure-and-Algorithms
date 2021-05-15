score = 233
name = "Aman"

print("Hey", name + ", My Score is", score)

# Format specifier

print("Hey %s, My score is %d"%(name, score))

myStr = "HelloWorld!"

print(myStr.swapcase())

print(myStr.upper())

print(myStr.lower())

print(myStr.isalnum())

userInput = "A   Aman      A"

print(userInput.strip('A'))
print(userInput.lstrip('A'))
print(userInput.rstrip('A'))
# strip() This method is used to remove from start and end
# lstrip() This method is used to remove from the left side
# rstrip() This method is used to remove from the right side