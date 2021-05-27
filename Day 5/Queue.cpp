#include<iostream>

using namespace std;

struct node{
    int data;
    node *next;
};

class queue{
    node *front, *rear;
    public:
        queue(){
            front = rear = NULL;
        }
    void insert(int);
    int del();
    void display();
    bool isEmpty();
};

void queue::insert(int item){
    node *curr = new node;
    curr -> data = item;
    curr -> next = NULL;

    if(rear == NULL){
        rear = front = curr;
        return;
    }
    else
    {
        rear -> next = curr;
        rear = curr;
    }
}

int queue::del(){

      int x;

      if(rear==NULL){
            cout<<"queue is empty"<<endl;
            return INT_MIN;
      }
      node *temp=new(nothrow) node;

      if(temp==NULL){
            cout<<"Failed"<<endl;
            return INT_MIN;
      }

      temp=front;

      x=temp->data;
      front=front->next;
      if(front==NULL) rear=NULL;
      delete temp;
      return x;
}


bool queue::isEmpty(){
      return rear==NULL;
}