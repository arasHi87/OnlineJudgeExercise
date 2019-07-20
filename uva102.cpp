#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll s[10];

inline string greator(int i, int j, int k) {
    string s;
    for (int l=1;l<=3;l++) {
        if (i==l) s.push_back('B');
        else if (j==l) s.push_back('G');
        else if (k==l) s.push_back('C'); 
    }
    return s;
}

int main() {
    while (cin>>s[1]) {
        for (int i=2;i<=9;i++) cin>>s[i];
        ll B[4]={0, s[4]+s[7], s[1]+s[7], s[1]+s[4]};
        ll G[4]={0, s[5]+s[8], s[2]+s[8], s[2]+s[5]};
        ll C[4]={0, s[6]+s[9], s[3]+s[9], s[3]+s[6]};
        ll ans=0x3f3f3f3f3f3f3f3f;
        string aans;
        for (int i=1;i<=3;i++) {
            for (int j=1;j<=3;j++) {
                for (int k=1;k<=3;k++) {
                    if (i!=j && i!=k && j!=k) {
                        int tmp=B[i]+G[j]+C[k];
                        if (tmp<=ans) {
                            if (tmp==ans) {
                                string str=greator(i, j, k);
                                string arr[2]={aans, str};
                                sort(arr, arr+2);
                                aans=arr[0];
                            } else {
                                ans=tmp;
                                aans=greator(i, j, k);
                            }
                        }
                    }
                }
            }
        }
        cout<<aans<<" "<<ans<<'\n';
    }
}