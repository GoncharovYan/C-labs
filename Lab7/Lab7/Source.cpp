#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>
using namespace std;

HANDLE wc = GetStdHandle(STD_OUTPUT_HANDLE);

enum class level {
    OK,
    WA,
    ER
};

class Write {
public:
    static void log(string message, level l) {
        time_t t = time(0);
        tm* local = localtime(&t);
        cout << put_time(local, "%T") << " ";

        switch (l) {
        case level::OK:
            SetConsoleTextAttribute(wc, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << "OK: ";
            SetConsoleTextAttribute(wc, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
            cout << message << endl;
            break;
        case level::WA:
            SetConsoleTextAttribute(wc, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "WA: ";
            SetConsoleTextAttribute(wc, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
            cout << message << endl;
            break;
        case level::ER:
            SetConsoleTextAttribute(wc, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "ER: ";
            SetConsoleTextAttribute(wc, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
            cout << message << endl;
            break;
        }
    }


};

int main() {
    Write::log("Dovolen", level::OK);
    Write::log("NeDovolen", level::WA);
    Write::log("Rasstroen", level::ER);

    return 0;
}