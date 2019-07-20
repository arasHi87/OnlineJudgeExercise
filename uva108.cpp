#include <iostream>
using namespace std;
const int maxN=105;

int num[maxN][maxN]={0}, n;

int main() {
    scanf("%d", &n);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) {
            scanf("%d", &num[i][j]);
            num[i][j]+=num[i-1][j];
        }
    int maxSum=num[1][1];
    for (int i=1;i<=n;i++) {
        for (int j=i;j<=n;j++) {
            int sum=0;
            for (int k=1;k<=n;k++) {
                if (sum<0) sum=num[j][k]-num[i][k];
                else if (i!=j) sum+=num[j][k]-num[i][k];
                if (sum>maxSum && sum!=0) maxSum=sum;
            }
        }
    }
    printf("%d\n", maxSum);
}