#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
};

Node *head;

void insert(int data) {
  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = nullptr;

  if (head == nullptr) {
    head = newNode;
  } else {
    Node *current = head;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = newNode;
  }
}

void printList() {
  Node *current = head;
  while (current != nullptr) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

void selectionSort() {
  Node *current = head;
  Node *minNode = nullptr;

  while (current != nullptr) {
    minNode = current;
    Node *next = current->next;
    while (next != nullptr) {
      if (next->data < minNode->data) {
        minNode = next;
      }
      next = next->next;
    }

    if (minNode != current) {
      int temp = current->data;
      current->data = minNode->data;
      minNode->data = temp;
    }
    current = current->next;
  }
}

int main() {
  head = nullptr;

  insert(5);
  insert(2);
  insert(7);
  insert(1);
  insert(3);

  cout << "Liste avant tri :" << endl;
  printList();

  selectionSort();

  cout << "Liste après tri :" << endl;
  printList();

  return 0;
}
