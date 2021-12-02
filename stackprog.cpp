#include<iostream>
using namespace std;


//   Creating a NODE Structure
struct node
{
    int data;
    struct node *next;
};

// Creating a class STACK
class stack
{
    struct node *top;
public:
    stack() // constructor
    {
        top=NULL;
    }
    /*void push(); // to insert an element
    void pop();  // to delete an element
    void show(); // to show the stack- the goods in the section*/

// PUSH Operation
void push()
{
    int value;
    struct node *ptr;
    cout<<"\nPush Operation\n";
    cout<<"Enter the serial number of the good: ";
    cin>>value;
    ptr=new node;
    ptr->data=value;
    ptr->next=NULL;
    if(top!=NULL)
        ptr->next=top;
    top=ptr;
    cout<<"\nNew item is inserted to the stack!\n";

}

// POP Operation
void pop()
{
    struct node *temp;
    if(top==NULL)
    {
        cout<<"\nThe stack is empty!\n";
    }
    temp=top;
    top=top->next;
    cout<<"\nPOP operation\nPopped value is: "<<temp->data<<endl;
    delete temp;
}

// Show stack
void show()
{
    struct node *ptr1=top;
    while(ptr1!=NULL)
    {
        cout<<ptr1->data<<" ->";
        ptr1=ptr1->next;
    }
    cout<<"NULL\n";
}
};
