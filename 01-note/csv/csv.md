# C++ - CSV

## Submission Guidelines

This lab must be completed **individually**.
You may search for information online. For this, prefer using [cppreference](https://cppreference.com).
**Any use of artificial intelligence tools or services, even if integrated in your IDE, is strictly prohibited and will result in a grade of 0, with no possibility of appeal.**

Your submission must consist of a single `cpp` file, renamed as `CSV_FIRSTNAME_LASTNAME_CLASSGROUP.cpp`, to be sent to your instructor at the following email address:

**Email:** joel.falcou@lisn.fr

**Warning:** Do **not** modify the signature of the functions already provided.

**Submission deadline:** The assignment must be sent by email **BEFORE** the end of the session. Every 5 minutes of delay will cost **-2 points**. Make sure to verify that the email has been sent correctly before leaving.

Your email subject must be `[CLASSGROUP] TP CSV LASTNAME FirstName`.

**Warning:** Do not send executable files by email. The university mail service will block them. The late submission penalty will still apply in this case.

## Objective

In this exercise, you will implement a C++ program that reads student grades from a CSV file, parses the data, and performs various statistical analyses using STL algorithms.

## Input File Format

The CSV file `grades.csv` contains student grades with the following columns:

- `last_name`: Student's last name (string)
- `first_name`: Student's first name (string)
- `ex1`, `ex2`, `ex3`: Grades for each exercise (floats from 0 to 5, in 0.25 increments)

## Requirements

### Part 1: Data Structure

Define a `Student` struct to hold the parsed data for each student.
Add the following methods to the struct:

```cpp
// Returns the total grade converted to /20
float total() const;

// Returns the best exercise as (exercise_number, grade)
std::tuple<int, float> best_grade() const;

// Returns the worst exercise as (exercise_number, grade)
std::tuple<int, float> worst_grade() const;
```

### Part 2: CSV Parsing

Implement a function to read and parse the CSV file:

```cpp
std::vector<Student> parse_csv(const std::string& filename);
```

**Hint:** You can use `std::ifstream` and `std::getline` to read the file line by line.

### Part 3: Statistical Analysis with STL Algorithms

Using **STL algorithms** (from `<algorithm>` and `<numeric>`), implement the following:

1. **Best/Worst Student**: Find the students with the highest and lowest total grade
2. **Class Average**: Calculate the average grade (out of 20) for the entire class
3. **Median Grade**: Calculate the median grade (out of 20)
4. **Passing Students**: Count students who passed (grade ≥ 10/20)
5. **Top/Bottom 5%**: Calculate the average grade of the top 5% and bottom 5% of students

### Part 4: Output

Display the results of all computations from Part 3 in a clear format.

## Constraints

- You **must** use STL algorithms wherever possible (no raw loops for computations)
- Handle file errors gracefully wherever possible (file not found, invalid format, values out of range, etc...)

## Provided Files

- `grades.csv` - Sample data file with student entries

## Grading

Your code will be evaluated not only on correctness but also on **code quality**: readability, proper use of C++ idioms, code organization, appropriate use of STL algorithms and performance.
