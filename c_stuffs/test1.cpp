#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "ya hi! name?" << endl;
    string name;
    cin >> name;
    cout << "Hi, " << name << "!" << endl << endl;

    for (char c : name) {
        cout << c << endl;
    }
}