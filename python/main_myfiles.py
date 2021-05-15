# ! https://stackoverflow.com/questions/419163/what-does-if-name-main-do

def main():
    # TODO write file
    # file = open("lco.txt", "a+")
    # for i in range(20):
    #     file.write("this is python code %d \n" %(i))
    # file.close()

    # TODO Read file
    # file = open("lco.txt", "r")
    # if file.mode == 'r':
    #     filecontent = file.read()
    #     print(filecontent)


    # TODO exception

    try:
        myfile = open("lc.txt", "r")
        print("success in reading")
    except IOError:
        print("File does not exists")

    print("Task Done")



if __name__ == "__main__":
    main()