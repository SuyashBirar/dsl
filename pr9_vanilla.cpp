#include <iostream>
#include <string>
using namespace std;

// Node for linked list
class Node {
public:
    string name;
    Node* next;

    Node(string name) : name(name), next(nullptr) {}
};

// Linked List class for managing sets
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Add a student to the list
    void addStudent(string name) {
        Node* newNode = new Node(name);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Check if a student is in the list
    bool contains(string name) const {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->name == name)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Display the list
    void display() const {
        Node* temp = head;
        if (head == nullptr) {
            cout << "No students.\n";
            return;
        }
        while (temp != nullptr) {
            cout << temp->name << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Compute intersection of two sets
    LinkedList intersection(const LinkedList& other) const {
        LinkedList result;
        Node* temp = head;
        while (temp != nullptr) {
            if (other.contains(temp->name)) {
                result.addStudent(temp->name);
            }
            temp = temp->next;
        }
        return result;
    }

    // Compute union of two sets
    LinkedList unionList(const LinkedList& other) const {
        LinkedList result;
        Node* temp = head;

        // Add all elements of the first list
        while (temp != nullptr) {
            result.addStudent(temp->name);
            temp = temp->next;
        }

        // Add elements of the second list that are not in the first list
        temp = other.head;
        while (temp != nullptr) {
            if (!contains(temp->name)) {
                result.addStudent(temp->name);
            }
            temp = temp->next;
        }
        return result;
    }

    // Compute difference of two sets
    LinkedList difference(const LinkedList& other) const {
        LinkedList result;
        Node* temp = head;
        while (temp != nullptr) {
            if (!other.contains(temp->name)) {
                result.addStudent(temp->name);
            }
            temp = temp->next;
        }
        return result;
    }

    // Count the number of students
    int count() const {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Destructor to free memory
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Main function
int main() {
    LinkedList vanilla, butterscotch, allStudents;
    int numVanilla, numButterscotch, totalStudents;

    // Input total number of students in the class
    cout << "Enter the total number of students in the class: ";
    cin >> totalStudents;

    // Add all students to the universal set
    for (int i = 0; i < totalStudents; i++) {
        string name;
        cout << "Enter the name of student " << i + 1 << ": ";
        cin >> name;
        allStudents.addStudent(name);
    }

    // Input students who like vanilla ice-cream
    cout << "\nEnter the number of students who like vanilla ice-cream: ";
    cin >> numVanilla;
    for (int i = 0; i < numVanilla; i++) {
        string name;
        cout << "Enter the name of student who likes vanilla: ";
        cin >> name;
        vanilla.addStudent(name);
    }

    // Input students who like butterscotch ice-cream
    cout << "\nEnter the number of students who like butterscotch ice-cream: ";
    cin >> numButterscotch;
    for (int i = 0; i < numButterscotch; i++) {
        string name;
        cout << "Enter the name of student who likes butterscotch: ";
        cin >> name;
        butterscotch.addStudent(name);
    }

    // Compute the sets
    LinkedList both = vanilla.intersection(butterscotch);
    LinkedList either = vanilla.unionList(butterscotch).difference(both);
    LinkedList neither = allStudents.difference(vanilla.unionList(butterscotch));

    // Display results
    cout << "\nSet of students who like both vanilla and butterscotch:\n";
    both.display();

    cout << "\nSet of students who like either vanilla or butterscotch but not both:\n";
    either.display();

    cout << "\nSet of students who like neither vanilla nor butterscotch:\n";
    neither.display();

    cout << "\nNumber of students who like neither vanilla nor butterscotch: " << neither.count() << endl;

    return 0;
}
