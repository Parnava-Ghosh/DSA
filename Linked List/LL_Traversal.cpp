#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;
};

vector<int> LLTraversal(ListNode *head){
    vector<int> arr;
    ListNode* temp = head;

    while(temp != nullptr){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    return arr;
}

int main(){
    ListNode* head = new ListNode();
    head->data = 1;

    ListNode* second = new ListNode();
    second->data = 2;

    ListNode* third = new ListNode();
    third->data = 3;

    head->next = second;
    second->next = third;
    third->next = nullptr;

    vector<int> result = LLTraversal(head);

    for(int i = 0; i < result.size(); i++){
        cout<<result[i]<<" -> ";
    }
    cout<< "NULL" <<endl;

    return 0;
}