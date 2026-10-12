#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node *front, *rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int nilai) {
        Node* baru = new Node{nilai, nullptr};

        if (isEmpty()) {
            front = rear = baru;
        } else {
            rear->next = baru;
            rear = baru;
        }

        cout << nilai << " masuk antrean\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrean kosong\n";
            return;
        }

        Node* hapus = front;
        cout << front->data << " keluar antrean\n";

        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete hapus;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Antrean kosong\n";
        } else {
            cout << "Elemen paling depan: "
                 << front->data << "\n";
        }
    }
};

int main() {
    Queue q;

    cout << "Antrean kosong? " << q.isEmpty() << "\n";

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.peek();
    q.dequeue();
    q.peek();

    cout << "Antrean kosong? " << q.isEmpty() << "\n";

    return 0;
}