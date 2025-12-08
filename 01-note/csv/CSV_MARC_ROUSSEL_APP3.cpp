#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

struct Student {

    // ---------- Attributes ---------- //
    std::string first_name, last_name;
    float ex1, ex2, ex3;

    // ---------- Methods ---------- //
    // Method to return the total grades of the student, out of 20.
    float total() const {
        // Adding up the notes (out of 15) and converting to /20
        return (((ex1 + ex2 + ex3)*20.0f)/15.0f);
    }

    // Returns the best exercise as (exercise_number, grade)
    std::tuple<int, float> best_grade() const {
        
        // Grouping grades into a tuple to figure out the maximum
        std::vector<float> all_grades{this->ex1, this->ex2, this->ex3};
        std::vector<float>::iterator max_grade;

        // Fetching the maximum grade
        max_grade = std::max_element(all_grades.begin(), all_grades.end());

        // Getting the position (the exercise number) of this grade
        // found thanks to the distance between the beginning of the vector
        // and this maximum grade
        int exercise_number = std::distance(all_grades.begin(), max_grade) + 1;

        return {exercise_number, *max_grade};
    }

    // Returns the worst exercise as (exercise_number, grade)
    std::tuple<int, float> worst_grade() const{
        
        // Grouping grades into a tuple to figure out the minimum
        std::vector<float> all_grades{this->ex1, this->ex2, this->ex3};
        std::vector<float>::iterator min_grade;

        // Fetching the minimum grade
        min_grade = std::min_element(all_grades.begin(), all_grades.end());

        // Getting the position (the exercise number) of this grade
        // found thanks to the distance between the beginning of the vector
        // and this minimum grade, incremented by 1.
        int exercise_number = std::distance(all_grades.begin(), min_grade) + 1;

        return {exercise_number, *min_grade};
    }
};


// Function to parse a CSV file into Students
std::vector<Student> parse_csv(const std::string& filename) {
    
    // Initializing the Student vector
    std::vector<Student> students_to_return;

    // Building a new file input stream to open the file 'filename'
    std::ifstream file(filename);

    // To store the current line read
    std::string current_line;
    
    // Reading every line of the file
    while (std::getline(file, current_line)) {

        // Parsing the line into a istringstream 
        // to spread the different elements of the CSV
        std::istringstream row(current_line);
        
        // Declaring new Student data that will be stored
        std::string first_name, last_name, ex1, ex2, ex3;

        // Fetching CSV line elements into strings
        if (std::getline(row, first_name, ',') &&
            std::getline(row, last_name, ',') &&
            std::getline(row, ex1, ',') &&
            std::getline(row, ex2, ',') &&
            std::getline(row, ex3)) {
                
                std::cout << first_name << "\n";
                std::cout << last_name << "\n";
                std::cout << ex1 << "\n";
                std::cout << ex2 << "\n";
                std::cout << ex3 << "\n";

                // If there is an error - that throws an invalid_argument, we will skip the line
                try {
                    // Converting data into Student instance and adding it to the vector
                    students_to_return.push_back({first_name, last_name, std::stof(ex1), std::stof(ex2), std::stof(ex3)});
                }
                catch (...) {
                    continue;
                }
            }
    }
    file.close();

    return students_to_return;
}

int main(int, char **) {

    // Tests
    Student s1 = {"Jordan", "Lavenant", 5.0, 3.1, 2.9};
    std::cout << s1.first_name << " " << s1.last_name << "'s total grade is "<< s1.total() << "\n";

    std::tuple<int, float> wg = s1.worst_grade();
    std::cout << s1.first_name << " " << s1.last_name << "'s worst grade is "<< std::get<1>(wg) << " on exercise " << std::get<0>(wg) << "\n";
    
    std::tuple<int, float> bg = s1.best_grade();
    std::cout << s1.first_name << " " << s1.last_name << "'s best grade is "<< std::get<1>(bg) << " on exercise " << std::get<0>(bg) << "\n";

    // Testing the parse_csv function
    std::vector<Student> csv_students = parse_csv("grades.csv");

    for (int i = 0; i < (int)csv_students.size(); i++) {
        std::cout << csv_students[i].first_name << " " << csv_students[i].last_name << " has grades " << csv_students[i].ex1 << ", " << csv_students[i].ex2 << " and " << csv_students[i].ex3 << "\n";
    }

    return 0;
}