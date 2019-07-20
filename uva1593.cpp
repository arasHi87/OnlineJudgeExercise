#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

vector<string> input;
vector<vector<string>> txt;
int max_col[200];

int main() {
    string s, t;
    int col = 0, row = 0;
    while (getline(cin, s)) {
        // if (s == "EOF") break;
        stringstream ss(s);
        while (ss>>t) {
            input.push_back(t);
            max_col[col] = max(max_col[col], (int)t.length());
            col++;
        }
        txt.push_back(input);
        input.clear();
        col = 0;
        row++;
    }
    for (auto it = txt.begin(); it != txt.end(); it++) {
        for (int i = 0; i < (*it).size(); i++) {
            cout << (*it)[i];
            if (i == (*it).size() - 1) break;
            for (int j = (*it)[i].length() - 1; j < max_col[i]; j++) {
                cout << " ";
            }
        }
        cout << '\n';
    }
}