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
	bool operator==(const Bank& other) const {
		return name_ == other.name_ && summ_ == other.summ_ && valuta_ == other.valuta_ && procent_ == other.procent_;
	}

	double getSumm() const { return summ_; }
	std::string getName() const { return name_;}
};
namespace std {
	template <>
	struct hash<Bank> {
		size_t operator()(const Bank& b) const {
			return hash<std::string>()(b.getName()) ^ hash<double>()(b.getSumm());
		}
	};

}


#endif

