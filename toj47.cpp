#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;

int main() {
    int n, x, k;
    cin >> n;
    for ( int i = 0; i < n; i++ )
    {
        cin >> x;
        a.push_back(x); 
    }
    sort(a.begin(), a.end());
    // for ( int i = 0; i < n; i++ )
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    cin >> k;
    for ( int i = 0; i < k; i++ )
    {
        long long t;
        cin >> t;
        int ptr = lower_bound(a.begin(), a.end(), t) - a.begin();
        // cout << "ptr " << ptr << endl;
        if ( a[ptr] == t ) {
            cout << a[ptr] << '\n';
        } else if ( ptr == a.size() ) {
            if ( a[ptr] > t)
                cout << a[ptr - 1] << a[ptr] << '\n';
            else
                cout << a[ptr - 1] << " no" << '\n';
        } else if ( ptr == 0 ) {
            if ( a[0] < t)
                cout << a[0] << " " << a[1] << '\n';
            else
                cout << "no " << a[0] << '\n';
        } else {
            cout << a[ptr - 1] << " " << a[ptr] << '\n';
        } 
    }
}
//4 1 7 -1 8 -10 19
//lower_bound 大於等於
//upper_bound 大於