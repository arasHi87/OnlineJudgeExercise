#include <iostream>
using namespace std;

int mp[5][20];
bool flag=false;

void iamnotdfs(int x1, int x2, int x3, int x4) {
    int s1=mp[1][x1], s2=mp[2][x2], s3=mp[3][x3], s4=mp[4][x4];
    if (s1==s2 && s1<=13 && s2<=13 && s1!=0 && s2!=0) iamnotdfs(x1+1, x2+1, x3, x4);
    if (s1==s3 && s1<=13 && s3<=13 && s1!=0 && s3!=0) iamnotdfs(x1+1, x2, x3+1, x4);
    if (s1==s4 && s1<=13 && s4<=13 && s1!=0 && s4!=0) iamnotdfs(x1+1, x2, x3, x4+1);
    if (s2==s3 && s2<=13 && s3<=13 && s2!=0 && s3!=0) iamnotdfs(x1, x2+1, x3+1, x4);
    if (s2==s4 && s2<=13 && s4<=13 && s2!=0 && s4!=0) iamnotdfs(x1, x2+1, x3, x4+1);
    if (s3==s4 && s3<=13 && s4<=13 && s3!=0 && s4!=0) iamnotdfs(x1, x2, x3+1, x4+1);
    if (x1>=13 && x2>=13 && x3>=13 && x4>=13) {flag=true; return;}
    // cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    bool ok=true;
    for (int i=1;i<=4;i++) {
        for (int j=1;j<=13;j++) {
            cin>>mp[i][j];
            if (mp[i][j]!=j) ok=false;
        }
    }
    if (ok) {cout<<"YES"<<endl; return 0;}
    flag=false;
    iamnotdfs(1, 1, 1, 1);
    if (flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}