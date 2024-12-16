# Function to perform Insertion Sort
def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        # Move elements of arr[0..i-1] that are greater than key to one position ahead
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

# Function to perform Shell Sort
def shell_sort(arr):
    n = len(arr)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            # Perform gap-based insertion sort
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2

# Function to display the top five scores
def display_top_five(arr):
    top_five = arr[-5:]  # Get the last 5 elements from the sorted array
    top_five.reverse()   # Reverse to display in descending order
    print("Top five scores:", top_five)

# Main program
def main():
    # Input: Number of students and their percentages
    n = int(input("Enter the number of students: "))
    percentages = []
    for _ in range(n):
        percentage = float(input("Enter the percentage of the student: "))
        percentages.append(percentage)

    # Sorting and displaying using Insertion Sort
    insertion_sorted = percentages.copy()
    insertion_sort(insertion_sorted)
    print("\nPercentages sorted using Insertion Sort:", insertion_sorted)
    display_top_five(insertion_sorted)

    # Sorting and displaying using Shell Sort
    shell_sorted = percentages.copy()
    shell_sort(shell_sorted)
    print("\nPercentages sorted using Shell Sort:", shell_sorted)
    display_top_five(shell_sorted)

# Run the main function
if __name__ == "__main__":
    main()
