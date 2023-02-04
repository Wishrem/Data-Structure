#include <iostream>
#include <stack> // 偷懒
#include <string>
#include <cstdlib>
#include <algorithm>
#include <sstream>

// prior 运算符优先级
int prior(char opt)
{
    switch (opt)
    {
    case '+':
    case '-':
        return 0;
        break;
    case '*':
    case '/':
        return 1;
        break;
    default: // ( )
        return -1;
        break;
    }
}

std::string infixToRPN(std::string expr)
{
    std::stack<char> st;
    std::string opts = "()+-*/#";
    std::stringstream ss;
    std::size_t l = 0, r = expr.find_first_of(opts); // 找到第一个非数字的位置

    char opt; // 操作符
    int pr;   // 优先级
    expr.append("#");
    while (true)
    {
        if (l != r)
            // 将此段内容转为数字并输出到流中
            ss << expr.substr(l, r - l) << "#";

        // 查找下一个非数字的位置
        l = r + 1;
        r = expr.find_first_of(opts, l);

        opt = expr[l - 1];

        // 终止
        if (opt == '#')
            break;

        // 括号
        if (opt == '(')
        {
            st.push(opt);
            continue;
        }
        if (opt == ')')
        {
            while (st.top() != '(')
            {
                ss << st.top() << "#";
                st.pop();
            }
            st.pop(); // 将左括号弹出
            continue;
        }

        // 其余操作符
        pr = prior(opt);
        if (!st.empty() && prior(st.top()) < pr)
        {
            st.push(opt);
            continue;
        }

        while (!st.empty() && prior(st.top()) >= pr)
        {
            ss << st.top() << "#";
            st.pop();
        }
        st.push(opt);
    }
    while (!st.empty())
    {
        ss << st.top() << "#";
        st.pop();
    }
    return ss.str();
}

double calc(double &a, double &b, char &opt)
{
    switch (opt)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    default:
        return 0.0;
        break;
    }
}

double calcRPN(std::string expr)
{
    std::stack<double> st;
    char d = '#';
    size_t l = 0, r = expr.find_first_of(d);
    std::string sub;

    char opt;
    double a, b;
    while (r != std::string::npos)
    {
        sub = expr.substr(l, r - l);

        l = r + 1;
        r = expr.find_first_of(d, l);

        // 操作数
        if (isdigit(sub[0]))
        {
            st.push(atof(sub.c_str()));
            continue;
        }

        // 操作符
        opt = sub[0];
        b = st.top(), st.pop();
        a = st.top(), st.pop();
        st.push(calc(a, b, opt));
    }
    return st.top();
}

bool isValidExpr(std::string &expr)
{
    int lbAmount = 0, rbAmount = 0;
    std::string validChars = "1234567890.+-*/";
    for (auto &c : expr)
    {
        if (c == '(')
        {
            lbAmount++;
            continue;
        }

        if (c == ')')
        {
            rbAmount++;
            continue;
        }
        if (validChars.find(c) == std::string::npos)
            return false;
    }

    return lbAmount == rbAmount;
}

int main(int arg, char *args[])
{
    if (arg < 2)
    {
        puts("用法：./[编译文件] [表达式]");
        exit(EXIT_FAILURE);
    }

    std::string expr(args[1]);
    if (!isValidExpr(expr))
    {
        puts("表达式不合法");
        exit(EXIT_FAILURE);
    }

    std::cout << calcRPN(infixToRPN(expr)) << std::endl;

    return 0;
}