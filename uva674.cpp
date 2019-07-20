#include <iostream>
#include <memory.h>
using namespace std;
const int maxN=7489+10;

int coin[5]={1, 5, 10, 25, 50};
int dp[maxN];

int main() {
    int n;
   memset(dp, 0, sizeof dp);
   dp[0]=1;
    for (int i=0;i<5;i++)
        for (int j=1;j<=maxN;j++)
            if (j>=coin[i]) dp[j]+=dp[j-coin[i]];
    while (~scanf("%d", &n)) {
        printf("%d\n", dp[n]);            
    }
}