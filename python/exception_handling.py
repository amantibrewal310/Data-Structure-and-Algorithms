# TODO exception

try:
    myfile = open("sample.txt", "r")
    print("Success in reading")
except IOError:
    print("File does not exits")
