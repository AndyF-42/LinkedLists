//Creator: Andy Fleischer
//Date: 10/30/20
//Main class for project

#include "Node.h"
#include <iostream>

using namespace std;

void add(Node* &head, Student* newStudent);
void print(Node* head, Node* next);

int main() {

  Node* head = NULL;
  add(head, new Student((char*)("Joe"), (char*)("Smith"), 123456, 1.2));
  print(head, head);
  add(head, new Student((char*)("Adam"), (char*)("Jones"), 321654, 2.7));
  print(head, head);
  add(head, new Student((char*)("Sally"), (char*)("Hill"), 400400, 3.5));
  print(head, head);

  return 0;
}

//add a new node (holding a new student) to the linked list
void add(Node* &head, Student* newStudent) {
  Node* current = head;
  if (current == NULL) { //head is NULL, meaning no data in linked list yet
    head = new Node(newStudent);
  }
  else {
    while (current->getNext() != NULL) { //get to last node in list
      current = current->getNext();
    }
    current->setNext(new Node(newStudent));
  }
}

//print out the student data of every node in the linked list
void print(Node* head, Node* next) {
  if (next == head) { //only go here the first time
    cout << "Students:" << endl;
  }
  if (next != NULL) {
    cout << next->getStudent()->getFirst();
    cout << " " << next->getStudent()->getLast();
    cout << ", ID: " << next->getStudent()->getID();
    cout << ", GPA: " << next->getStudent()->getGPA() << endl;
    print(head, next->getNext());
  }
}
