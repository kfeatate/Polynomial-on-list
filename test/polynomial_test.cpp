#include "gtest.h"
#include "Polynomial.h"

TEST(Polynomial, can_create_monom) {
	EXPECT_NO_THROW(Polynomial Polynom());
}

TEST(Polynomial, can_push_monom) {
	std::unordered_map<char, int> expr = { {'x', 2}, {'y', 3}, {'z', 4} };
	Monom monom = Monom(-2, expr);
	Polynomial pol;
	EXPECT_NO_THROW(pol.push(monom));
}

TEST(Polynomial, can_folding) {
	std::unordered_map<char, int> expr1 = { {'x', 2}, {'y', 3}, {'z', 4} };
	std::unordered_map<char, int> expr2 = { {'x', 1}, {'y', 5}, {'z', 6}};
	Monom monom1 = Monom(-2, expr1);
	Monom monom2 = Monom(3, expr2);
	Polynomial pol1;
	pol1.push(monom1);
	pol1.push(monom2);
	std::unordered_map<char, int> expr3 = { {'x', 8}, {'y', 5}, {'z', 2} };
	Monom monom3 = Monom(5, expr1);
	Monom monom4 = Monom(4, expr3);
	Polynomial pol2;
	pol2.push(monom3);
	pol2.push(monom4);
	Polynomial res = pol1 + pol2;
	Monom monom11 = Monom(3, expr1);
	Polynomial proverka;
	proverka.push(monom11);
	proverka.push(monom2);
	proverka.push(monom4);
	ASSERT_EQ(res, proverka);
}

TEST(Polynomial, can_sub) {
	std::unordered_map<char, int> expr1 = { {'x', 2}, {'y', 3}, {'z', 4} };
	std::unordered_map<char, int> expr2 = { {'x', 1}, {'y', 5}, {'z', 6} };
	Monom monom1 = Monom(-2, expr1);
	Monom monom2 = Monom(3, expr2);
	Polynomial pol1;
	pol1.push(monom1);
	pol1.push(monom2);
	std::unordered_map<char, int> expr3 = { {'x', 8}, {'y', 5}, {'z', 2} };
	Monom monom3 = Monom(5, expr1);
	Monom monom4 = Monom(4, expr3);
	Polynomial pol2;
	pol2.push(monom3);
	pol2.push(monom4);
	Polynomial res = pol1 - pol2;
	Monom monom11 = Monom(-7, expr1);
	Monom monom5 = Monom(-4, expr3);
	Polynomial proverka;
	proverka.push(monom11);
	proverka.push(monom2);
	proverka.push(monom5);
	ASSERT_EQ(res, proverka);
}

TEST(Polynomial, can_multiply_polynomials) {
	std::unordered_map<char, int> expr1 = { {'x', 2,}, {'y', 1}, {'z', 0} };
	std::unordered_map<char, int> expr2 = { {'x', 1}, {'y', 2}, {'z', 0} };
	Monom monom1 = Monom(1, expr1);
	Monom monom2 = Monom(1, expr2);
	Polynomial pol1;
	pol1.push(monom1);
	pol1.push(monom2);
	std::unordered_map<char, int> expr3 = { {'x', 2}, {'y', 0}, {'z', 0} };
	std::unordered_map<char, int> expr4 = { {'x', 2}, {'y', 2}, {'z', 2} };
	Monom monom3 = Monom(2, expr2);
	Monom monom4 = Monom(-1, expr4);
	Polynomial pol2;
	pol2.push(monom3);
	pol2.push(monom4);
	Polynomial res = pol1 * pol2; 
	std::unordered_map<char, int> expr11 = { {'x', 3}, {'y', 3}, {'z', 0} };
	std::unordered_map<char, int> expr12 = { {'x', 2}, {'y', 4}, {'z', 0} };
	std::unordered_map<char, int> expr13 = { {'x', 4}, {'y', 3}, {'z', 2} };
	std::unordered_map<char, int> expr14 = { {'x', 3}, {'y', 4}, {'z', 2} };
	Monom monom11 = Monom(2, expr11);
	Monom monom12 = Monom(2, expr12);
	Monom monom13 = Monom(-1, expr13);
	Monom monom14(-1, expr14);
	Polynomial proverka;
	proverka.push(monom11);
	proverka.push(monom12);
	proverka.push(monom13);
	proverka.push(monom14);
	ASSERT_EQ(res, proverka);
}

TEST(Polynomial, can_multiplay_on_scalar) {
	std::unordered_map<char, int> expr1 = { {'x', 2}, {'y', 3}, {'z', 4} };
	std::unordered_map<char, int> expr2 = { {'x', 1}, {'y', 5}, {'z', 6} };
	Monom monom1 = Monom(-2, expr1);
	Monom monom2 = Monom(3, expr2);
	Polynomial pol1;
	pol1.push(monom1);
	pol1.push(monom2);
	Polynomial res = pol1 * 2;
	Monom monom3 = Monom(-4, expr1);
	Monom monom4 = Monom(6, expr2);
	Polynomial proverka;
	proverka.push(monom3);
	proverka.push(monom4);
	ASSERT_EQ(res, proverka);
}