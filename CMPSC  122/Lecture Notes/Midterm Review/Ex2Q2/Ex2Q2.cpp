#include <iostream>
#include <iomanip>
#include <cmath>


using namespace std;
//Methods

class Node {
public:
int data;
Node * next;
};



int FindMiddle(Node* first){
    Node* slow = first;
    Node* fast = first;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

int main(){
//Variables

// Create linked list with values 2, 4, 3, 5, 6
Node* head = new Node();
Node* second = new Node();
Node* third = new Node();
Node* fourth = new Node();
Node* fifth = new Node();

head->data = 2;
head->next = second;

second->data = 4;
second->next = third;

third->data = 5;
third->next = fourth;

fourth->data = 5;
fourth->next = fifth;

fifth->data = 6;
fifth->next = nullptr;

// Find the middle element

int middle = FindMiddle(head);
cout << "The middle element is: " << middle << endl;



//Inputs



//Processes



//Outputs



return 0;
}