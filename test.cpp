#include <string>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
    string tmp="9533";
    for (int i=0;i<=9;i++)
        for (int j=0;j<=9;j++)
            for (int k=0;k<=9;k++)
                for (int m=0;m<=9;m++)
                    cout<<tmp+(char)i+(char)j+(char)k+(char)m<<'\n';
}