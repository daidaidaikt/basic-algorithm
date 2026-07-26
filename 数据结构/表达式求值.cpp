#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <cctype>

using namespace std;

stack<int> num; // 数字栈
stack<char> op; // 运算符栈

// 执行一次运算
void eval()
{
    // 先弹出右操作数
    int b = num.top();
    num.pop();

    int a = num.top();
    num.pop();

    char c = op.top();
    op.pop();

    int result;

    if (c == '+')
        result = a + b;
    else if (c == '-')
        result = a - b;
    else if (c == '*')
        result = a * b;
    else
        result = a / b;

    num.push(result);
}

int main()
{
    string str;
    cin >> str;

    unordered_map<char, int> priority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

    for (int i = 0; i < static_cast<int>(str.size()); i++)
    {
        char c = str[i];

        // 1.当前是数字
        if (isdigit(c))
        {
            int value = 0;
            int j = i;

            // 连续读取一个完整的多位整数
            while (j < static_cast<int>(str.size()) && isdigit(str[j]))
            {
                value = value * 10 + str[j] - '0';
                j++;
            }

            num.push(value);
            i = j - 1;
        }

        // 2.当前是左括号
        else if (c == '(')
        {
            op.push(c);
        }

        // 3.当前是右括号
        else if (c == ')')
        {
            // 计算当前括号内部的所有运算
            while (!op.empty() && op.top() != '(')
            {
                eval();
            }

            // 删除左括号
            op.pop();
        }

        // 4.当前是普通运算符
        else
        {
            // 栈顶元素大于等于当前运算符，先计算栈顶
            while (!op.empty() && op.top() != '(' && priority[op.top()] >= priority[c])
            {
                eval();
            }

            op.push(c);
        }
    }

    while (!op.empty())
        eval();

    cout << num.top() << endl;

    return 0;
}