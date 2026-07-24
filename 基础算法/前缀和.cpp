#include <iostream>
using namespace std;

const int N = 100010;
int n, m;
int a[N], s[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // 构造前缀和
    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + a[i];
    }

    // 回答询问
    while (m--)
    {
        int l, r;
        cin >> l >> r;

        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}

// const int N=100010;
// int n,m;
// int a[N],S[N];

// int main()
// {
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//     }

//     for(int i=1;i<=n;i++)
//     {
//         S[i]=S[i-1]+a[i];
//     }

//     while(m--)
//     {
//         int l,r;
//         cin>>l>>r;

//         cout<<S[r]-S[l-1]<<endl;
//     }

//     return 0;
// }