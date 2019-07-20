#include <iostream>
using namespace std;

int dp[80]={0}, x;

int main() {
    dp[0]=1, dp[1]=1, dp[2]=2;
    for (int i=3;i<=80;i++)
        dp[i]+=(dp[i-3]+dp[i-2]);
    while (~scanf("%d", &x)) {
        printf("%d\n", dp[x]);
    }
}