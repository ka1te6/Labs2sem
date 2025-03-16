#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>
#include "Bank.h"

int main() {

	setlocale(LC_ALL, "Russian");

	std::list<Bank> deposits;

	std::ifstream ifile("input.txt");

	std::string name, valuta;
	double summ, procent;

	while (ifile >> name >> summ >> valuta >> procent) {
		deposits.emplace_back(Bank(name, summ, valuta, procent));
	}

	ifile.close();

	std::ofstream ofile("output.txt");

	for (const auto& deposit : deposits) {
		ofile << deposit << '\n';
	}

	deposits.sort();

	ofile << "\nОтсортированный список:\n";
	for (const auto& deposit : deposits) {
		ofile << deposit << '\n';
	}

	std::vector<Bank> depositsVector;
	std::copy(deposits.begin(), deposits.end(), std::back_inserter(depositsVector));

	ofile << ("\nКопия списка в Вектор:\n");
	for (const auto& deposit : depositsVector) {
		ofile << deposit << '\n';
	}

	ofile.close();
	std::cout << "Данные записаны";

	return 0;
}

