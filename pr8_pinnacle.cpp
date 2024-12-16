#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    int prn;
    Node* next;

    Node(string name, int prn) : name(name), prn(prn), next(nullptr) {}
};

class PinnacleClub {
private:
    Node* head;
    Node* tail;

public:
    PinnacleClub() : head(nullptr), tail(nullptr) {}

    // Add a member (can also add president or secretary)
    void addMember(string name, int prn, bool isPresident = false, bool isSecretary = false) {
        Node* newNode = new Node(name, prn);

        if (isPresident) {
            newNode->next = head;
            head = newNode;
            if (tail == nullptr) tail = head; // If the list was empty
            cout << "President added: " << name << " (" << prn << ")\n";
        } else if (isSecretary) {
            if (tail == nullptr) {
                head = tail = newNode; // If the list was empty
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            cout << "Secretary added: " << name << " (" << prn << ")\n";
        } else {
            if (tail == nullptr) {
                head = tail = newNode; // If the list was empty
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            cout << "Member added: " << name << " (" << prn << ")\n";
        }
    }

    // Delete a member by PRN
    void deleteMember(int prn) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }

        // Check if the member to delete is the head (President)
        if (head->prn == prn) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "President deleted.\n";
            return;
        }

        // Traverse to find the member to delete
        Node* curr = head;
        while (curr->next != nullptr && curr->next->prn != prn) {
            curr = curr->next;
        }

        if (curr->next == nullptr) {
            cout << "Member with PRN " << prn << " not found.\n";
            return;
        }

        // Check if the member to delete is the tail (Secretary)
        if (curr->next == tail) {
            Node* temp = tail;
            tail = curr;
            tail->next = nullptr;
            delete temp;
            cout << "Secretary deleted.\n";
        } else {
            // Delete the member in the middle
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            cout << "Member with PRN " << prn << " deleted.\n";
        }
    }

    // Compute total number of members
    int computeTotalMembers() {
        int count = 0;
        Node* curr = head;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        return count;
    }

    // Display members
    void displayMembers() {
        if (head == nullptr) {
            cout << "No members in the club.\n";
            return;
        }

        Node* curr = head;
        cout << "Club Members:\n";
        while (curr != nullptr) {
            cout << "Name: " << curr->name << ", PRN: " << curr->prn << "\n";
            curr = curr->next;
        }
    }

    // Concatenate two lists
    void concatenate(PinnacleClub& other) {
        if (head == nullptr) {
            head = other.head;
            tail = other.tail;
        } else if (other.head != nullptr) {
            tail->next = other.head;
            tail = other.tail;
        }
        other.head = nullptr; // Clear the other list
        other.tail = nullptr;
        cout << "Lists concatenated successfully.\n";
    }

    // Destructor to clean up memory
    ~PinnacleClub() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
};

// Main function to test the program
int main() {
    PinnacleClub divisionA, divisionB;

    // Add members to Division A
    divisionA.addMember("Suyash", 101, true);       // President
    divisionA.addMember("Aditya", 102);
    divisionA.addMember("Shubham", 103);
    divisionA.addMember("Nachiket", 104, false, true); // Secretary

    // Add members to Division B
    divisionB.addMember("Harshad", 201, true);       // President
    divisionB.addMember("Krishhna", 202);
    divisionB.addMember("Yash", 203, false, true); // Secretary

    // Display members of Division A
    cout << "\nDivision A Members:\n";
    divisionA.displayMembers();

    // Display members of Division B
    cout << "\nDivision B Members:\n";
    divisionB.displayMembers();

    // Compute total members in Division A
    cout << "\nTotal members in Division A: " << divisionA.computeTotalMembers() << "\n";

    // Delete a member from Division A
    divisionA.deleteMember(102); // Delete Alice

    // Display members of Division A after deletion
    cout << "\nDivision A Members after deletion:\n";
    divisionA.displayMembers();

    // Concatenate Division B into Division A
    divisionA.concatenate(divisionB);

    // Display members of Division A after concatenation
    cout << "\nDivision A Members after concatenation:\n";
    divisionA.displayMembers();

    // Compute total members in Division A after concatenation
    cout << "\nTotal members in Division A after concatenation: " << divisionA.computeTotalMembers() << "\n";

    return 0;
}
