input = "2 3 1 5"
list = input.split(" ")
sortedList = sorted(list)

for i in range(len(sortedList)):
    if str(i+1) != sortedList[i]:
        print(i+1)