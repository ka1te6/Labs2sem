#include "Bank.h"


Bank::Bank(const std::string& name, double summ, const std::string& valuta, double procent)
	: name_(name), summ_(summ), valuta_(valuta), procent_(procent) {}

std::ostream& operator<<(std::ostream& os, const Bank& deposit) {

	os << "���: " << deposit.name_ 
	<< ", �����: " << deposit.summ_ 
	<< ", ������: " << deposit.valuta_ 
	<< ", ������: " << deposit.procent_ << "%";
	return os;
}

bool Bank::operator<(const Bank& other) const {
	return summ_ < other.summ_;
}