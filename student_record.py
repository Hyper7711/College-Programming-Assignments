def get_marks(num_students):  # first funtion 
    marks = []  # empty list to stored the marks. 
    for _ in range(num_students):  #  create a loop through the number of student 
        while True:
            mark = input("Enter the marks for student (or 'A' if absent): ").strip()
            if mark.upper() == 'A':
                marks.append(None)
                break
            else:
                try:  # Attempts convert the input to an integer
                    marks.append(int(mark))  # if the input value is an integer then appens to the list.
                    break                    
                except ValueError:
                    print("Invalid input. Please enter a valid mark or 'A' for absent.")
    return marks


def calculate_average(marks):  # second function
    present_marks = [mark for mark in marks if mark is not None]  # 'for'starts loop,iterates every element in the list 'marks'.
    if present_marks:                                             # conditional 'if' checks that marks cannot be none.
        return sum(present_marks) / len(present_marks)  # input formula for avg marks
    return 0


def find_highest_lowest(marks):  # third function
    present_marks = [mark for mark in marks if mark is not None]
    if present_marks:
        return max(present_marks), min(present_marks)
    return None, None


def count_absent(marks):  # fourth function
    return marks.count(None)


def find_highest_frequency(marks):  # fifth function
    from collections import Counter  # import 'counter' to count the occurrence of th elements.
    present_marks = [mark for mark in marks if mark is not None] # creates the list of marks excluding none values.
    if present_marks:
        mark_counts = Counter(present_marks)  # apply conter to the mark's list.
        most_common_mark = mark_counts.most_common(1)[0]  # finds the most repeated count of marks.
        return most_common_mark 
    return None


def main():
    num_students = int(input("Enter the number of students: ")) # taking input of number if students.
    marks = get_marks(num_students)  # calls the first function

    avg_score = calculate_average(marks)   # calls the second function
    print(f"Average score of the class: {avg_score:.2f}")

    highest, lowest = find_highest_lowest(marks)  # calls the third function 
    if highest is not None and lowest is not None:
        print(f"Highest score in the class: {highest}")
        print(f"Lowest score in the class: {lowest}")
    else:
        print("No scores available to determine highest and lowest marks.")

    absent_count = count_absent(marks)  # calls the fourth function
    print(f"Count of students absent for the test: {absent_count}")

    most_frequent_mark = find_highest_frequency(marks)  # calls the fifth function
    if most_frequent_mark:
        print(f"Mark with highest frequency: {most_frequent_mark[0]} (Frequency: {most_frequent_mark[1]})")
    else:
        print("No marks available to calculate frequency.")  # if no marks are available 

if __name__ == "__main__":   # Runs the main function if the script is executed directly.
    main()