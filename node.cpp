#include<iostream>
using namespace std;
//SINLGE LINKED LIST NODE CREATION
class Node
{
    public:
    int data ;
    Node* next;
    
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
int main()
{
    Node* node1 = new Node(10);
    cout<<"the head node is"<<endl;
    cout<<node1->data<<":"<<node1->next<<endl;
    return 0;
}