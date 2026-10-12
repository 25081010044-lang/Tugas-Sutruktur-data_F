#include <iostream>
using namespace std;

struct Node {
    int data;
    int prio;
    Node* next;
};

class PriorityQueue {
private:
    Node* front;

public:
    PriorityQueue() {
        front = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int x, int p) {
        Node* baru = new Node{x, p, nullptr};

        if (isEmpty() || p < front->prio) {
            baru->next = front;
            front = baru;
            return;
        }

        Node* cur = front;

        while (cur->next != nullptr &&
               cur->next->prio <= p) {
            cur = cur->next;
        }

        baru->next = cur->next;
        cur->next = baru;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrean kosong!\n";
            return;
        }

        Node* hapus = front;

        cout << "Data yang keluar: "
             << hapus->data << endl;

        front = front->next;
        delete hapus;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Antrean kosong!\n";
        } else {
            cout << "Data terdepan: "
                 << front->data
                 << ", Prioritas: "
                 << front->prio << endl;
        }
    }

    void tampilkan() {
        Node* cur = front;

        cout << "Isi antrean: ";

        while (cur != nullptr) {
            cout << "[" << cur->data
                 << ", P" << cur->prio << "] ";

            cur = cur->next;
        }

        cout << endl;
    }

    ~PriorityQueue() {
        while (!isEmpty()) {
            Node* hapus = front;
            front = front->next;
            delete hapus;
        }
    }
};

int main() {
    PriorityQueue pq;

    pq.enqueue(10, 3);
    pq.enqueue(20, 1);
    pq.enqueue(30, 2);
    pq.enqueue(40, 1);

    pq.tampilkan();
    pq.peek();

    pq.dequeue();
    pq.tampilkan();

    return 0;
}