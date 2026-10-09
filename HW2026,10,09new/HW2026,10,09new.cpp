// HW2026,10,09new.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
using namespace std;

static short chartoint(char a) {
    switch (a) {
    case '0': return 0;
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    default: return 0;
    }
}



static long long stringtoint(string a) {
    long long ret = 0;
    for (int i = 0; i < a.size(); i++) {
        ret *= 10;
        ret += chartoint(a[i]);
    }
}



union U {
    long long l;
    double d;
    string* s;
};
enum EnumU {
    INT,
    DOUBLE,
    STRING
};




class Var {
    U un;
    EnumU e;
public:
    friend istream& operator>>(iostream& os, Var a);
    friend ostream& operator<<(ostream& os, Var a);

    Var(int a) {
        un.l = a;
        e = INT;
    }
    Var(long long a) {
        un.l = a;
        e = INT;
    }
    Var(double a) {
        un.d = a;
        e = DOUBLE;
    }
    Var(string a) {
        un.s = new string(a);
        e = STRING;
    }

    void Show() {
        cout << *this<<endl;
    }

    Var operator+(long long a) {
        switch (this->e) {
        case INT:
            os << a.un.l;
            break;
        case DOUBLE:
            os << a.un.d;
            break;
        case STRING:
            os << *(a.un.s);
            break;
        }
    }


    Var operator+(Var a) {
        if (a.e == STRING and this->e == STRING) goto skip;
        if (a.e == STRING) return stringtoint(*a.un.s) + this->un;
        skip:
    }


};
ostream& operator<<(ostream& os, Var a) {
    switch (a.e) {
    case INT:
        os << a.un.l;
        break;
    case DOUBLE:
        os << a.un.d;
        break;
    case STRING:
        os << *(a.un.s);
        break;
    }
    return os;

}

int main()
{
    Var a1=42;
    Var a2 = 37.69;
    Var a3= (Var)"Hello World";
    cout << a1 << a2 << a3;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
