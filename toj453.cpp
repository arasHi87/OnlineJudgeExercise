#include <iostream>
using namespace std;

int main() {
    int n; cin>>n;
    int l=(n+1)*2+1;
    int half_long=n+2;
    for (int i=1;i<=n+2;i++) {
        if (i==n+2) {
            for (int j=1;j<=l;j++) cout<<'*';
            cout<<endl;
            break;
        }
        for (int j=1;j<=half_long-i;j++) cout<<" ";
        if (i==1) {cout<<'*'<<endl; continue;}
        cout<<'*';
        for (int j=1;j<=1+(i-2)*2;j++) cout<<' ';
        cout<<'*'<<endl;
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=half_long-1;j++) cout<<' ';
        cout<<'*'<<endl;
    }
    for (int j=1;j<=l;j++) cout<<'*';
    cout<<endl;
    for (int i=n+1;i>1;i--) {
        int cnt=0;
        for (int j=1;j<=half_long-i;j++) {cout<<" "; cnt++;}
        cout<<'*'; cnt++;
        for (int j=1;j<=1+(i-2)*2;j++) {
            if (cnt==half_long-1) {cout<<'*'; cnt++;}
            else {cout<<' '; cnt++;}
        }
        cout<<'*'<<endl;
    }
    for (int j=1;j<=l;j++) cout<<'*';
    cout<<endl;
}