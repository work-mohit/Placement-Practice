#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this -> next = NULL;
        }
        // destructor 
        ~Node(){
            int value = this->data;
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }
        }
};
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data;
        cout<<" ";
        temp =temp->next;
    }
}
void insertAtHead(Node* &head, int key){
    Node* temp = new Node(key);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node* &tail, int key){
   
    Node* newNode = new Node(key);
    tail->next = newNode;
    tail = newNode;
}
// generic method for inserting 
void insertAtPosition(Node* &head,Node* &tail, int key, int loc){
    if(loc == 1){
        insertAtHead(head,key);
        return;
    } 
    Node* temp = head;
    int step = 1;
    while(step < loc-1){
        temp = temp ->next;
        step++;
    }
    if(temp -> next == NULL){
        insertAtTail(tail, key);
        return;
    }
    Node* newNode = new Node(key);
    newNode->next= temp->next;
    temp->next = newNode;

}
void deleteNode(Node* &head,Node* &tail, int position){
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL; // whenever delete, first point it to null
        delete temp;
    }else{
        Node* prev = NULL;
        Node* curr = head;
        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if(curr->next == NULL)
            tail = prev;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
    

}
// O(N) O(N)
bool detectLoop(Node* head){
    if(head==NULL)
        return false;
    map<Node*, bool> visited;
    Node* temp  = head;
    while(temp != NULL){
        if(visited[temp] == true)
            return true;
        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
}
// O(N) O(1)
Node* floydLoopDetection(Node* head){
    if(head == NULL)
        return head;
    Node* slow = head;
    Node* fast = head;
    while(slow != NULL || fast != NULL){
        fast = fast -> next;
        if(fast != NULL)
            fast = fast->next;
        slow = slow->next;
        if(slow == fast)
            break;
    }
    return slow;
}
Node* startingOfLoop(Node* head){
    if(head == NULL)
        return NULL;
    Node* intersection = floydLoopDetection(head);
    Node* slow = head;
    while(slow != intersection){
        slow  = slow -> next;
        intersection = intersection -> next;
        if(slow == intersection)
            return slow;
    }
    return NULL;
}

//  it's all about breaking the connection that completes the loop by connecting to the node from where the loop originates.
void removeLoop(Node* head){
    if(head == NULL)
        return;
    Node* intersection = floydLoopDetection(head);
    Node *slow = head, *prev =NULL;
    while(slow != intersection){
        prev = intersection;
        slow  = slow -> next;
        intersection = intersection -> next;
        if(slow == intersection)
            break;
    }
    prev->next = NULL;
    
}
int main(){
    
    Node* node = new Node(10);
    Node* tail = node;
    Node* head = node;

    insertAtHead(head, 29);
    insertAtHead(head,20);
    insertAtHead(head,45);
    insertAtHead(head,63);
    insertAtTail(tail, 1);
    insertAtPosition(head,tail,72,7);

    // cout<<"Before Deleting"<<endl; 
    // print(head);
    // cout<<endl;
    // deleteNode(head,tail, 7);
    // cout<<"After Deleting"<<endl;
    // deleteNode(head,tail, 4);
    // print(head);
    // cout<<endl;
    // print(head);
    tail->next= head->next;  
    // print(head);
    // cout<<"Head:"<<head->data;
    // cout<<endl;
    // cout<<"Tail:"<<tail->data;
    // print(head);
    // Node* temp = startingOfLoop(head);
    // if(temp)
    //     cout<<"starting at "<<temp->data;
    // else
    //     cout<<"No cycle";
    removeLoop(head);
    print(head);
    return 0;
}