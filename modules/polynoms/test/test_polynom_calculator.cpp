// Copyright 2019 Malkin Danil

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <map>

#include "include/monom.h"
#include "include/polynom.h"
#include "include/polynoms_calculator.h"

using std::map;

TEST(PolynomTest, Empty_Polynom_Equals_Test) {
    // Arrange
    Polynom p1;
    Polynom p2;

    // Act & Assert
    EXPECT_EQ(p1, p2);
}

TEST(PolynomTest, Polynom_And_Monom_Def_Cnstrctr_Test) {
    // Arrange
    Polynom p1(1.0);
    Polynom p2;
    Monom m;

    // Act
    p2.AddMonom(m);

    // Assert
    EXPECT_EQ(p1, p2);
}

TEST(PolynomTest, Can_Create_With_Int_Coeffs) {
    // Arrange
    map<char, double> vars1{
        { 'x', 2 },
        { 'y', 7 }
    };
    double coeff1 = 2;
    map<char, double> vars2{
        { 'x', 2 },
        { 'y', 7 }
    };
    double coeff2 = 2.0;
    Monom m1(coeff1, vars1);
    Monom m2(coeff2, vars2);

    Polynom p1(m1);
    Polynom p2(m2);

    // Act & Assert
    EXPECT_EQ(p1, p2);
}

TEST(PolynomTest, Monom_Clear_Check) {
    // Arrange
    map<char, double> vars1{
        { 'x', 2 }
    };
    double coeff1 = 2;
    map<char, double> vars2{
        { 'x', 2 }
    };
    double coeff2 = 2;
    Monom m1(coeff1, vars1);
    Monom m2(coeff2, vars2);

    Polynom p1(m1);
    Polynom p2(m2);

    // Act
    Polynom p3 = p1 - p2;

    // Assert
    EXPECT_EQ(p3, Polynom());
}

TEST(PolynomTest, Can_Create_By_Summ) {
    // Arrange
    map<char, double> vars1{
        { 'x', 2 },
    };
    double coeff1 = 2;
    map<char, double> vars2{
        { 'y', 7 }
    };
    double coeff2 = 2;
    map<char, double> vars3{
        { 'z', 5 }
    };
    double coeff3 = -2;
    Monom m1(coeff1, vars1);
    Monom m2(coeff2, vars2);
    Monom m3(coeff3, vars3);
    std::vector<Monom> vm = { m1, m2, m3 };

    Polynom p1(m1);
    Polynom p2(m2);
    Polynom p3(m3);
    Polynom sum(vm);

    // Act
    Polynom res = p1 + p2 + p3;

    // Assert
    EXPECT_EQ(sum, res);
}

TEST(PolynomTest, Can_Multiplication_Polynoms) {
    // Arrange
    Monom m1(5.0);
    map<char, double> vars1{
        { 'y', 7 }
    };
    double coeff1 = 2;
    Monom m2(coeff1, vars1);

    Polynom p1({ m1, m2 });

    map<char, double> vars2{
        { 'x', 2 },
    };
    double coeff2 = 3;
    Monom m3(coeff2, vars2);

    Polynom p2(m3);

    map<char, double> varsres1{
        { 'y', 7 },
        { 'x', 2 }
    };
    double coeffres1 = 6;
    Monom m2res(coeffres1, varsres1);

    map<char, double> varsres2{
        { 'x', 2 },
    };
    double coeffres2 = 15;
    Monom m3res(coeffres2, varsres2);

    Polynom res({ m2res, m3res });

    // Act
    Polynom p = p1 * p2;

    // Assert
    EXPECT_EQ(res, p);
}

TEST(PolynomTest, Can_Division_Polynom) {
    // Arrange
    map<char, double> vars1{
        { 'x', 2 }
    };
    double coeff1 = 2;
    Monom m1(coeff1, vars1);
    Polynom p1(m1);

    Monom m2(1.0);
    map<char, double> vars2{
        { 'y', 2 }
    };
    double coeff2 = 2;
    Monom m3(coeff2, vars2);
    Polynom p2({ m3, m2 });


    // Act
    Polynom p = (p1 * p2) / m1;

    // Assert
    EXPECT_EQ(p2, p);
}

