# write mode always write file from the first line so be careful as it can overwrite the content of the file.
# append mode (a+) will solve the problem.
# numpy is used for CSV file.
def main():
    a = []
     # How to read from the file ?

    file = open("sample.txt", "r")
    if file.mode == "r":
        fileContent = file.read()
        s = fileContent.split("\n")
        nums = s[1].split(" ")
        for i in range(len(nums)):
            a.append(int(nums[i]))

    
    a.sort()
    file = open("sample_output.txt", "w+")
    for i in a:
        x = str(i)
        x += " "
        file.write(x)
    file.close()

   


if __name__ == "__main__":
    main()
