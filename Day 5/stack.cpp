#include<iostream>

using namespace std;

struct node{
    int data;
    node *next;
};

class Stack{
    public:
    node *top;

    Stack(){
        top = NULL;
    }
  
    void push(int);
    int pop();
    void display();
    void peek();
    bool isEmpty();
};

void Stack :: push(int item){
    node *curr = new node;
    curr -> data = item;
    curr -> next = top;
    top = curr;
}

int Stack::pop(){

      int x;

      if(top==NULL){
            cout<<"stack is empty"<<endl;
            return INT_MIN;
      }
      node *temp=new(nothrow) node;

      if(temp==NULL){
            cout<<"Failed"<<endl;
            return INT_MIN;
      }

      temp=top;
      x=temp->data;
      top=top->next;
      delete temp;
      return x;
}

bool Stack::isEmpty(){
      return top==NULL;
}