TEST(PolynomTest, Can_Subscr_Polynoms) {
    // Arrange
    map<char, double> vars1{
        { 'x', 2 },
        { 'y', 2 }
    };
    double coeff1 = 6;
    Monom m1(coeff1, vars1);
    Polynom p1(m1);

    double coeff2 = 2;
    Monom m2(coeff2, vars1);
    Polynom p2(m2);

    Monom m3(4, vars1);
    Polynom res(m3);
    // Act
    Polynom p = p1 - p2;

    // Assert
    EXPECT_EQ(res, p);
}

TEST(PolynomTest, Can_Sum_Polynoms) {
    // Arrange
    map<char, double> vars1{
        { 'x', 2 },
        { 'y', 2 }
    };
    double coeff1 = 3;
    Monom m1(coeff1, vars1);
    Monom m(7.0);
    Polynom p1({ m1, m });

    double coeff2 = 2;
    Monom m2(coeff2, vars1);
    Polynom p2(m2);

    Monom m3(5, vars1);
    Polynom res({ m3, m });

    // Act
    Polynom p = p1 + p2;

    // Assert
    EXPECT_EQ(res, p);
}

TEST(PolynomTest, Do_Throw_When_Division_By_Zero) {
    // Arrange
    map<char, double> vars1{
        { 'x', 2 }
    };
    double coeff1 = 2;
    Monom m1(coeff1, vars1);
    Polynom p1(m1);
    Monom m(0.0);

    // Act & Assert
    EXPECT_THROW(p1 / m, std::string);
}

TEST(PolynomTest, Test_Copy_Constructor) {
    // Arrange
    map<char, double> vars1{
        { 'x', 2 }
    };
    double coeff1 = 2;
    Monom m1(coeff1, vars1);
    Polynom p1(m1);


    // Act
    Polynom p2(p1);

    // Assert
    EXPECT_EQ(p1, p2);
}

TEST(PolynomTest, Simple_Pow_Test) {
    // Arrange
    map<char, double> vars1{
        { 'x', 2 }
    };
    double coeff1 = 1;
    Monom m1(coeff1, vars1);
    Polynom p1(m1);
    map<char, double> vars2{
        { 'x', 10 }
    };
    double coeff2 = 5;
    Monom m2(coeff2, vars2);
    Polynom p2(m2);

    map<char, double> vars_res{
        { 'x', 12 }
    };
    double coeff_res = 5;
    Monom mres(coeff_res, vars_res);
    Polynom res(mres);

    // Act
    Polynom p = p1 * p2;

    // Assert
    EXPECT_EQ(res, p);
}

TEST(PolynomTest, To_String_Test) {
    // Arrange
    map<char, double> vars1{
        { 'x', 2 },
        { 'y', 3 },
        { 'z', 4 }
    };
    double coeff1 = 7;
    Monom m1(coeff1, vars1);

    Monom m2(1.0);
    map<char, double> vars2{
        { 'x', 7 },
        { 'y', 5 },
        { 'z', 1 }
    };
    double coeff2 = 32;
    Monom m3(coeff2, vars2);
    Polynom p1({ m3, m1, m2 });

    // Act & Assert
    EXPECT_EQ(std::string("(32x^7y^5z^1) + (7x^2y^3z^4) + (1)"), p1.ToString());
}

TEST(PolynomTest, Copy_Operator_Test) {
    // Arrange
    map<char, double> vars1{
        { 'x', 2 }
    };
    double coeff1 = 1;
    Monom m1(coeff1, vars1);
    Polynom p1(m1);
    Polynom p2;

    // Act
    p2 = p1;

    // Assert
    EXPECT_EQ(p1, p2);
}

TEST(PolynomTest, Not_Equal_Test_Polynom) {
    // Arrange
    map<char, double> vars1{
        { 'x', 2 }
    };
    double coeff1 = 1;
    Monom m1(coeff1, vars1);
    Polynom p1(m1);
    Polynom p;

    // Act
    p = p1 * p1;

    // Assert
    EXPECT_TRUE(p != p1);
}

TEST(PolynomTest, Not_Equal_Test_Monom) {
    // Arrange
    map<char, double> vars1{
        { 'x', 2 }
    };
    double coeff1 = 1;
    Monom m1(coeff1, vars1);
    Monom m2(coeff1+1, vars1);

    // Act & Assert
    EXPECT_TRUE(m1 != m2);
}

