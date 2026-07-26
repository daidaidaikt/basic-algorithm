#include <iostream>
using namespace std;

const int N = 100010;

int stk[N];
int tt;

int main()
{
    int n;
    cin >> n;

    tt = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        // 删除所有大于等于当前数的栈顶元素
        while (tt && stk[tt] >= x)
        {
            tt--;
        }

        // 栈顶就是左边最近的较小值
        if (tt)
            cout << stk[tt] << ' ';
        else
            cout << -1 << ' ';

        // 当前数入栈
        stk[++tt] = x;
    }

    return 0;
}