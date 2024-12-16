# Function to perform Quick Sort
def quick_sort(arr, low, high):
    if low < high:
        # Partition the array
        pi = partition(arr, low, high)
        # Recursively sort the subarrays
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)

# Function to partition the array for Quick Sort
def partition(arr, low, high):
    pivot = arr[high]  # Choosing the last element as pivot
    i = low - 1  # Index of smaller element
    for j in range(low, high):
        if arr[j] < pivot:  # If current element is smaller than the pivot
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]  # Swap the pivot element
    return i + 1

# Main function to handle input and display results
def main():
    # Input the number of students
    n = int(input("Enter the number of students: "))
    
    # Input percentages for the students
    percentages = []
    for i in range(n):
        percentage = float(input(f"Enter percentage for student {i + 1}: "))
        percentages.append(percentage)
    
    print("\nOriginal Percentages:")
    print(percentages)
    
    # Sort percentages using Quick Sort
    quick_sort(percentages, 0, len(percentages) - 1)
    
    print("\nPercentages after Sorting (Ascending Order):")
    print(percentages)
    
    # Display top five scores
    print("\nTop Five Scores:")
    for i in range(min(5, len(percentages))):
        print(f"{i + 1}. {percentages[-(i + 1)]:.2f}")  # Print scores in descending order

if __name__ == "__main__":
    main()