TEST(PolynomTest, Not_Equal_Test_Different_Vars_Same_Coff) {
    // Arrange
    map<char, double> vars1{
        { 'x', 2 }
    };
    double coeff1 = 1;
    Monom m1(coeff1, vars1);
    Polynom p1(m1);
    map<char, double> vars2{
        { 'y', 2 }
    };
    double coeff2 = 1;
    Monom m2(coeff2, vars2);
    Polynom p2(m2);

    // Act & Assert
    EXPECT_TRUE(p2 != p1);
}

TEST(PolynomTest, Not_Equal_Test_Different_Sizes) {
    // Arrange
    map<char, double> vars1{
        { 'x', 2 }
    };
    double coeff1 = 1;
    Monom m1(coeff1, vars1);
    Polynom p1(m1);
    map<char, double> vars2{
        { 'y', 2 }
    };
    double coeff2 = 1;
    Monom m2(coeff2, vars2);
    Polynom p2({ m2, m1 });

    // Act & Assert
    EXPECT_FALSE(p2 == p1);
}

TEST(PolynomTest, Different_Vars_Division) {
    // Arrange
    map<char, double> vars1{
        { 'x', 2 }
    };
    double coeff1 = 2;
    Monom m1(coeff1, vars1);
    Polynom p1(m1);
    map<char, double> vars2{
        { 'y', 2 }
    };
    double coeff2 = 2;
    Monom m2(coeff2, vars2);

    map<char, double> vars_res{
        { 'x', 2 },
        { 'y', -2 }
    };
    double coeff_res = 1;
    Monom m_res(coeff_res, vars_res);
    Polynom p_res(m_res);
    // Act
    Polynom p = p1 / m2;

    // Assert
    EXPECT_EQ(p_res, p);
}

TEST(PolynomTest, Different_Monoms_Subscr) {
    // Arrange
    map<char, double> vars1{
        { 'x', 2 }
    };
    double coeff1 = 3;
    Monom m1(coeff1, vars1);
    Polynom p1(m1);
    map<char, double> vars2{
        { 'y', 2 }
    };
    double coeff2 = 3;
    Monom m2(coeff2, vars2);
    Polynom p2(m2);


    map<char, double> vars_res{
        { 'y', 2 }
    };
    double coeff_res = -3;
    Monom m_res(coeff_res, vars_res);
    Polynom res({ m1, m_res });

    // Act
    Polynom p = p1 - p2;

    // Assert
    EXPECT_EQ(res, p);
}

TEST(PolynomTest, Check_Calculate) {
    // Arrange
    map<char, double> vars1{
        { 'x', 2 }
    };
    double coeff1 = 2;
    Monom m1(coeff1, vars1);

    map<char, double> vars2{
        { 'y', 2 }
    };
    double coeff2 = 2;
    Monom m2(coeff2, vars2);
    Polynom p2({ m2, m1 });

    // Act
    double res = p2.CalculateResult({ { 'x', 2 }, { 'y', 2 } });
    // Assert
    EXPECT_EQ(16.0, res);
}

TEST(PolynomTest, Add_Different_Monom) {
    // Arrange
    map<char, double> vars1{
        { 'x', 2 }
    };
    double coeff1 = 3;
    Monom m1(coeff1, vars1);
    Polynom p1(m1);
    map<char, double> vars2{
        { 'y', 2 }
    };
    double coeff2 = 3;
    Monom m2(coeff2, vars2);
    Polynom p2(m2);
    Polynom p3({ m1, m2 });

    // Act
    Polynom p = p1 + p2;
    p1.AddMonom(m2);

    // Assert
    EXPECT_EQ(p, p1);
}

TEST(PolynomTest, Add_Same_Monom) {
    // Arrange
    map<char, double> vars1{
        { 'x', 2 }
    };
    double coeff1 = 3;
    Monom m1(coeff1, vars1);
    Polynom p1(m1);

    map<char, double> vars_res{
        { 'x', 2 }
    };
    double coeff_res = 6;
    Monom m_res(coeff_res, vars_res);
    Polynom p_res(m_res);

    // Act
    p1.AddMonom(m1);

    // Assert
    EXPECT_EQ(p_res, p1);
}

class PolynomCalculatorTest : public ::testing::Test {
 private:
    std::string res_;
    PolynomsCalculator calc_;

