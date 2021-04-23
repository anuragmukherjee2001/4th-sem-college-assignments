#include<iostream>

using namespace std;

int count;

int TOH(int n, char source, char aux, char des){
    if (n == 1)
    {

        cout << " Move disk 1 from " << source << " to " << des << endl;
        count++;
        
    }
    else
    {
        TOH(n - 1, source, des, aux);
        cout << " Move disk " << n << " from " <<  source << " to " << des << endl;
        TOH(n - 1, aux, des, source);
        count++;
    }
    
}


int main(){

    int num;
    cout << "Enter the number of discs ";
    
    cin >> num;

    TOH(num, 'A', 'B', 'C');
    
    cout << "The number of moves are " << count << endl;

    return 0;
}
