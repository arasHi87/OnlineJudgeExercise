#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll c, x1, y1, x2, y2, x3, y3;
    cin>>c>>x1>>y1>>x2>>y2>>x3>>y3;
    c/=2;
    cout<<abs((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1))*c<<endl;
}