 protected:
    void Act(std::vector<std::string> argv_) {
        std::vector<const char*> new_argv_;

        new_argv_.push_back("appname");
        for (size_t i = 0; i < argv_.size(); i++) {
            new_argv_.push_back(argv_[i].c_str());
        }

        const char** argv = &new_argv_.front();
        int argc = static_cast<int>(argv_.size()) + 1;

        res_ = calc_(argc, argv);
    }

    void Assert(std::string exp) {
        EXPECT_EQ(exp, res_);
    }
};

TEST_F(PolynomCalculatorTest, Calculator_Check_Summ) {
    // Arrange
    PolynomsCalculator calc;
    std::string p = "(2x^1) + (2y^1) + (-3z^1)";
    std::vector<std::string> vec_arg = { "2.0x", "2.0y-3z", "+" };

    Act(vec_arg);

    Assert(p);
}

TEST_F(PolynomCalculatorTest, Calculator_Check_Subt) {
    // Arrange
    PolynomsCalculator calc;
    std::string p = "(1t^1x^3) + (-7s^2z^1)";
    std::vector<std::string> vec_arg = { "2.0x^3t-4zs^2", "x^3t+3zs^2", "-" };

    Act(vec_arg);

    Assert(p);
}

TEST_F(PolynomCalculatorTest, Calculator_Check_Multiplication) {
    // Arrange
    PolynomsCalculator calc;
    std::string p = "(9x^2y^1) + (-9x^2z^1)";
    std::vector<std::string> vec_arg = { "3.0x^2", "3.0y-3z", "*" };

    Act(vec_arg);

    Assert(p);
}

TEST_F(PolynomCalculatorTest, Check_Incorrect_Operation) {
    // Arrange
    PolynomsCalculator calc;
    std::string p = "Incorrect input.";
    std::vector<std::string> vec_arg = { "3.0x^2", "3.0y-3z", "$" };

    Act(vec_arg);

    Assert(p);
}

TEST_F(PolynomCalculatorTest, Check_Brackets_Operator_Correct) {
    // Arrange
    PolynomsCalculator calc;
    std::string p = "(9x^2y^1) + (-9x^2z^1)";
    std::vector<std::string> vec_arg = { "3.0x^2", "3.0y-3.0z", "*" };

    Act(vec_arg);

    Assert(p);
}

TEST_F(PolynomCalculatorTest, Check_Brackets_Operator_Incorrect) {
    // Arrange
    PolynomsCalculator calc;
    std::string p = "Error";
    std::vector<const char*> v;
    std::vector<std::string> vec_arg = { "3.0x^2%^*", "3.0y-3.0z", "*" };

    Act(vec_arg);

    Assert(p);
}

TEST_F(PolynomCalculatorTest, Check_Brackets_Operator_Incorrect_1) {
    // Arrange
    PolynomsCalculator calc;
    std::string p = "Error";
    std::vector<std::string> vec_arg = { "3.0x^y2*", "3.0y-3z", "*" };

    Act(vec_arg);

    Assert(p);
}

TEST_F(PolynomCalculatorTest, Check_Brackets_Operator_Incorrect_2) {
    // Arrange
    PolynomsCalculator calc;
    std::string p = "Error";
    std::vector<std::string> vec_arg = { "^3.0x^2y^4", "3.0y-3z", "*" };

    Act(vec_arg);

    Assert(p);
}

TEST_F(PolynomCalculatorTest, Check_Brackets_Operator_Incorrect_3) {
    // Arrange
    PolynomsCalculator calc;
    std::string p = "Error";
    std::vector<std::string> vec_arg = { "3.0^2x^5", "3.0y-3z", "*" };

    Act(vec_arg);

    Assert(p);
}

TEST_F(PolynomCalculatorTest, Check_Brackets_Operator_Incorrect_4) {
    // Arrange
    PolynomsCalculator calc;
    std::string p = "Error";
    std::vector<std::string> vec_arg = { ".3.0x^2", "3.0y-3z", "*" };

    Act(vec_arg);

    Assert(p);
}

TEST_F(PolynomCalculatorTest, Check_Brackets_Operator_Incorrect_5) {
    // Arrange
    PolynomsCalculator calc;
    std::string p = "Error";
    std::vector<std::string> vec_arg = { "3.0x^2z.y^8", "3.0y-3z", "*" };

    Act(vec_arg);

    Assert(p);
}

