#include <iostream>
using namespace std;

class CircularQueue {
private:
    static const int MAX = 5;
    int data[MAX];
    int front, rear, count;

public:
    CircularQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == MAX;
    }

    void enqueue(int nilai) {
        if (isFull()) {
            cout << "Antrean penuh, " << nilai
                 << " tidak bisa masuk\n";
            return;
        }

        rear = (rear + 1) % MAX;
        data[rear] = nilai;
        count++;

        cout << nilai << " masuk antrean\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrean kosong, tidak ada yang dihapus\n";
            return;
        }

        cout << data[front] << " keluar antrean\n";

        front = (front + 1) % MAX;
        count--;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Antrean kosong\n";
        } else {
            cout << "Elemen paling depan: "
                 << data[front] << "\n";
        }
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.enqueue(60);

    q.dequeue();
    q.dequeue();

    q.enqueue(60);
    q.enqueue(70);

    q.peek();

    cout << boolalpha;
    cout << "Antrean penuh? " << q.isFull() << "\n";

    return 0;
}