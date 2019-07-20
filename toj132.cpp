#include <iostream>
typedef long long LL;
using namespace std;

int main()
{
    LL a, b, t;

    cin >> a >> b;
    while (b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    cout << a << endl;

    return 0;
}