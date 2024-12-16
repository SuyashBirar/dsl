def linearSearch(I, key):
    for i in range(len(I)):
        if I[i] == key:
            return i
    return -1

def sentinelSearch(I, key):
    ISize = len(I)
    I.append(key)  # Append the key to the end of the list

    i = 0
    while I[i] != key:
        i += 1

    if i == ISize:
        return -1
    else:
        return i

NUMBERS = []
n = int(input("Enter the number of students who attended training program: "))
print("\n")

for i in range(n):
    temp = int(input("Enter the roll numbers : "))
    NUMBERS.append(temp)

key = int(input("\nEnter Roll Number to search: "))

print("\n")

print("Roll Number", key, "at index using linear search:", linearSearch(NUMBERS, key))
print("Roll Number", key, "at index using sentinel search:", sentinelSearch(NUMBERS, key))
