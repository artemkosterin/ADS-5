#include <string>
#include <stack>

bool isOperator(char op) {
    return (op == '+' || op == '-' || op == '(' ||
        op == ')' || op == '/' || op == '*');
}

bool isDigit(char n) {
    return (n >= '0' && n <= '9');
}

int whatPriority(char op) {
    if (op == '-' || op == '+')
        return 1;
    if (op == '/' || op == '*')
        return 2;
    return 0;
}

std::string infx2pstfx(std::string inf) {
    std::string postfix;
    std::stack<char> stack1;
    for (char s : inf) {
        if (isDigit(s)) {
            postfix += s;
            continue;
        } else if (isOperator(s)) {
            postfix += ' ';
            if (s == '(') {
                stack1.push(s);
            } else if (s == ')') {
                while (!stack1.empty() && stack1.top() != '(') {
                    postfix += stack1.top();
                    stack1.pop();
                }
                stack1.pop(); // Pop the '('
            } else {
                while (!stack1.empty() && whatPriority(s) <= whatPriority(stack1.top())) {
                    postfix += stack1.top();
                    stack1.pop();
                }
                stack1.push(s);
            }
        }
    }
    while (!stack1.empty()) {
        postfix += ' ';
        postfix += stack1.top();
        stack1.pop();
    }
    return postfix;
}

int eval(std::string post) {
    std::stack<int> stack2;
    for (char s : post) {
        if (isDigit(s)) {
            stack2.push(s - '0');
        } else if (isOperator(s)) {
            int x = stack2.top();
            stack2.pop();
            int y = stack2.top();
            stack2.pop();
            switch (s) {
            case '+':
                stack2.push(x + y);
                break;
            case '-':
                stack2.push(y - x);
                break;
            case '*':
                stack2.push(x * y);
                break;
            case '/':
                stack2.push(y / x);
                break;
            default:
                continue;
            }
        }
    }
    return stack2.top();
}
