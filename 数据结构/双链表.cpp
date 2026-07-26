#include <iostream>
using namespace std;

const int N = 100010;
int e[N], l[N], r[N], idx; // l[]表示节点的左指针，r[]表示节点的右指针

// 初始化
void init()
{
    // 0是左端点，1是右端点
    r[0] = 1, l[1] = 0;
    idx = 2;
}

// 在下标为a的右边插入一个数x
void insert_r(int a, int x)
{
    e[idx] = x;
    l[idx] = a, r[idx] = r[a];
    l[r[a]] = idx, r[a] = idx;
    idx++;
}

// 在下标为a的左边插入一个数x
void insert_l(int a, int x)
{
    e[idx] = x;
    l[idx] = l[a], r[idx] = a;
    r[l[a]] = idx, l[a] = idx;
    idx++;
}

// 将下标为a的数删除
void remove(int a)
{
    r[l[a]] = r[a];
    l[r[a]] = l[a];
}

int main()
{
    int m;
    cin >> m;

    init();

    while (m--)
    {
        string op;
        cin >> op;

        if (op == "L")
        {
            int x;
            cin >> x;

            // 在左端点0的右边插入
            insert_r(0, x);
        }
        else if (op == "R")
        {
            int x;
            cin >> x;

            // 在右端点1的左边插入
            insert_l(1, x);
        }
        else if (op == "D")
        {
            int k;
            cin >> k;

            // 第k个插入的结点下标为k+1
            remove(k + 1);
        }
        else if (op == "IL")
        {
            int k, x;
            cin >> k >> x;

            insert_l(k + 1, x);
        }
        else if (op == "IR")
        {
            int k, x;
            cin >> k >> x;

            insert_r(k + 1, x);
        }
    }

    // 从左端点的右边开始，遍历到右端点1
    for (int i = r[0]; i != 1; i = r[i])
    {
        cout << e[i] << ' ';
    }
}