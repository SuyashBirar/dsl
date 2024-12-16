# Function to perform Binary Search
def binary_search(arr, roll_number):
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == roll_number:
            return True
        elif arr[mid] < roll_number:
            low = mid + 1
        else:
            high = mid - 1
    return False

# Function to perform Fibonacci Search
def fibonacci_search(arr, roll_number):
    n = len(arr)
    fib_m_2 = 0  # (m-2)th Fibonacci Number
    fib_m_1 = 1  # (m-1)th Fibonacci Number
    fib = fib_m_1 + fib_m_2  # mth Fibonacci Number
    
    while fib < n:
        fib_m_2 = fib_m_1
        fib_m_1 = fib
        fib = fib_m_1 + fib_m_2
    
    # Start with the largest Fibonacci number smaller than n
    offset = -1
    while fib > 1:
        i = min(offset + fib_m_2, n - 1)
        if arr[i] < roll_number:
            fib = fib_m_1
            fib_m_1 = fib_m_2
            fib_m_2 = fib - fib_m_1
            offset = i
        elif arr[i] > roll_number:
            fib = fib_m_2
            fib_m_1 -= fib_m_2
            fib_m_2 = fib - fib_m_1
        else:
            return True
    if fib_m_1 and arr[offset + 1] == roll_number:
        return True
    return False

# Function to store and sort roll numbers
def store_roll_numbers():
    roll_numbers = []
    n = int(input("Enter the number of students who attended the training program: "))
    for _ in range(n):
        roll_number = int(input("Enter roll number: "))
        roll_numbers.append(roll_number)
    roll_numbers.sort()  # Sort roll numbers in ascending order
    return roll_numbers

# Main program
def main():
    roll_numbers = store_roll_numbers()
    print("Sorted roll numbers of students who attended the training program:", roll_numbers)
    
    roll_number_to_search = int(input("Enter the roll number to search: "))
    
    # Search using Binary Search
    if binary_search(roll_numbers, roll_number_to_search):
        print(f"Student with roll number {roll_number_to_search} attended the training program (Binary Search).")
    else:
        print(f"Student with roll number {roll_number_to_search} did not attend the training program (Binary Search).")
    
    # Search using Fibonacci Search
    if fibonacci_search(roll_numbers, roll_number_to_search):
        print(f"Student with roll number {roll_number_to_search} attended the training program (Fibonacci Search).")
    else:
        print(f"Student with roll number {roll_number_to_search} did not attend the training program (Fibonacci Search).")

# Run the main function
if __name__ == "__main__":
    main()
