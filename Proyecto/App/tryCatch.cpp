#include <iostream>
using namespace std;

void func3(bool flag, bool flag2) {
    try {
        if (flag) throw 3;
        if (flag2) throw 'a';
    } catch (int e) {
        cout << "error en: " << e << endl;
    } catch (char e) {
        cout << "error tipo: " << e << endl;
    } catch (...) {
        cout << "error desconocido" << endl;
    }
}

void func2(bool flag) {
    try {
        if (flag) throw 2;
        func3(true, false);
    } catch (int e) {
        cout << "error en: " << e << endl;
    }
}

void func1(bool flag) {
    try {
        if (flag) throw 1;
        func2(false);
    } catch (int e) {
        cout << "error en: " << e << endl;
    }
}

int main() {
    func1(false);
}
