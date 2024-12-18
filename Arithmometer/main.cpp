#include "expression_evaluator.h"

int main(){    
    //括号不匹配
    std::cout << "Test for incorrect bracket matching:" << std::endl << std::endl;

    std::cout << "Input: " << std::string("1+2*(3-(4*2)))/2") << std::endl;
    infixExpression<int> exp1("1+2*(3-(4*2)))/2");
    std::cout << "Ans: " << exp1.calculate() << std::endl << std::endl;

    std::cout << "Input: " << std::string("1+2*((3-(4*2))/2") << std::endl;
    infixExpression<int> exp2("1+2*((3-(4*2))/2");
    std::cout << "Ans: " << exp2.calculate() << std::endl << std::endl;

    std::cout << "--------------------------------------------------------------------" << std::endl;
    //运算符使用不正确
    std::cout << "Test for incorrect operator uses:" << std::endl << std::endl;

    std::cout << "Input: " << std::string("(-)") << std::endl;
    infixExpression<int> exp100("(-)");
    std::cout << exp100.calculate() << std::endl << std::endl;

    std::cout << "Input: " << std::string("1+2*3-4/+2") << std::endl;
    infixExpression<double> exp3("1+2*3-4/+2");
    std::cout << "Ans: " << exp3.calculate() << std::endl << std::endl;

    std::cout << "Input: " << std::string("1+2*3-4/2-") << std::endl;
    infixExpression<double> exp4("1+2*3-4/2-");
    std::cout << "Ans: " << exp4.calculate() << std::endl << std::endl;

    std::cout << "Input: " << std::string("1+2--*3-4/2") << std::endl;
    infixExpression<double> exp5("1+2--*3-4/2");
    std::cout << "Ans: " << exp5.calculate() << std::endl << std::endl;

    std::cout << "Input: " << std::string("1@2") << std::endl;
    infixExpression<double> exp17("1@2");
    std::cout << "Ans: " << exp17.calculate() << std::endl << std::endl;

    std::cout << "Input: " << std::string("2=1+1") << std::endl;
    infixExpression<double> exp18("2=1+1");
    std::cout << "Ans: " << exp18.calculate() << std::endl << std::endl;

    std::cout << "--------------------------------------------------------------------" << std::endl;
    //科学计数法指数或底数缺失
    std::cout << "Test for missing base or exponent in scientific notation:" << std::endl << std::endl;

    std::cout << "Input: " << std::string("1.2E") << std::endl;
    infixExpression<double> exp188("1.2E");
    std::cout << "Ans: " << exp188.calculate() << std::endl << std::endl;

    std::cout << "Input: " << std::string("e-1") << std::endl;
    infixExpression<double> exp189("e-1");
    std::cout << "Ans: " << exp189.calculate() << std::endl << std::endl;

    std::cout << "--------------------------------------------------------------------" << std::endl;
    //被零除
    std::cout << "Test for division is zero:" << std::endl << std::endl;

    std::cout << "Input: " << std::string("1+2*3-4/0+2") << std::endl;
    infixExpression<double> exp6("1+2*3-4/0+2");
    std::cout << "Ans: " << exp6.calculate() << std::endl << std::endl;

    std::cout << "--------------------------------------------------------------------" << std::endl;
    //小数点误用测试
    std::cout << "Test for decimal point misuse:" << std::endl << std::endl;

    std::cout << "Input: " << std::string("1.2.3+1") << std::endl;
    infixExpression<double> exp190("1.2.3+1");
    std::cout << "Ans: " << exp190.calculate() << std::endl << std::endl;

    std::cout << "Input: " << std::string("..2*1") << std::endl;
    infixExpression<double> exp191("..2*1");
    std::cout << "Ans: " << exp191.calculate() << std::endl << std::endl;

    std::cout << "--------------------------------------------------------------------" << std::endl;
    //负号处理测试
    std::cout << "Test for negative number:" << std::endl << std::endl;

    std::cout << "Input: " << std::string("-1+-(1*-2)--5") << std::endl;
    infixExpression<double> exp7("-1+-(1*-2)--5");
    std::cout << "Ans: " << exp7.calculate() << std::endl << std::endl;

    std::cout << "Input: " << std::string("1+2*-(-3)-4/2") << std::endl;
    infixExpression<double> exp8("1+2*--3-4/2");
    std::cout << "Ans: " << exp8.calculate() << std::endl << std::endl;

    std::cout << "--------------------------------------------------------------------" << std::endl;
    //小数测试
    std::cout << "Test for decimal number:" << std::endl << std::endl;

    std::cout << "Input: " << std::string("1-.1/.01*(.2+.1)") << std::endl;
    infixExpression<double> exp9("1-.1/.01*(.2+.1)");
    std::cout << "Ans: " << exp9.calculate() << std::endl << std::endl;

    std::cout << "Input: " << std::string("1-0.1/.01*(.2+.1)") << std::endl;
    infixExpression<double> exp10("1-0.1/.01*(.2+.1)");
    std::cout << "Ans: " << exp10.calculate() << std::endl << std::endl;

    std::cout << "Input: " << std::string("1-.1/-.01*(.2+-.1)") << std::endl;
    infixExpression<double> exp11("1-.1/-.01*(.2+-.1)");
    std::cout << "Ans: " << exp11.calculate() << std::endl << std::endl;

    std::cout << "--------------------------------------------------------------------" << std::endl;
    //科学计数法测试
    std::cout << "Test for scientific notation:" << std::endl << std::endl;

    std::cout << "Input: " << std::string("1.0e-2/1e-1-1E-1") << std::endl;
    infixExpression<double> exp12("1.0e-2/1e-1-1E-1");
    std::cout << "Ans: " << exp12.calculate() << std::endl << std::endl;

    std::cout << "Input: " << std::string("1.0e---2/1e-1-1E-1") << std::endl;
    infixExpression<double> exp16("1.0e---2/1e-1-1E-1");
    std::cout << "Ans: " << exp16.calculate() << std::endl << std::endl;

    std::cout << "--------------------------------------------------------------------" << std::endl;    
    //乘方测试
    std::cout << "Test for power operation:" << std::endl << std::endl;

    std::cout << "Input: " << std::string("2^2+1") << std::endl;
    infixExpression<double> exp19("2^2+1");
    std::cout << "Ans: " << exp19.calculate() << std::endl << std::endl;

    std::cout << "Input: " << std::string("2^-2+1") << std::endl;
    infixExpression<double> exp20("2^-2+1");
    std::cout << "Ans: " << exp20.calculate() << std::endl << std::endl;

    std::cout << "Input: " << std::string("2^--2+1") << std::endl;
    infixExpression<double> exp22("2^--2+1");
    std::cout << "Ans: " << exp22.calculate() << std::endl << std::endl;

    std::cout << "Input: " << std::string("2^(-2+1)") << std::endl;
    infixExpression<double> exp23("2^(-2+1)");
    std::cout << "Ans: " << exp23.calculate() << std::endl << std::endl;

    std::cout << "Input: " << std::string("2^-(-2+1)") << std::endl;
    infixExpression<double> exp24("2^-(-2+1)");
    std::cout << "Ans: " << exp24.calculate() << std::endl << std::endl;

    std::cout << "Input: " << std::string("2^3^2") << std::endl;
    infixExpression<double> exp25("2^3^2");
    std::cout << "Ans: " << exp25.calculate() << std::endl << std::endl;

    std::cout << "--------------------------------------------------------------------" << std::endl;
    //混合运算测试
    std::cout << "Test for mixed operations:" << std::endl << std::endl;

    std::cout << "Input: " << std::string("1024/2^e10--8") << std::endl;
    infixExpression<double> exp26("1024/2^1e10--8");
    std::cout << "Ans: " << exp26.calculate() << std::endl << std::endl;

    std::cout << "Input: " << std::string(".125/8^(1+2/2---3)") << std::endl;
    infixExpression<double> exp27(".125/8^(1+2/2---3)");
    std::cout << "Ans: " << exp27.calculate() << std::endl << std::endl;

    std::cout << "Input: " << std::string("11e---2+.1+100^.5") << std::endl;
    infixExpression<double> exp28("11e---2+.1+100^.5");
    std::cout << "Ans: " << exp28.calculate() << std::endl << std::endl;

    std::cout << "Input: " << std::string("11e---2+.1+100^-.5") << std::endl;
    infixExpression<double> exp29("11e---2+.1+100^-.5");
    std::cout << "Ans: " << exp29.calculate() << std::endl << std::endl;

    return 0;
}