# Function to compute the average score of the class
def average_score(marks):
    total = 0
    for mark in marks:
        total += mark
    return total / len(marks) if marks else 0

# Function to compute the highest and lowest score in the class
def highest_and_lowest_score(marks):
    if not marks:
        return None, None  # Return None if the list is empty
    highest = marks[0]
    lowest = marks[0]
    for mark in marks:
        if mark > highest:
            highest = mark
        if mark < lowest:
            lowest = mark
    return highest, lowest

# Function to count students absent for the test
def count_absent_students(marks):
    return marks.count(-1)  # Assuming -1 is used to denote absent students

# Function to display the mark with the highest frequency
def mark_with_highest_frequency(marks):
    frequency = {}
    for mark in marks:
        if mark != -1:  # Exclude absent students
            frequency[mark] = frequency.get(mark, 0) + 1
    max_freq = max(frequency.values(), default=0)
    most_frequent_marks = [mark for mark, freq in frequency.items() if freq == max_freq]
    return most_frequent_marks, max_freq

# Input marks for N students
N = int(input("Enter the number of students: "))
marks = []
for i in range(N):
    mark = int(input(f"Enter marks for student {i+1} (-1 if absent): "))
    marks.append(mark)

# Compute results
avg = average_score([mark for mark in marks if mark != -1])  # Exclude absent students for average
highest, lowest = highest_and_lowest_score([mark for mark in marks if mark != -1])  # Exclude absent students
absent_count = count_absent_students(marks)
most_frequent_marks, max_freq = mark_with_highest_frequency(marks)

# Print results
print(f"Average score of the class: {avg:.2f}")
print(f"Highest score in the class: {highest}")
print(f"Lowest score in the class: {lowest}")
print(f"Number of students absent for the test: {absent_count}")
if max_freq > 0:
    print(f"Marks with the highest frequency: {most_frequent_marks} (Frequency: {max_freq})")
else:
    print("No valid marks available to calculate frequency.")
