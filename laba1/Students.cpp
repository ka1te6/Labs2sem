#include "Students.hpp"


Student::Student(const std::string& name, const std::vector<int>& marks)
    : fullName(name), grades(marks) {
}

void Student::print() const {
    std::cout << "ФИО: " << fullName << "Оценки: ";
    for (int grade : grades) {
        std::cout << grade << " ";
    }
    std::cout << std::endl;
}

bool Student::nalichie_stepuhi() const {
    for (int grade : grades) {
        if (grade < 4) {
            return false;
        }
    }
    return true;
}

std::string Student::getName() const {
    return fullName;
}
