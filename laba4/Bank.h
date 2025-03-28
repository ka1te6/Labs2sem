#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <string>


class Bank {
private:
	std::string name_;
	double summ_;
	std::string valuta_;
	double procent_;
public:
	Bank() = default;
	Bank(const std::string& name, double summ, const std::string& valuta, double procent);

	Bank(const Bank& other) = default;
	Bank(Bank&& other) noexcept = default;


	friend std::ostream& operator<<(std::ostream& os, const Bank& deposit);

	bool operator<(const Bank& other) const;

	double getSumm() const { return summ_; }
};

#endif



