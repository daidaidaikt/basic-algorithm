#include <iostream>
using namespace std;

const int N = 100010;

int q[N];
int hh = 0;
int tt = -1;

int main()
{
    int m;
    cin >> m;

    while (m--)
    {
        string op;
        cin >> op;

        if (op == "push")
        {
            int x;
            cin >> x;
            // 在队尾插入
            q[++tt] = x;
        }
        else if (op == "pop")
        {
            hh++;
        }
        else if (op == "empty")
        {
            if (hh > tt)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else if (op == "query")
        {
            cout << q[hh] << endl;
        }
    }
    return 0;
}