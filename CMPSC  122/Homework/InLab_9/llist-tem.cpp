// Academic Integrity Affidavit:
// I certify that this program code is my work. Others may have
// assisted me with planning and concepts, but the code was written,
// solely, by me.
// I understand that submitting code that is totally or partially
// the product of other individuals is a violation of the Academic
// Integrity Policy and accepted ethical precepts. Falsified
// execution results are also results of improper activities. Such
// violations may result in zero credit for the assignment, reduced
// credit for the assignment, or course failure.
//
// Name: <Ryan Reagle>
// Section: <003L>
// Assignment: InLab 09
//
#include <iostream>


using namespace std;


// Declation of Node class template
template <typename T>
class Node{
public:
    T data;
    Node<T> * next;
};

// Insert. Fill in your code here...
template <typename T>
void insert(Node<T>*& first, int position, T value) {
    Node<T>* newNode = new Node<T>();
    newNode->data = value;
    newNode->next = nullptr;

    if (position == 0) {
        newNode->next = first;
        first = newNode;
        return;
    }

    Node<T>* cur = first;
    for (int i = 0; i < position - 1 && cur != NULL; ++i) {
        cur = cur->next;
    }

    if (cur == nullptr) {
        cerr << "Position out of bounds" << endl;
        delete newNode;
        return;
    }

    newNode->next = cur->next;
    cur->next = newNode;
}


// Display
template <typename T>
void display(Node<T> * first){
    Node<T> * cur = first;
    while(cur != nullptr){
        cout << (cur->data) << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main(){
    Node<int> * ifirst = nullptr; // Empty linked list of integer
    insert<int>(ifirst, 0, 5);//5
    insert<int>(ifirst, 0, 6);//6 5 
    insert<int>(ifirst, 0, 7);//7 6 5
    insert<int>(ifirst, 1, 8);//7 8 6 5
    insert<int>(ifirst, 4, 100);// 7 8 6 5 100
    cout << "A Linked List of Integers: " << endl;
    display<int>(ifirst);
    
    Node<double> * dfirst = nullptr; // Empty linked list of doubles
    insert<double>(dfirst, 0, 5.4);// 5.4
    insert<double>(dfirst, 0, 23.4);// 23.4 5.4
    insert<double>(dfirst, 0, 7.253);// 7.253 23.4 5.4
    insert<double>(dfirst, 1, 100.45);// 7.253 100.45 23.4 5.4
    insert<double>(dfirst, 4, 15.84);// 7.253 100.45 23.4 5.4 15.84
    cout << "A Linked List of Doubles: "  << endl;
    display<double>(dfirst);
}
/* -------------------------------------------------------------------------- */
/*                                   OUTPUT                                   */
/* -------------------------------------------------------------------------- */
/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"llist-tem"
A Linked List of Integers: 
7 8 6 5 100 
A Linked List of Doubles: 
7.253 100.45 23.4 5.4 15.84 
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/