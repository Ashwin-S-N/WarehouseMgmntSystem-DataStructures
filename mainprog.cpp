#include<iostream>
#include "stackprog.cpp"

using namespace std;

struct Node{
    string section;
    stack goods;
    Node *next= NULL;
};
Node* create_node(string data){
    Node *new_node=new Node;
    new_node->section=data;
    new_node->next= NULL;
    return new_node;
}

Node* insert_sec(Node *head,string data){
    Node *ptr= create_node(data);
    if(head== NULL){
        head=ptr;
    }
    else{
        Node *temp=head;
        while(temp->next!= NULL)temp=temp->next;
        temp->next=ptr;
    }
    return head;
}

Node* insert_goods(Node *head,string s){
    Node *ptr= NULL;
    Node *tmp=head;
    while(head!=NULL){
        if(tmp->section==s){
            ptr=tmp;
            break;
        }
        tmp=tmp->next;
    }
    ptr->goods.push();
    return head;
}

Node* delete_goods(Node *head,string s){
    Node *ptr= NULL;
    Node *tmp=head;
    while(head!=NULL){
        if(tmp->section==s){
            ptr=tmp;
            break;
        }
        tmp=tmp->next;
    }
    ptr->goods.pop();
    return head;
}

void display_goods(Node *head,string s){
    Node *ptr= NULL;
    Node *tmp=head;
    while(head!=NULL){
        if(tmp->section==s){
            ptr=tmp;
            break;
        }
        tmp=tmp->next;
    }
    ptr->goods.show();
}

Node* del_sec(Node *head){
    if(head== NULL){
        cout<<"Underflow"<<endl;
        return NULL;
    }
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    Node *sec_last=head;
    while(sec_last->next->next!= NULL)sec_last=sec_last->next;
    delete(sec_last->next);
    sec_last->next= NULL;
    return head;
}

void display(Node *head){
    cout<<endl;
    while(head!=NULL)
    {
        cout<<head->section<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    int ch;
    string x,y,s;
    Node *head= NULL;
    cout<<endl;
    do
    {
        cout<<"1.Insert Section 2.Delete Section 3.Insert goods 4.Delete goods 5.Display sections 6.Display goods 7.Quit\n";
        cin>>ch;
            switch(ch)
            {
                case 1:
                    cin>>x;//Section name
                    head=insert_sec(head,x);
                    break;
                case 2:
                    head=del_sec(head);//from end
                    break;
                case 3:
                	cout<<"Enter the section to which you wish the goods to be inserted: ";
                    cin>>s;//Section name
                    head= insert_goods(head,s);
                    break;
                case 4:
                	cout<<"Enter the section to which you wish the goods to be deleted: ";	
                    cin>>s;//Section name
                    head= delete_goods(head,s);
                    break;
                case 5:
                    display(head);//Sections display
                    break;
                case 6:
                	cout<<"Enter the section in which goods should be displayed: ";
                    cin>>s;//Section name
                    cout<<"The goods under section "<<s<<" are:"<<endl;
                    display_goods(head,s);
                    break;
                default:
                    cout<<"Invalid Input"<<endl;
            }
    }
    while(ch!=7);
}
