class Samsung:
    def __init__(self):
        print("I am Samsung")

    def makeScreen(self):
        print("I make screens")
    
    def test(self):
        print("Screen test: OK")


class Iphone(Samsung):
    def __init__(self):
        print("I am iPhone")
        super().__init__()
    
    def a3chips(self):
        print("I make A3 bionic chips")
    
    def itest(self):
        print("A3 test: OK")
        # import the another function
        super().test()
    
    # method overriding
    def makeScreen(self):
        print("I make screen: Apple")


user = Iphone()

user.a3chips()
user.makeScreen()
user.itest()