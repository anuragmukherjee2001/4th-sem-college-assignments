#include <iostream>
#include <stdlib.h>

#define max 4

using namespace std;

class Stack{
    
    public:

    int arr[max];
    int top;
    
    Stack(){
        top = -1;
    }


    int isEmpty(){
        if (top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }    

    int isFull(){
        if (top == max - 1)
        
            return 1;
        
        else
        
            return 0;
           
    }    

    void push(int item){
        top++;
        arr[top] = item;
    }

    int peek(){
        if (!isEmpty())    
            return arr[top];              
    }

    void print(){
        if (!isEmpty())
        {
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << endl;
            }
        }

        else
        {
            cout << "The Stack is Empty" << endl;
        }
        
    }
        
    int pop(){
        if (!isEmpty())
        {
            int x = arr[top];
            top--;
            return x;
        }
        else
        
            cout << "Stack is Empty" << endl;
        
    }       
};


int main(){
    int ch;
    Stack s1;

    while (1)
    {
        cout << "1. Push \t 2. Pop \t 3. Peek \t 4. IsEmpty \t 5. IsFull \t 6. Print 7. Exit" << endl;
        cout << "Enter Your Choice" << endl;

        cin >> ch;

        switch (ch)
        {
            case 1:

                if (!s1.isFull())
                {
                    cout << "Enter the Item" << endl;
                    int item;

                    cin >> item;

                    s1.push(item);
                }

                else
                {
                    cout << "Stack is full" << endl;
                }
                break;

            case 2:
                if(!s1.isEmpty()){
                    cout << "The popped item is" << s1.pop() << endl;
                }
                else{
                    s1.pop();
                }
                break;

            case 4:

                if(s1.isEmpty()){
                    cout << "The stack is empty" << endl;
                }
                else{
                    cout << "The stack is not empty" << endl;
                }
                break;

            case 3:
                if(!s1.isEmpty()){
                    cout << s1.peek() << endl;
                }
                else{
                    cout << "The stack is empty" << endl;
                }
                break;

            case 5:

                if(s1.isFull()){
                    cout << "The stack is Full" << endl;
                }
                else{
                    cout << "The stack is not Full" << endl;
                }
                break; 

            case 6:

                s1.print();
                break;       

            case 7:

                exit(1); 
                break;   

            default:

                cout << "Enter a right choice" << endl;                           
        }
    } 
    return 0;
}