class Phone:
    phone_version = "S10"
    brand_name = "Samsung"
    user_name = ""

    model = "S10+"
    # Getter 
    def get_model(self):
        return self.model
    
    # Setter
    def set_model(self, val):
        self.model = "S10+," + val
        


    # Constructor
    def __init__(self, user):
        self.user_name = user

    def BootLogo(self):
        print("SAMSUNG", self.phone_version)

x = Phone("Aman")
print(x.get_model())
x.set_model("iPhone")
print(x.get_model())