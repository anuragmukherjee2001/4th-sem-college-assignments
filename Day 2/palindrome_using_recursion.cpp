#include<iostream>

using namespace std;

int reverse(int num, int temp)
{
    if (num == 0)
        return temp;
    temp = (temp * 10) + (num % 10);
 
    return reverse(num / 10, temp);
}

int main(){
	int num;
	cout << "Enter the number " << endl;
	
	cin >> num;
	
	int ans = reverse(num, 0);
	if(ans == num){
		cout << "It is a Palindrome Number";
	}
	else{
		cout << "It is not a palindrome number";
	}
	return 0;
}
