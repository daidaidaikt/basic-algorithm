#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> div(vector<int> &A, int b, int &r) // 除法除了要返回商 C，还需要返回余数 r(引用方式)
{
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i--) // 从最高位开始算
    {
        r = r * 10 + A[i]; // r为当前拿下来参与计算的数
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();

    return C;
}

int main()
{
    string a;
    int b;
    cin >> a >> b;

    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    int r;
    vector<int> C = div(A, b, r);

    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    cout << endl;

    return 0;
}