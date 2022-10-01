#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    //destructor
    ~Node()
    {
        int value = this->data;
        if(this->next != NULL)
        {
        delete next;
        this->next = NULL;
        }
      cout<<"memory is free for data for node with data"<<value<<endl;

    }
};
void InsertAtHead(Node* &head,int data1)
{
    //new node create
    Node* temp= new Node(data1);
    temp -> next= head;//new node is connected to the previous head
    head = temp;//the nodee value of the new head is made the head

}
//inserting at tail...
void insertattail(Node* tail,int d)
{
    //new node banaya
    Node* temp = new Node(12);
    tail->next = temp;
    tail = tail->next;// or tail = temp;
}
//insert in the middle
void insertatmiddle(Node* head,int position,int d)
{
    if(position == 1)
    {
        InsertAtHead(head, d);
        return;
    }
    Node* temp = head;
    int count=1;//1st node pe hai hi ham
    while(count<(position-1))
    {
        temp=temp->next;
        count++;
    }
    Node* nodetoinsert = new Node(d);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;
}
//deletion 
void deletenode(int position,Node* head)
{
    //deleting 1st node
    if(position == 1)
    {
        Node* temp = head;
        head=head->next;
        //memory free
        temp->next= NULL;
        delete temp;
    }
    else
    {
        Node* current = head;
        Node* prev = NULL ;
        int count=1;
        while(count<position)
        {
           
              current=current->next;
               prev=current;
              count++;

        }
        prev->next=current->next;
        current->next=NULL;
        delete current;

    }

}
//how to traverse a linked list
void print(Node* &head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;

    }
    cout<<endl;

}
int main()
{
    //creating a new node
    Node* node1=new Node(10);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;
    
    //head pointed to node1
    Node* head= node1;
    Node* tail=node1;
    print(head);
    insertattail(tail,12);
    print(tail);
    
    insertatmiddle(head,1,22);
    print(head);
    


//deletenode(1,head);
//print(head);  

    return 0;
}