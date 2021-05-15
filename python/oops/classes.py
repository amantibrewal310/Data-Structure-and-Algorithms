class Phone:
    phone_version = "S10"
    brand_name = "Samsung"
    user_name = ""

    # Constructor
    def __init__(self, user):
        self.user_name = user

    def BootLogo(self):
        print("SAMSUNG", self.phone_version)

x = Phone("Aman Phone")

print(x.phone_version)
print(x.brand_name)
x.BootLogo()