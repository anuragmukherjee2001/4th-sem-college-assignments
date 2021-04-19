#include<iostream>
#include<stdlib.h>

#define max 5

using namespace std;

class Lin_Queue{
    public:
    int arr[max];
    int front;
    int rear;

    Lin_Queue(){
    
    front = -1;
    rear = -1;
    }

    int isFull(){
        if (rear == max - 1)
        
            return 1;
        

        else
        
            return 0;
        
    }

    int isEmpty(){
        if (front == -1 && rear == -1)
        
            return 1;
        

        else
        
            return 0;
        
    }

    void enqueue(int item){
        if(isFull())
        {
            cout << "Queue is full" << endl;
        }
        
        else if (isEmpty()){
            front=rear=0;
            arr[rear] = item;
        }

        else {
            rear++;
            arr[rear] = item;
        }

    }

    int dequeue(){
      int x;
        if (isEmpty())
        {
            cout << "empty queue";
            return 0;
        }
        
        else if(front == rear){
          x = arr[front];
          front = rear = -1;
          return x;
        }

        else
        {
            x = arr[front];
            front++;
            return x;
        }
    }

    void display(){
        if (!isEmpty())
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] <<endl;
            }
        }

        else
        {
            cout << "The Queue is Empty" << endl;
        }   
    }
};

int main()
{

    Lin_Queue Q1;


    while (1)
    {
        cout << "1. Enqueue \t 2. Dequeue \t 3. Display \t 4. IsFull \t 5. IsEmpty \t 6.Exit" << endl;
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
            if(!Q1.isEmpty()){
                cout << "The dequeued item is" << Q1.dequeue() << endl;
            }

            else{
                Q1.dequeue();
            }
               
                break;

            case 3:
                cout << "The Queue is" << endl;
                Q1.display();
                break;

            case 4:
                if(Q1.isFull()){
                    cout << "The queue is full" << endl;
                }          
                else{
                    cout << "The queue is not full" << endl;
                }
                break;

            case 5:
                if(Q1.isEmpty()){
                    cout << "The queue is Empty" << endl;
                }  
                else{
                    cout << "The queue is not Empty" << endl;
                }  
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