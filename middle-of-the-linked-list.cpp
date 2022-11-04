#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* createLinkedList(vector<int> values);
void printLinkedList(ListNode* head);
ListNode* middleNode(ListNode* head);

int main(int argc, char const* argv[]) {
  vector<int> v1 = {5, 32, 1, 2, 93, 75, 89};
  vector<int> v2 = {6, 2, 30, 34};

  ListNode* list1 = createLinkedList(v1);
  ListNode* list2 = createLinkedList(v2);
  ListNode *mlist1, *mlist2;  // middle node of list1 and li

  printLinkedList(list1);
  printLinkedList(list2);

  // Get middle nodes
  mlist1 = middleNode(list1);
  mlist2 = middleNode(list2);

  // Print list from middle nodes
  printLinkedList(mlist1);
  printLinkedList(mlist2);

  return 0;
}

ListNode* middleNode(ListNode* head) {
  ListNode* node;
  int totalNodes = 0;

  // if list has one or no nodes
  if ((head == nullptr) || (head->next == nullptr))
    return head;

  node = head;
  while (node != nullptr) {
    node = node->next;
    totalNodes++;
  }

  // cout << "total nodes: " << totalNodes << "\n";

  node = head;
  for (int i = 1; i <= (totalNodes / 2); i++) {
    node = node->next;
  }

  // cout << "middle node value: " << node->val << endl;

  return node;
}

// Create Linked list given a vector of int values
// returns pointer to head of lined list
ListNode* createLinkedList(vector<int> values) {
  ListNode* head;
  ListNode* node = new ListNode();
  head = node;
  for (int value : values) {
    node->next = new ListNode(value);
    node = node->next;
  }
  head = head->next;
  return head;
}

// Prints Linked List
// e.g. 5->8->3->NULL
void printLinkedList(ListNode* head) {
  ListNode* node = head;

  while (node != nullptr) {
    cout << node->val << "->";
    node = node->next;
  }
  cout << "NULL\n";
}