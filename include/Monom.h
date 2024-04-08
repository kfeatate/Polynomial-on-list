#pragma once
#include <unordered_map>
#include <iostream>
#include <string>
#include <sstream>
#include "Iterator.h"

class Monom {
protected:
	double koeff;
	std::unordered_map<char, int> expr;
public:
	Monom() : koeff(0), expr({}) {}
	Monom(double _koeff, std::unordered_map<char, int>& _expr) {
		this->koeff = _koeff;
		this->expr = _expr;
	}
	Monom(const Monom& monom) {
		this->koeff = monom.koeff;
		this->expr = monom.expr;
	}
	bool operator==(const Monom& monom);
	Monom operator=(const Monom& monom);
	Monom& operator+(const Monom& monom);
	Monom& operator-(const Monom& monom);
	Monom& operator*(const Monom& monom);
	friend std::istream& operator>>(std::istream& istr, Monom& monom) { 
		std::string str;
		istr >> str;
		std::stringstream ss(str); //рассматриваем строку как поток
		std::string multiplier;
		std::getline(ss, multiplier, '*');
		monom.koeff = std::stod(multiplier);
		while (std::getline(ss, multiplier, '*')) {
			char a = multiplier[0];
			int b = std::stoi(multiplier.substr(2));
			monom.expr[a] = b;
		}
		return istr;
	}
	friend std::ostream& operator<<(std::ostream& ostr, const Monom& monom) {
		ostr << '+' << '(' << monom.koeff << ')';
		for (const auto& iter : monom.expr) {
			ostr << '*' << iter.first << "^" << iter.second;
		}
		return ostr;
	}
	friend class Polynomial;
	template <typename T>
	friend class Iterator;
};

bool Monom::operator==(const Monom& monom) {
	if (expr == monom.expr) {
		return true;
	}
	else return false;
}

Monom Monom::operator=(const Monom& monom) {
	this->koeff = monom.koeff;
	this->expr = monom.expr;
	return *this;
}

Monom& Monom::operator+(const Monom& monom) {
	if (expr == monom.expr) {
		this->koeff += monom.koeff;
		return *this;
	}
	else throw "not equal!";
}

Monom& Monom::operator-(const Monom& monom) {
	if (expr == monom.expr) {
		double res_coeff = koeff - monom.koeff;
		Monom *res = new Monom(res_coeff, expr);
		return *res;
	}
	else throw "not equal!";
}

Monom& Monom::operator*(const Monom& monom) {
	double res_coeff = koeff * monom.koeff;
	Monom *res = new Monom(res_coeff, expr);
	for (auto& iter : monom.expr) {
		res->expr[iter.first] += iter.second;
	}
	return *res;
}