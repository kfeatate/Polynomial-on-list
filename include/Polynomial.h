#pragma once
#include "List.h"
#include "Monom.h"
#include "Iterator.h"

class Polynomial {
	TList<Monom> polynom;
public:
	Polynomial() {
		polynom = TList<Monom>();
	}
	Polynomial(const Polynomial& pol) {
		this->polynom = pol.polynom;
	}
	bool check(std::string str);
	void push(const Monom& monom);

	Polynomial operator+(Polynomial& pol);
	Polynomial operator-(Polynomial& pol);
	Polynomial operator*(Polynomial& pol);
	Polynomial operator*(double var);
	friend std::istream& operator>>(std::istream& istr, Polynomial& pol) {
		std::string str;
		istr >> str;
		if (!pol.check(str)) {
			throw "not polynomial!";
		}
		std::string str_monom;
		if (str[0] == '-') {
			str_monom = '-';
			str = str.substr(1);
		}
		for (char c : str) {
			if (c == '+') {
				Monom monom;
				std::stringstream iss(str_monom);
				iss >> monom;
				pol.push(monom);
				str_monom = '+';
			}
			else if (c == '-') {
				Monom monom;
				std::stringstream iss(str_monom);
				iss >> monom;
				pol.push(monom);
				str_monom = '-';
		    }
			else {
				str_monom.push_back(c);
			}
		}
		Monom monom;
		std::stringstream iss(str_monom);
		iss >> monom;
		pol.push(monom);
		return istr;
	}
	friend std::ostream& operator<<(std::ostream& ostr, Polynomial& pol) {

		for (auto iter = pol.polynom.begin(); iter != pol.polynom.end(); ++iter) {
			ostr << (*iter);
		}
		return ostr;
	}
};

bool Polynomial::check(std::string str) {
	for (char c : str) {
		if ((std::isdigit(c) == 0) && c != '+' && c != '-' && c != '*' && c != '^' && c != 'x' && c != 'y' && c != 'z') {
			return false;
		}
	}
	return true;
}

void Polynomial::push(const Monom& monom) {
	if (monom.koeff == 0.0) {
		return;
	}
	for (auto it = polynom.begin(); it != polynom.end(); ++it) {
		if ((*it).expr == monom.expr) {
			(*it).koeff = monom.koeff + (*it).koeff;
			return;
		}
	}
	polynom.push_back(monom);
	return;
}

Polynomial Polynomial::operator+(Polynomial& pol) {
	Polynomial res(*this);
	for (auto iter = pol.polynom.begin(); iter != pol.polynom.end(); ++iter) {
		res.push(*iter);
	}
	return res;
}

Polynomial Polynomial::operator-(Polynomial& pol) {
	Polynomial res(*this);
	for (auto iter = pol.polynom.begin(); iter != pol.polynom.end(); ++iter) {
		Monom monom = (*iter);
		monom.koeff = -monom.koeff;
		res.push(monom);
	}
	return res;
}

Polynomial Polynomial::operator*(Polynomial& pol) {
	Polynomial res;
	for (auto iter = pol.polynom.begin(); iter != pol.polynom.end(); ++iter) {
		for (auto it = polynom.begin(); it != polynom.end(); ++it) {
			res.push((*iter) * (*it));
		}
	}
	return res;
 }

Polynomial Polynomial::operator*(double val) {
	Polynomial res(*this);
	for (auto iter = res.polynom.begin(); iter != res.polynom.end(); ++iter) {
		(*iter).koeff *= val;
	}
	return res;
}