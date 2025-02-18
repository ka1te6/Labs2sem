#include "Students.hpp"
#include <fstream>
#include <vector>
#include <sstream>

int main() {
    setlocale(LC_ALL, "Russian");
    
    std::ifstream inputFile("students.txt");
    std::vector<Student> students;


    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string name;
        std::vector<int> grades;
        iss >> std::ws;
        std::getline(iss, name, ','); 
        int grade;
        while (iss >> grade) {
            grades.push_back(grade);
        }
        students.emplace_back(name, grades);
    }

    inputFile.close();

    std::ofstream outputFile("stepuha_students.txt");
    for (const auto& student : students) {
        if (student.nalichie_stepuhi()) {
            student.print();
            outputFile << "Стипендия одобрена для " << student.getName() << ".\n";
        }
    }

    outputFile.close();
    return 0;
}
