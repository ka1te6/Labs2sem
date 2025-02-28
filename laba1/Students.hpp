#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <vector>
#include <string>

class Student {
private:
    std::string fullName;
    std::vector<int> grades;

public:
    Student();
    Student(const std::string& name, const std::vector<int>& marks);
    void print() const;
    bool nalichie_stepuhi() const;
    std::string getName() const;
};

#endif 
