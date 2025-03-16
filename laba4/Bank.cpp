#include "Bank.h"


Bank::Bank(const std::string& name, double summ, const std::string& valuta, double procent)
	: name_(name), summ_(summ), valuta_(valuta), procent_(procent) {}

std::ostream& operator<<(std::ostream& os, const Bank& deposit) {

	os << "Имя: " << deposit.name_ 
	<< ", Вклад: " << deposit.summ_ 
	<< ", Валюта: " << deposit.valuta_ 
	<< ", Ставка: " << deposit.procent_ << "%";
	return os;
}

bool Bank::operator<(const Bank& other) const {
	return summ_ < other.summ_;
}
