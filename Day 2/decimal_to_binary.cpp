#include<iostream>

using namespace std;

int convertDec(int dec){
    if (dec == 0)
    {
        return 0;
    }
    else
    {
        return (dec % 2 + 10 * convertDec(dec / 2));
    }
}

int main(){
	int num;
	cout << "Enter the decimal number " << endl;
	cin >> num;
	int bin = convertDec(num);
	cout << "The number is " << bin;
	return 0;
}
