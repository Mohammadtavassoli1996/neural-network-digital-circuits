
#include <iostream>
#include <string>
using namespace std;

// Step activation function
int step(double value) {
    if (value >= 0) {
        return 1;
    }
    return 0;
}

// Neural 2:1 multiplexer
int mux(int d0, int d1, int s) {
    int y0 = step(d0 - s - 0.5);
    int y1 = step(d1 + s - 1.5);

    int z = step(y0 + y1 - 0.5);
    return z;
}

int main() {
    string input0, input1, select;

    cout << "Enter d0, d1, s (0 or 1): " << endl;

    // Check whether three inputs were received
    if (!(cin >> input0 >> input1 >> select)) {
        cout << "Error: Three inputs are required." << endl;
        return 1;
    }

    if ((input0 != "0" && input0 != "1") ||
        (input1 != "0" && input1 != "1") ||
        (select != "0" && select != "1")) {
        cout << "Error: Inputs must be 0 or 1." << endl;
        return 1;
    }

    int d0 = 0;
    int d1 = 0;
    int s = 0;

    if (input0 == "1") d0 = 1;
    if (input1 == "1") d1 = 1;
    if (select == "1") s = 1;

    int output = mux(d0, d1, s);

    cout << "MUX output = " << output << endl;

    // Generate complete truth table
    cout << "\nMUX 2:1 Truth Table" << endl;
    cout << "d0 d1 s | Output" << endl;
    cout << "------------------" << endl;

    for(int a = 0;a<=1;a++){
        for(int b = 0; b<=1 ; b++){
            for(int c = 0;c <= 1;c++){
                int result = mux(a, b, c);

                cout << a << "  "
                     << b << "  "
                     << c << " | "
                     << result << endl;
            }
        }
    }

    return 0;
}
