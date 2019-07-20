#include <iostream>
#include <cctype>
#include <cstring>
#include <iomanip>
using namespace std;

const double C = 12.010;
const double H = 1.008;
const double N = 14.010;
const double O = 16.000;

void add( char emt, int mole, double& mass) {
    switch ( emt ) {

        case 'C':
            mass += C * mole;
            break;

        case 'H':
            mass += H * mole;
            break;

        case 'N':
            mass += N * mole;
            break;

        case 'O':
            mass += O * mole;
            break;
    }
}

int main() {
    double mole;
    int n;

    cin >> n;

    for ( int i = 0; i < n; i++ ) {
        char molar[85];
        double mass = 0;

        cin >> molar;
        for ( int j = 0; j < strlen(molar); j++ ) {
            char emt = molar[j];
            double p1 = molar[j + 1], p2 = molar[j + 2];

            if ( isalpha(emt) ) {
                if ( isdigit(p1) ) {
                    if ( isdigit(p2) ) {
                        add( emt, (p1 - '0') * 10 + (p2 - '0'), mass);
                        j += 2;
                    } else {
                        add ( emt, p1 - '0', mass);
                        j++;
                    }
                } else {
                    add( emt, 1, mass);
                }
            }
        }
        cout << fixed << setprecision(3) << mass << endl;
    }
}