#include <iostream>
using namespace std;

const int N = 1000010;

int n, k;
int a[N];
int q[N];

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    // 求每个窗口的最小值
    int hh = 0, tt = -1;

    for (int i = 0; i < n; i++)
    {
        // 1.删除已经滑出窗口的队头
        // 当前窗口是[i-k+1,i]
        // 队头下标如果小于窗口左端点，说明已经滑出
        if (hh <= tt && q[hh] < i - k + 1)
            hh++;

        // 2.删除队尾所有大于等于当前元素的数
        // 维护单调递增队列
        while (hh <= tt && a[q[tt]] >= a[i])
            tt--;

        // 3.当前元素下标入队
        q[++tt] = i;

        // 4.窗口形成后，队头就是最小值
        if (i >= k - 1)
            cout << a[q[hh]] << ' ';
    }
    cout << endl;

    // 求每个窗口的最大值
    int hh = 0, tt = -1;

    for (int i = 0; i < n; i++)
    {
        // 1.删除已经滑出窗口的队头
        if (hh <= tt && q[hh] < i - k + 1)
            hh++;

        // 2.删除队尾所有小于等于当前元素的数，维护单调递减序列
        while (hh <= tt && a[q[tt]] <= a[i])
            tt--;

        // 3.当前元素下标入队
        q[++tt] = i;

        // 4.窗口形成之后，队头就是最大值
        if (i > k - 1)
            cout << a[q[hh]] << ' ';
    }

    return 0;
}