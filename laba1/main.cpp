#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Students.hpp"



int main() {
	setlocale(LC_ALL, "Russian");

	const int MAX_STUDENTS = 100;

	std::ifstream inputFile("students.txt");
	Student* students = new Student[MAX_STUDENTS];
	int studentCount = 0;

	std::vector<Student> studentsVector;

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

		if (studentCount < MAX_STUDENTS) {
			students[studentCount] = Student(name, grades);
			studentCount++;
		}

		studentsVector.emplace_back(name, grades);
	}

	inputFile.close();

	std::ofstream outputFile("stepuha_students.txt");


	outputFile << "=== Проверка студентов (Массив) ===\n";
	for (int i = 0; i < studentCount; i++) {
		if (students[i].nalichie_stepuhi()) {
			students[i].print();
			outputFile << "Стипендия одобрена для " << students[i].getName() << ".\n";
		}
	}

	outputFile << "\n=== Проверка студентов (Вектор) ===\n";
	for (const auto& student : studentsVector) {
		if (student.nalichie_stepuhi()) {
			student.print();
			outputFile << "Стипендия одобрена для " << student.getName() << ".\n";
		}
	}

	outputFile.close();
	delete[] students;
	return 0;
}
