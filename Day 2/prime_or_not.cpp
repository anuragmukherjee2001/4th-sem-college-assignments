#include<iostream>

using namespace std;

int isPrime(int n, int i)
{
    if(i == 1)
        return 1; 
    else
    {
        if(n%i == 0)
            return 0;
        else
            isPrime(n, i-1); 
    }
}

int main(){
	int num, ans;
	cout << "Enter the number" << endl;
	cin >> num;
	int i = num/2;
	ans = isPrime(num, i);

	if (num == 1)
	{
		cout << "It is not a prime number" << endl;
	}	
	else if(ans == 1){
		cout << "It is a prime number" << endl;
	}
	else{
		cout << "It is not a prime number" << endl;
	}
	return 0;
}
