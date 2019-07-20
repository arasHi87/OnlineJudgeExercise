    #include <iostream>
    const int maxN=1e6+10;

    int cnt[maxN]={0};

    int main() {
        for (int i=1;i<=1e6;i++) {
            int u=i, sum=i;
            while (u) {
                sum+=u%10;
                u/=10;
            }
            cnt[sum]=1;
        }
        for (int i=1;i<=1e6;i++)
        if (!cnt[i]) printf("%d\n", i);
    }