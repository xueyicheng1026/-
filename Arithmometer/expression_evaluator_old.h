#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cctype>
#include <exception>
#include <limits>

template <typename element>
class infixExpression
{
    private:
        std::string expression = "";
        std::string expression_processed = "";
        std::stack<element> numberStack = {};
        std::stack<char> operatorStack = {};

        template <typename T>
        T pop_and_return(std::stack<T> &stack) {
            if (stack.empty()) 
                throw std::runtime_error("Error: Invaild expression:Operator used incorrectly!");
            T top = stack.top();
            stack.pop();
            return top;
        }
        bool isOperator(char c) {
            return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
        }

        bool isOperatorwithoutbrackets(char c) {
            return c == '+' || c == '-' || c == '*' || c == '/';
        }

        int priority(char c) {
            if (c == '(') return 0;
            if (c == '+' || c == '-') return 1;
            if (c == '*' || c == '/') return 2;
            if (c == ')') return 3;
            return 0;
        }

        std::string addSpace(const std::string &exp) {
            std::string expression_processed = "";
            for (int i = 0; i < exp.size(); ++i) {
                if (isOperator(exp[i]) && !(exp[i] == '-' && i>0 && exp[i-1] == 'e')){
                    expression_processed += " ";
                    expression_processed += exp[i];
                    expression_processed += " ";
                } else {
                    expression_processed += exp[i];
                }
            }
            return expression_processed;
        }

        std::string deleteminus(const std::string &exp) {
            std::string expression_processed = "";
            for (int i = 0; i < exp.size(); ++i){
                if (exp[i] == '-' ) {
                    if (i == 0 || exp[i-1] == '(' || isOperatorwithoutbrackets(exp[i-1])) {
                        expression_processed += "(0-1)*";
                    }
                    else if (exp[i-1] == 'e' || exp[i-1] == 'E') {
                        expression_processed += "-";
                    }
                    else if (exp[i-1] == ')' || std::isdigit(exp[i-1])) {
                        expression_processed += "+(0-1)*"; 
                    }
                }
                else 
                    expression_processed += exp[i];
            }
            return expression_processed;
        }

        std::string cutminus(const std::string &exp) {
            std::string expression_processed = "";
            int i = 0;
            while (i < exp.size()){
                bool k = false;
                if (exp[i] == '-'){
                    while (i < exp.size() && exp[i] == '-') 
                    {
                        ++i;
                        k = !k;
                    }
                    if (k) 
                        expression_processed += '-';
                    else  
                        expression_processed += "--";
                }
                else {
                    expression_processed += exp[i];
                    ++i;  
                }
            }
            //std::cout << expression_processed << std::endl;
            return expression_processed;
        }

        void preprocess(){
            expression_processed = cutminus(expression);
            expression_processed = deleteminus(expression_processed);
            expression_processed = addSpace(expression_processed);
            numberStack = {};
            operatorStack = {};
        }

        void pop_until_leftbracket(){
            while (operatorStack.top() != '('){
                executecalculation();
            }
            operatorStack.pop();
        }

        void executecalculation(){
            element a = pop_and_return(numberStack);
            element b = pop_and_return(numberStack);
            char op = pop_and_return(operatorStack);
            element ans;
            if (op == '+') ans = b + a;
            else if (op == '-') ans = b - a;
            else if (op == '*') ans = b * a;
            else if (op == '/') {
                if (a == 0) 
                    throw std::runtime_error("Error: Divided by zero!");
                ans = b / a;
            }
            else 
                throw std::runtime_error("Error: Invalid operator!");
            numberStack.push(ans);
        }
        void bracketisvalid(){
            operatorStack = {};
            for (int i = 0; i < expression.size(); ++i)
            {
                if (expression[i] == '(')
                    operatorStack.push(expression[i]);
                else
                    if (expression[i] == ')'){
                        if (operatorStack.empty()) 
                            throw std::runtime_error("Error: Invalid expression:Bracket missmatch!");
                        else {
                            operatorStack.pop();
                        }
                    }
            }
            if (!operatorStack.empty())
                throw std::runtime_error("Error: Invalid expression:Bracket missmatch!");
        }

        element _calculate() {
        try{
            bracketisvalid();
            preprocess(); 
            std::istringstream tokens(expression_processed);
            std::string token;
            while (tokens >> token) {
                //数字入栈
                if (std::isdigit(token[0]) || token[0] == '.')
                    numberStack.push(std::stod(token));
                //是运算符
                else if (isOperator(token[0])){
                    //空栈直接入
                    if (operatorStack.empty()) operatorStack.push(token[0]);
                    else {
                        //左括号 入栈
                        if (token[0] == '(' ) 
                            operatorStack.push(token[0]);
                        //不是左括号
                        else {
                            //不是左括号 但是 右括号
                            if (token[0] == ')'){
                                pop_until_leftbracket();
                            }
                            //不是左括号 且 不是右括号 入栈
                            else {
                                //优先级大于栈顶元素 直接入栈
                                if (priority(token[0]) > priority(operatorStack.top())) 
                                    operatorStack.push(token[0]);
                                //优先级小于栈顶 弹出直到 栈顶优先级小于当前运算 或 栈空
                                else {
                                    while (!operatorStack.empty() && (priority(token[0]) <= priority(operatorStack.top()))) {
                                        executecalculation();
                                    }
                                    operatorStack.push(token[0]);
                                }
                            }
                        }
                    }
                }
            }
            while (!operatorStack.empty()) {
                executecalculation();
            }
            return pop_and_return(numberStack);
        }catch (const std::exception &e){
            std::cerr << e.what() << std::endl;
            return std::numeric_limits<element>::lowest();
        }
        };



    public:
        infixExpression() {};
        infixExpression(std::string _exp) : expression(_exp) {};
        infixExpression(const infixExpression &rhs) : expression(rhs.expression) {};
        infixExpression(infixExpression &&rhs) noexcept : expression(std::move(rhs.expression)) {};
        infixExpression &operator=(const infixExpression &rhs) {
            if (this != &rhs) {
                expression = rhs.expression;
            }
            return *this;
        }
        void print() const {
            std::cout << expression << std::endl;
        }

        void printprocessed() const {
            std::cout << expression_processed << std::endl;
        }

        std::string calculate(){
            element ans = _calculate();
            return ans != std::numeric_limits<element>::lowest() 
                   ? std::to_string(ans) : "Invalid!";
        }

        ~infixExpression() {};
};