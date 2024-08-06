#include <iostream>
#include <string>
#include <cstdlib>
#include <array>
#include <cmath>
#include <iomanip> // For fixed and setprecision

using namespace std;

bool check(const string str) {
    if (str == "") return false;
    for (char c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}

array<double, 2> DataXY(string x, string y, string select) {
    if (stoi(select) >= 6) {
        cout << "> Input X: ";
        getline(cin, x);

        while (!check(x))
        {
            cout << "> Input X: ";
            getline(cin, x);
        }
        return { stod(x) };
    }
    else {
        cout << "> Input X: ";
        getline(cin, x);
        while (!check(x))
        {
            cout << "> Input X: ";
            getline(cin, x);
        }

        cout << "> Input Y: ";
        getline(cin, y);

        while (!check(y))
        {
            cout << "> Input Y: ";
            getline(cin, y);
        }
        return { stod(x), stod(y) };
    }
}

void clearScreen() {
    if (_WIN32) {
        system("CLS");
    }
    else {
        system("clear");
    }
}

int main()
{
    string information[] = {
        "1. Addition",
        "2. Subtraction",
        "3. Multiplication",
        "4. Division",
        "5. Power",
        "6. Square",
        "7. Square Root",
        "8. Exit"
    };
    string select;

    while (true) {
        cout << "*******************************************" << endl;

        int width = 0;
        for (const string& line : information) {
            if (line.length() > width) {
                width = line.length() + 28;
            }
        }

        for (const string& line : information) {
            cout << "* " << line;
            cout << string(width - line.length(), ' ') << " *" << endl;
        }

        cout << "*******************************************" << endl;

        cout << "[*] Select between 1 and 8: " << endl;
        cout << "> Input: ";
        getline(cin, select);

        while (!check(select) || (stoi(select) < 1 || stoi(select) > 8))
        {
            cout << "> Input: ";
            getline(cin, select);
        }
        clearScreen();

        cout << "*******************************************" << endl;
        cout << "You've choosen: " << information[stoi(select) - 1] << endl;
        cout << "*******************************************" << endl;

        if (stoi(select) == 8) {
            cout << "Exiting the program." << endl;
            break;
        }

        if (stoi(select) <= 5) {
            cout << "Please enter data of X and Y :-)" << endl;
        }
        else {
            cout << "Please enter data of X :-)" << endl;
        }
        string x; string y;
        double res = 0;
        string cal;
        array<double, 2> result = DataXY(x, y, select);

        if (result[1]) {
            switch (stoi(select))
            {
            case 1:
                res = result[0] + result[1];
                cal = "+";
                break;
            case 2:
                res = result[0] - result[1];
                cal = "-";
                break;
            case 3:
                res = result[0] * result[1];
                cal = "*";
                break;
            case 4:
                res = result[0] / result[1];
                cal = "/";
                break;
            case 5:
                res = pow(result[0], result[1]);
                cal = "^";
                break;
            default:
                break;
            }
            cout << fixed << setprecision(2);
            cout << "[*] RESULT: " << result[0] << " " << cal << " " << result[1] << " = " << res;
            break;
        }
        else {
            switch (stoi(select))
            {
            case 6:
                res = result[0] * result[0];
                cal = "squared";
                break;
            case 7:
                res = sqrt(result[0]);
                cal = "square root of";
                break;
            default:
                break;
            }
            cout << fixed << setprecision(2);
            cout << "[*] RESULT: " << cal << " " << result[0] << " = " << res;
            break;
        }
    }

    return 0;
}
