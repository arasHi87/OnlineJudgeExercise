#include <iostream>
using namespace std;

int main() {
    int n; cin>>n;
    while (n--) {
        int l, r, k=1; cin>>l>>r; 
        while (l--) {
            if (r%2) k<<=1;
            else k = (k<<1) + 1;
            r = (r>>1) + 1;
        }
        cout<<k<<endl;
    }
}