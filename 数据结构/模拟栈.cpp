#include <iostream>
using namespace std;

const int N = 100010;
int stk[N], tt = 0; // 初始化，栈为空

int main()
{
    int m;
    cin >> m;

    tt = 0;

    while (m--)
    {
        string op;
        cin >> op;

        if (op == "push")
        {
            int x;
            cin >> x;

            stk[++tt] = x;
        }
        else if (op == "pop")
        {
            tt--;
        }
        else if (op == "empty")
        {
            if (tt == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else if (op == "query")
        {
            cout << stk[tt] << endl;
        }
    }

    return 0;
}
