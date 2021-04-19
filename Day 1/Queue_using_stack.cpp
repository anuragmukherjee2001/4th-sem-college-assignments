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
    
        else
    
            cout << "Stack is Empty" << endl;
               
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

class Queue {
    public:
    Stack s1, s2;
    int i = 0;
  
    void enqueue(int x)
    {
        s1.push(x);
			i++;
    }
  
    int dequeue()
    {
        while(!s1.isEmpty()){
			int k=s1.pop();
			s2.push(k);
			}
		s2.pop();
		while(!s2.isEmpty()){
			int k=s2.pop();
			s1.push(k);
			}
    } 
    void display(){
        s1.print();
    }       
};

int main()
{
    Queue Q1;

    while (1)
    {
        cout << "1. Enqueue \t 2. Dequeue \t 3. Display \t 6.Exit" << endl;
        cout << "Enter your choice" << endl;
        int n;

        cin >> n;
    switch(n){

            case 1:
                int item;
                cout << "Enter the item" << endl;
                cin >> item;
                Q1.enqueue(item);
                break;

            case 2:
                Q1.dequeue();              
                break;

            case 3:
                cout << "The Queue is" << endl;
                Q1.display();
                break;


            case 6:
                exit(1);  

            default:
                cout << "Choose the options correctly";
                break;        
        }
    } 
    return 0;
}