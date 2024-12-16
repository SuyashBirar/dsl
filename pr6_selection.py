# Function to perform Selection Sort
def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        # Swap the found minimum element with the first element
        arr[i], arr[min_index] = arr[min_index], arr[i]

# Function to perform Bubble Sort
def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                # Swap if the element found is greater than the next element
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

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

    # Sorting and displaying using Selection Sort
    selection_sorted = percentages.copy()
    selection_sort(selection_sorted)
    print("\nPercentages sorted using Selection Sort:", selection_sorted)
    display_top_five(selection_sorted)

    # Sorting and displaying using Bubble Sort
    bubble_sorted = percentages.copy()
    bubble_sort(bubble_sorted)
    print("\nPercentages sorted using Bubble Sort:", bubble_sorted)
    display_top_five(bubble_sorted)

# Run the main function
if __name__ == "__main__":
    main()
