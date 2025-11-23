
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// PRINT FUNCTION (same as notebook)
void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// REMOVE HEAD (same logic as photo)
Node* removeHead(Node* head) {
    if (head == NULL) return head;

    Node* temp = head;
    head = head->next;
    delete temp;

    return head;
}

// Convert vector to linked list
Node* convertArr2LL(vector<int>& arr) {
    if (arr.size() == 0) return NULL;

    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++) {
        mover->next = new Node(arr[i]);
        mover = mover->next;
    }
    return head;
}

int main() {
    vector<int> arr = {12, 5, 8, 7};

    Node* head = convertArr2LL(arr);

    head = removeHead(head);

    print(head);

    return 0;
}      