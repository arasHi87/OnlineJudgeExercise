#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int maxN=4e5+10;
const int MOD=998244353;

int w[25], f[205];

int main() {
    int t;
    scanf("%d", &t);
    cin.get();
    while (t--) {
        int idx=1, sum=0, x;
        string line;
        getline(cin, line);
        stringstream ss(line);
        while (ss>>x) {
            w[idx++]=x;
            sum+=x;
        }
        for (int i=0;i<=sum;i++)
            f[i]=0;
        f[0]=1;
        for (int i=1;i<idx;i++)
            for (int j=sum;j>=w[i];j--)
                if (f[j-w[i]]) f[j]=1;
        if (sum%2 || !f[sum/2]) printf("NO\n");
        else printf("YES\n");
    }
}