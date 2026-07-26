#include <iostream>
using namespace std;

const int N = 100010;
int head, e[N], ne[N], idx; // e[]存储节点的值，ne[]存储节点的next指针，idx表示当前用到了哪个节点

// 初始化
void init()
{
    head = -1; // 表示为空
    idx = 0;
}

// 在链表头插入一个数
void insert_head(int a)
{
    e[idx] = a, ne[idx] = head, head = idx++;
}

// 将a插入到第k个插入数的后面
void insert_k(int a, int k)
{
    e[idx] = a;
    ne[idx] = ne[k - 1];
    ne[k - 1] = idx;
    idx++;
}

// 删除第 k个插入的数后面的一个数
void remove(int k)
{
    ne[k - 1] = ne[ne[k - 1]];
}

// 将头节点删除
void remove_head()
{
    head = ne[head];
}

void print()
{
    for (int i = head; i != -1; i = ne[i])
    {
        cout << e[i] << ' ';
    }
}

int main()
{
    int m;
    cin >> m;

    init();

    while (m--)
    {
        char op;
        cin >> op;
        switch (op)
        {
        case 'H':
        {
            int x;
            cin >> x;
            insert_head(x);
            break;
        }
        case 'D':
        {
            int k;
            cin >> k;
            if (k == 0)
                remove_head();
            else
                remove(k);
            break;
        }
        case 'I':
        {
            int k, x;
            cin >> k >> x;
            insert_k(x, k);
            break;
        }
        }
    }

    print();

    return 0;
}