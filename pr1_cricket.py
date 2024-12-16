# Define the groups of students
cricket = ["Shubham", "Suyash" ,"Yash", "Aditya"]
badminton = ["Suyash", "Krishna", "Darshan", "Yash"]
football = ["Pratik", "Harsh", "Atharva"]

# Function to remove duplicates from a list
def remove_duplicates(lst):
    """Remove duplicate entries from a list."""
    unique = []
    for item in lst:
        if item not in unique:
            unique.append(item)
    return unique

# Function to compute students who play both cricket and badminton
def both_cricket_and_badminton(cricket, badminton):
    """Find students who play both cricket and badminton."""
    result = []
    for student in cricket:
        if student in badminton:
            result.append(student)
    return remove_duplicates(result)

# Function to compute students who play either cricket or badminton but not both
def either_cricket_or_badminton_not_both(cricket, badminton):
    """Find students who play either cricket or badminton but not both."""
    result = []
    for student in cricket:
        if student not in badminton:
            result.append(student)
    for student in badminton:
        if student not in cricket:
            result.append(student)
    return remove_duplicates(result)

# Function to compute students who play neither cricket nor badminton
def neither_cricket_nor_badminton(cricket, badminton, football):
    """Find the number of students who play neither cricket nor badminton."""
    all_students = remove_duplicates(cricket + badminton + football)
    cricket_or_badminton = remove_duplicates(cricket + badminton)
    result = []
    for student in all_students:
        if student not in cricket_or_badminton:
            result.append(student)
    return len(result)

# Function to compute students who play cricket and football but not badminton
def cricket_and_football_not_badminton(cricket, football, badminton):
    """Find the number of students who play cricket and football but not badminton."""
    result = []
    for student in cricket:
        if student in football and student not in badminton:
            result.append(student)
    return len(remove_duplicates(result))

# Remove duplicates from the original lists
cricket = remove_duplicates(cricket)
badminton = remove_duplicates(badminton)
football = remove_duplicates(football)

# Compute results
students_both = both_cricket_and_badminton(cricket, badminton)
students_either_not_both = either_cricket_or_badminton_not_both(cricket, badminton)
students_neither = neither_cricket_nor_badminton(cricket, badminton, football)
students_cricket_football_not_badminton = cricket_and_football_not_badminton(cricket, football, badminton)

# Print results
print("a) Students who play both cricket and badminton:", students_both)
print("b) Students who play either cricket or badminton but not both:", students_either_not_both)
print("c) Number of students who play neither cricket nor badminton:", students_neither)
print("d) Number of students who play cricket and football but not badminton:", students_cricket_football_not_badminton)
