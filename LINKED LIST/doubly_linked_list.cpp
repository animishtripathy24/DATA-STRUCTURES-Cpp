#include<iostream>
using namespace std;


class Node
{
    public:
        int data;
        Node* prev;
        Node* next;
    //constructor
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
    ~Node()
    {
        int value=this->data;
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout << "Memory freed for node with data " << value << endl;
    }
};

void insertAtHead(Node* &head,Node* &tail,int data)
{
    //in case the list is empty
    if(head==NULL)
    {
        Node* temp=new Node(data);
        head=temp;
        tail=temp;
    }
    else
    {
        Node*temp=new Node(data);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}

void insertAtTail(Node* &head,Node * &tail,int data)
{
    //in case the list is empty
    if(tail==NULL)
    {
        Node* temp=new Node(data);
        head=temp;
        tail=temp;
    }
    else
    {
        Node* temp=new Node(data);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}

void insertAtPosition(Node* &head,Node* &tail,int data,int position)
{
    if(position==1)
    {
        insertAtHead(head,tail,data);
        return;
    }
    int count=1;
    Node* curr=head;

    while(count < position-1)
    {
        curr=curr->next;
        count++;
    }
    if(curr->next==NULL)
    {
        insertAtTail(head,tail,data);
        return;
    }
    Node* temp=new Node(data);

    temp->next=curr->next;
    curr->next->prev=temp;
    curr->next=temp;
    temp->prev=curr;
    
}

void deleteAtHead(Node* &head)
{
    Node* temp=head;
    head=head->next;
    head->prev=NULL;
    temp->next=NULL;
    delete temp;
}

void deleteAtTail(Node* &head,Node* &tail)
{
    Node*curr=head;
    while(curr != tail)
    {
        curr=curr->next;
    }
    tail=tail->prev;
    tail->next=NULL;
    curr->prev=NULL;
    delete curr;
}

void deleteAtTail2(Node* &tail,Node* &current,Node* &prev)
{
    tail=tail->prev;
    prev->next=current->next;
    current->prev=NULL;
    delete current;
}

void deleteAtPosition(Node* &head,Node* &tail,int position)
{
    if(position==1)
    {
        deleteAtHead(head);
    }
    else
    {
        //deleting any middle node or last node
		Node* current = head;
		Node* prev =NULL;
		int count = 1;
		while(count < position)
		{
			prev = current;
			current = current->next;
			count++;
		}
        //if we have to delete the tail node then how to handle the tail pointer problem
		if(current->next == NULL )
		{
			deleteAtTail2(tail,current,prev);
			return;
		}
		else
		{
            current->prev=NULL;
            prev->next=current->next;
            current->next=NULL;
            delete current;
		}
    }
}

//traversing the doubly linked list
void print(Node* &head)
{
    Node* temp=head;

    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
}

int getLength(Node* &head)
{
    Node* temp=head;
    int count = 0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;  
}

int main()
{
    Node* node1=new Node(10);
    //head will be pointing to the first node
    Node* head=node1;
    //at first tail will be pointing to the first node
    Node* tail=node1;

    print(head);
    cout << "Current length of the linked list is : "  << getLength(head) << endl;
    cout << "Head is : " << head->data << endl;
    cout << "Tail is : " << tail->data << endl;
    cout << endl << endl;

    insertAtHead(head,tail,12);
    print(head);
    cout << "Current length of the linked list is : "  << getLength(head) << endl;
    cout << "Head is : " << head->data << endl;
    cout << "Tail is : " << tail->data << endl;
    cout << endl << endl;

    insertAtHead(head,tail,14);
    print(head);
    cout << "Current length of the linked list is : "  << getLength(head) << endl;
    cout << "Head is : " << head->data << endl;
    cout << "Tail is : " << tail->data << endl;
    cout << endl << endl;

    insertAtTail(head,tail,8);
    print(head);
    cout << "Current length of the linked list is : "  << getLength(head) << endl;
    cout << "Head is : " << head->data << endl;
    cout << "Tail is : " << tail->data << endl;
    cout << endl << endl;

    insertAtTail(head,tail,6);
    print(head);
    cout << "Current length of the linked list is : "  << getLength(head) << endl;
    cout << "Head is : " << head->data << endl;
    cout << "Tail is : " << tail->data << endl;
    cout << endl << endl;

    insertAtPosition(head,tail,50,6);
    print(head);
    cout << "Current length of the linked list is : "  << getLength(head) << endl;
    cout << "Head is : " << head->data << endl;
    cout << "Tail is : " << tail->data << endl;
    cout << endl << endl;

    insertAtPosition(head,tail,90,1);
    print(head);
    cout << "Current length of the linked list is : "  << getLength(head) << endl;
    cout << "Head is : " << head->data << endl;
    cout << "Tail is : " << tail->data << endl;
    cout << endl << endl;

    insertAtPosition(head,tail,200,4);
    print(head);
    cout << "Current length of the linked list is : "  << getLength(head) << endl;
    cout << "Head is : " << head->data << endl;
    cout << "Tail is : " << tail->data << endl;
    cout << endl << endl;

    deleteAtHead(head);
    print(head);
    cout << "Current length of the linked list is : "  << getLength(head) << endl;
    cout << "Head is : " << head->data << endl;
    cout << "Tail is : " << tail->data << endl;
    cout << endl << endl;

    deleteAtTail(head,tail);
    print(head);
    cout << "Current length of the linked list is : "  << getLength(head) << endl;
    cout << "Head is : " << head->data << endl;
    cout << "Tail is : " << tail->data << endl;
    cout << endl << endl;

    deleteAtTail(head,tail);
    print(head);
    cout << "Current length of the linked list is : "  << getLength(head) << endl;
    cout << "Head is : " << head->data << endl;
    cout << "Tail is : " << tail->data << endl;
    cout << endl << endl;

    deleteAtPosition(head,tail,1);
    print(head);
    cout << "Current length of the linked list is : "  << getLength(head) << endl;
    cout << "Head is : " << head->data << endl;
    cout << "Tail is : " << tail->data << endl;
    cout << endl << endl;

    deleteAtPosition(head,tail,4);
    print(head);
    cout << "Current length of the linked list is : "  << getLength(head) << endl;
    cout << "Head is : " << head->data << endl;
    cout << "Tail is : " << tail->data << endl;
    cout << endl << endl;

    deleteAtPosition(head,tail,2);
    print(head);
    cout << "Current length of the linked list is : "  << getLength(head) << endl;
    cout << "Head is : " << head->data << endl;
    cout << "Tail is : " << tail->data << endl;
    cout << endl << endl;





}