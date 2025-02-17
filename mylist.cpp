#include <iostream>
#include "mylist.h"

using namespace std;

List::List()
{
    head = nullptr;
}

void List::push_front(const Payload& x)
{
    Node* temp = new Node(x);
    temp->next = head;
    head = temp;
}


void List::pop_front()
{
    if (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int List::size() const
{
    Node* current = head;
    int count = 0;

    while (current != nullptr)
    {
        current = current->next;
        count++;
    }

    return count;
}

void List::print() const
{
    Node* current = head;

    while (current != nullptr)
    {
        current->data.print();
        current = current->next;
    }
}

List::~List()
{
    while (head != nullptr)
    {
        pop_front();
    }
}