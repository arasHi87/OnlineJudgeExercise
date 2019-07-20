#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n, idx=0, num[100];
        cin>>n;
        if (n==1) {cout<<"1"<<endl; continue;}
        for (int i=9;i>1;i--) {
            while (!(n%i)) {
                num[idx++]=i;
                n/=i;
            }
        }
        sort(num, num+idx);
        if (n!=1) cout<<"-1"<<endl;
        else {
            for (int i=0;i<idx;i++)
                cout<<num[i];
            cout<<endl;
        }
    }
}