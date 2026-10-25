#include <iostream>
#include <string>
using namespace std;

// Step activation: H(z) = 1 for z >= 0; otherwise 0.
int step(double z) {
    if (z >= 0) {
        return 1;
    }
    return 0;
}

// Two-input artificial neuron.
int neuron(int x1, int x2, double w1, double w2, double b) {
    double z = w1 * x1 + w2 * x2 + b;
    return step(z);
}

int main() {
    string input1, input2;
    double w1, w2, b;

    cout << "Enter x1 (0 or 1): ";
    if (!(cin >> input1) || (input1 != "0" && input1 != "1")) {
        cout << "Error: x1 must be 0 or 1." << endl;
        return 1;
    }

    cout << "Enter x2 (0 or 1): ";
    if (!(cin >> input2) || (input2 != "0" && input2 != "1")) {
        cout << "Error: x2 must be 0 or 1." << endl;
        return 1;
    }

    int x1 = 0;
    int x2 = 0;

    if (input1 == "1") {
        x1 = 1;
    }

    if (input2 == "1") {
        x2 = 1;
    }

    cout << "Enter w1, w2, and bias (separated by spaces): ";
    if (!(cin >> w1 >> w2 >> b)) {
        cout << "Error: weights and bias must be numbers." << endl;
        return 1;
    }

    cout << "Neuron output = " << neuron(x1, x2, w1, w2, b) << endl;

    cout << "\nTruth table: AND, OR, NOR\n";
    cout << "x1 x2 | AND OR NOR\n";
    cout << "------------------\n";

    for (int a = 0; a <= 1; a++) {
        for (int c = 0; c <= 1; c++) {
            cout << a << "  " << c << "  |  "
                 << neuron(a, c, 1, 1, -1.5) << "   "
                 << neuron(a, c, 1, 1, -0.5) << "  "
                 << neuron(a, c, -1, -1, 0.5) << '\n';
        }
    }

    cout << "\nTruth table: NOT\n";
    cout << "x | NOT\n";
    cout << "-------\n";

    for (int a = 0; a <= 1; a++) {
        cout << a << " |  "
             << neuron(a, 0, -1, 0, 0.5) << '\n';
    }
    return 0;
}
