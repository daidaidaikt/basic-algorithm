#include <iostream>
using namespace std;

const int N = 100010;
int n, m;
int a[N], b[N];

void insert(int l, int r, int c)
{
    b[l] += c;
    b[r + 1] -= c;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    // 构造差分数组
    for (int i = 1; i <= n; i++)
    {
        insert(i, i, a[i]);
    }

    // 进行m次区间修改
    while (m--)
    {
        int l, r, c;
        cin >> l >> r >> c;

        insert(l, r, c);
    }

    // 对差分数组求前缀和，恢复最终数组
    for (int i = 1; i <= n; i++)
    {
        b[i] += b[i - 1];
        cout << b[i] << ' ';
    }

    return 0;
}