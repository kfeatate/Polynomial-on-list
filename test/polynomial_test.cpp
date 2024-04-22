#include "gtest.h"
#include "Polynomial.h"

TEST(Monom, can_create_monom) {
	EXPECT_NO_THROW(Monom monom());
}

TEST(Monom, can_add_monoms) {
	std::unordered_map<char, int> expr;
	expr['x'] = 2;
	expr['y'] = 3;
	expr['z'] = 4;
	Monom m1(2, expr);
	Monom m2(1, expr);
	Monom res = m1 + m2;
	Monom proverka(3, expr);
	EXPECT_EQ(res, proverka);
}

TEST(Monom, can_sub_monoms) {
	std::unordered_map<char, int> expr;
	expr['x'] = 2;
	expr['y'] = 3;
	expr['z'] = 4;
	Monom m1(2, expr);
	Monom m2(1, expr);
	Monom res = m1 - m2;
	Monom proverka(1, expr);
	EXPECT_EQ(res, proverka);
}

TEST(Monom, can_mult_monoms) {
	std::unordered_map<char, int> expr;
	expr['x'] = 1;
	expr['y'] = 1;
	expr['z'] = 0;
	Monom m1(2, expr);
	std::unordered_map<char, int> expr2;
	expr2['x'] = 2;
	expr2['y'] = 0;
	expr2['z'] = 1;
	Monom m2(3, expr2);
	Monom res = m1 * m2;
	std::unordered_map<char, int> expr_res;
	expr_res['x'] = 3;
	expr_res['y'] = 1;
	expr_res['z'] = 1;
	Monom proverka(6, expr_res);
	EXPECT_EQ(res, proverka);
}

TEST(Polynomial, can_create_polynomial) {
	EXPECT_NO_THROW(Polynomial Polynom());
}

TEST(Polynomial, can_push_monom) {
	std::unordered_map<char, int> expr = { {'x', 2}, {'y', 3}, {'z', 4} };
	Monom monom = Monom(-2, expr);
	Polynomial pol;
	EXPECT_NO_THROW(pol.push(monom));
}

TEST(Polynomial, can_folding_polynomials) {
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

TEST(Polynomial, can_sub_polynomials) {
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

TEST(Polynomial, can_multiplay_polynomial_on_scalar) {
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