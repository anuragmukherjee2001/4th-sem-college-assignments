#include<iostream>

using namespace std;

int gcd(int num1, int num2) {
    if (num2 == 0)
        return num1;
    else
        return gcd(num2, num1 % num2);
} 

int main(){
	int num1, num2;
	cout << "Enter two numbners " << endl;
	cin >> num1 >> num2;
	int GCD = gcd(num1, num2);
	cout << "The GCD is " << GCD;
	return 0;
}
