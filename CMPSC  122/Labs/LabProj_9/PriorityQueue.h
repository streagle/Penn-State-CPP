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
// Assignment: Lab 09
//

#pragma once

#include <vector>

#include <iostream>

#include <string>

using namespace std;

template <class T>

class PriorityQueue

{

public:
    PriorityQueue();

    ~PriorityQueue();

    void Insert(T item, int priority);

    T Peek();

    void Pull();

    void ChangePriority(T item, int newPriority);

    bool IsEmpty();

    void PrintQueue();

    

private:
    struct Node

    {

        T data;

        int priority;
    };

    vector<Node> queue;
};

template <class T>

PriorityQueue<T>::PriorityQueue(){

}

template <class T>

PriorityQueue<T>::~PriorityQueue(){

}

template <class T>

void PriorityQueue<T>::Insert(T item, int priority)

{

    Node newNode;
    newNode.data = item;
    newNode.priority = priority;

    if (queue.size() == 0)

    {
        queue.push_back(newNode);
    }

    else

    {
        for (int i = 0; i < queue.size(); i++)
        {
            if (queue[i].data == item)
            {
                cout << "Error: Duplicated item." << endl;
                return;
            }
        }

        for (int i = 0; i < queue.size(); i++)
        {
            if (priority > queue[i].priority)
            {
                queue.insert(queue.begin() + i, newNode);
                return;
            }
        }
        queue.push_back(newNode);
    }
}

template <class T>

T PriorityQueue<T>::Peek()

{

    if (queue.size() == 0)
    {
        cout << "Error: The queue is empty." << endl;
        return T();
    }
    return queue[0].data;
}

template <class T>

void PriorityQueue<T>::Pull()

{

    if (queue.size() == 0)
    {
        cout << "Error: The queue is empty." << endl;
        return;
    }

    queue.erase(queue.begin());
}

template <class T>

void PriorityQueue<T>::ChangePriority(T item, int newPriority)

{
    for (int i = 0; i < queue.size(); i++)
    {
        if (queue[i].data == item)
        {
            queue[i].priority = newPriority;
            return;
        }
    }
    cout << "Error: Item not found." << endl;
}

template <class T>

bool PriorityQueue<T>::IsEmpty()
{
    return queue.size() == 0;
}

template <class T>

void PriorityQueue<T>::PrintQueue()

{
    for (int i = 0; i < queue.size(); i++)
    {
        cout << queue[i].data << " " << queue[i].priority << endl;
    }
}

/* -------------------------------------------------------------------------- */
/*                                   OUTPUT                                   */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./LabProj_9
Successfully created an empty priority queue for strings.
Insert string "Homework Due Today" to the priority queue with priority value 20.
Insert string "Play Games" to the priority queue with priority value 3.
Insert string "Prepare Dinner" to the priority queue with priority value 30.
Insert string "Exam" to the priority queue with priority value 70.
Insert string "Workout" to the priority queue with priority value 15.
Insert string "Homework Due Today" to the priority queue with priority value 45.
Error: Duplicated item.
Current item with the highest priority: Exam
Removing the highest priority item...
Current item with the highest priority: Prepare Dinner
Change the priority of item "Homework Due Today" to 50.
Current item with the highest priority: Prepare Dinner
Removing the two highest priority item...
Current item with the highest priority: Workout
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/