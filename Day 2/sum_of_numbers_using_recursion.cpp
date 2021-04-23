#include<iostream>

using namespace std;

int addNumbers(int num) {
    if (num != 0)
        return num + addNumbers(num - 1);
    else
        return num;
}

int main() {
    int num;
    cout << "Enter a the value " << endl;
    cin >> num;
    cout << "The sum is" << addNumbers(num);
    return 0;
}
