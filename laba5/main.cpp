#include <iostream>
#include <fstream>
#include <set>
#include <unordered_set>
#include "Bank.h"

int main() {
    setlocale(LC_ALL, "Russian");

    std::ifstream ifile("input.txt");

    std::set<Bank> bankSet; 
    std::unordered_set<Bank> bankUnorderedSet;

    std::string name, valuta;
    double summ, procent;

    while (ifile >> name >> summ >> valuta >> procent) {
        Bank bank(name, summ, valuta, procent);
        bankSet.insert(bank);
        bankUnorderedSet.insert(bank);
    }

    ifile.close();

    std::ofstream ofile("output.txt");
    ofile << "\nСодержимое std::set : \n" << std::endl;
    for (const auto& bank : bankSet) {
        ofile << bank << '\n';
    }

    ofile << "\nСодержимое std::unordered_set :\n" << std::endl;
    for (const auto& bank : bankUnorderedSet) {
        ofile << bank << '\n';
    }

    ofile.close();
    std::cout << "Данные записаны\n" ;
    return 0;
}
