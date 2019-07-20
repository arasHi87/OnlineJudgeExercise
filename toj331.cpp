#include <iostream>
using namespace std;

int main() {
    string s1, s2;
    cin>>s1>>s2;
    long long l1=s1.length(), l2=s2.length();
    for (int i=0;i<(int)s1.length();i++)
        if (s1[i]=='0') l1--;
    for (int i=0;i<(int)s2.length();i++)
        if (s2[i]=='0') l2--;
        cout<<l1*l2<<endl;
}