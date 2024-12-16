#include <iostream>
using namespace std;

class Deque {
private:
    int *arr;
    int front, rear, size, capacity;

public:
    // Constructor to initialize the deque
    Deque(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = 0;
        size = 0;
    }

    // Destructor to free allocated memory
    ~Deque() {
        delete[] arr;
    }

    // Function to check if the deque is full
    bool isFull() {
        return size == capacity;
    }

    // Function to check if the deque is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to add an element at the front
    void addFront(int value) {
        if (isFull()) {
            cout << "Deque is full. Cannot add element at front.\n";
            return;
        }
        // If deque is empty, both front and rear should point to the same location
        if (isEmpty()) {
            front = rear = 0;
        } else {
            // Decrement front circularly
            front = (front - 1 + capacity) % capacity;
        }
        arr[front] = value;
        size++;
    }

    // Function to add an element at the rear
    void addRear(int value) {
        if (isFull()) {
            cout << "Deque is full. Cannot add element at rear.\n";
            return;
        }
        // If deque is empty, both front and rear should point to the same location
        if (isEmpty()) {
            front = rear = 0;
        } else {
            // Increment rear circularly
            rear = (rear + 1) % capacity;
        }
        arr[rear] = value;
        size++;
    }

    // Function to delete an element from the front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete element from front.\n";
            return;
        }
        cout << "Deleted " << arr[front] << " from front.\n";
        // If only one element is present
        if (front == rear) {
            front = rear = -1;
        } else {
            // Increment front circularly
            front = (front + 1) % capacity;
        }
        size--;
    }

    // Function to delete an element from the rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete element from rear.\n";
            return;
        }
        cout << "Deleted " << arr[rear] << " from rear.\n";
        // If only one element is present
        if (front == rear) {
            front = rear = -1;
        } else {
            // Decrement rear circularly
            rear = (rear - 1 + capacity) % capacity;
        }
        size--;
    }

    // Function to display the elements of the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }
        cout << "Deque elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

// Main function
int main() {
    int capacity;
    cout << "Enter the capacity of the deque: ";
    cin >> capacity;

    Deque dq(capacity);
    int choice, value;

    while (true) {
        cout << "\nDeque Menu:\n";
        cout << "1. Add element at front\n";
        cout << "2. Add element at rear\n";
        cout << "3. Delete element from front\n";
        cout << "4. Delete element from rear\n";
        cout << "5. Display deque\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to add at front: ";
                cin >> value;
                dq.addFront(value);
                break;
            case 2:
                cout << "Enter value to add at rear: ";
                cin >> value;
                dq.addRear(value);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                dq.display();
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
