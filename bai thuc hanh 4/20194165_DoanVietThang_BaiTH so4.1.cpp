#include <iostream> 
using namespace std;
struct Node {
    int data;
    Node* next;
};

// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
    Node* q = new Node;
    q->data = data;
    q->next = head;
    head = q;
    return q;
}

// print the list content on a line
void print(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// return the new head of the reversed list
Node* reverse(Node* head) {
    Node* prev = NULL, * next = NULL;
    while (head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

int main() {
    cout << "Doan Viet Thang" << endl;
    cout << "20194165" << endl;
    cout << endl;
    int n, u;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i) {
        cin >> u;
        head = prepend(head, u);
    }

    cout << "Original list: ";
    print(head);

    head = reverse(head);

    cout << "Reversed list: ";
    print(head);

    return 0;
}