'''
LEGB
Local, Enclosing, Global, Built-in
'''

# x = 'global x'

# def test():
#     x = 'local x'
#     # print(y)
#     print(x)

# test()
# print(x)

# def test1():
#     global x
#     x = 'local x'
#     print(x)

# test1()
# print(x)

# def min():
#     pass

# m = min([5, 1, 4])
# print(m)

# import builtins
# print( dir(builtins) ) # Print all builtin function

# Enclosing Scope

# def outer():
#     x = 'outer x'

#     def inner():
#         x = 'inner x'
#         print(x)

#     inner()
#     print(x)

# outer()

def outer():
    x = 'outer x'

    def inner():
        nonlocal x
        x = 'inner x'
        print(x)

    inner()
    print(x)

outer()