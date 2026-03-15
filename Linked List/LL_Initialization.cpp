#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    public:
        int data;
        ListNode* next;

};

void LLInit(int n){
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for(int i=0;i<n;i++){
        int val;
        cout<<"Enter element "<<i+1<<" : ";
        cin>>val;

        ListNode* newNode = new ListNode();
        newNode -> data = val;
        newNode -> next = nullptr;

        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }else{
            tail -> next = newNode;
            tail = newNode;
        }
        
    }
    cout<<"Linked List Initialized";
    cout<<"Given elements:\n";
    ListNode* traverse = head;
    while(traverse != nullptr){
        cout<<traverse->data<<" -> ";
        traverse = traverse-> next;
    }
    cout<<"NULL";
    return;
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    LLInit(n);
    return 0;
}
