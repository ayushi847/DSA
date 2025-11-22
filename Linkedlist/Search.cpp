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


int checkIfPresent(Node* head, int val) {

    Node* temp = head;

    while (temp) {
        if (temp->data == val)
            return 1;
        temp = temp->next;
    }

    return 0;
}


Node* convertArr2LL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int main() {

    vector<int> arr = {1, 2, 5, 8, 3};

    Node* head = convertArr2LL(arr);

    cout << checkIfPresent(head, 9);

    return 0;
}
