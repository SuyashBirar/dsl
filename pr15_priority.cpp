#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class PriorityItem {
public:
    T data;       // The data item
    int priority; // The priority associated with the data item

    // Constructor to initialize data and priority
    PriorityItem(T data, int priority) : data(data), priority(priority) {}

    // Overload the <= operator to compare based on priority
    bool operator<=(const PriorityItem<T>& other) const {
        return priority <= other.priority;  // Higher priority comes first, so lower priority value is 'greater'
    }
};

// Class to maintain an inorder list based on priority
template <typename T>
class PriorityList {
private:
    std::vector<PriorityItem<T>> items; // List to store priority items

public:
    // Function to add an item to the list
    void addItem(T data, int priority) {
        PriorityItem<T> newItem(data, priority);
        items.push_back(newItem);
        // Sort the items in descending order of priority
        std::sort(items.begin(), items.end(), [](const PriorityItem<T>& a, const PriorityItem<T>& b) {
            return a.priority > b.priority;  // Sorting in descending order of priority
        });
    }

    // Function to display all items in the list
    void display() {
        if (items.empty()) {
            std::cout << "No items in the list.\n";
            return;
        }

        std::cout << "Items in priority order:\n";
        for (const auto& item : items) {
            std::cout << "Data: " << item.data << ", Priority: " << item.priority << "\n";
        }
    }

    // Function to retrieve and remove the highest priority item
    T getHighestPriorityItem() {
        if (items.empty()) {
            std::cout << "No items to retrieve.\n";
            return T();  // Return default value of T if no items are available
        }

        // Get the highest priority item (the first item in the sorted list)
        T highestPriorityItem = items.front().data;
        items.erase(items.begin());  // Remove the item from the list
        return highestPriorityItem;
    }
};

// Main function to demonstrate the functionality
int main() {
    PriorityList<std::string> pList;

    pList.addItem("Task A", 5);
    pList.addItem("Task B", 8);
    pList.addItem("Task C", 3);
    pList.addItem("Task D", 7);

    pList.display();

    std::cout << "\nRetrieving the highest priority item:\n";
    std::cout << "Highest Priority Item: " << pList.getHighestPriorityItem() << "\n";

    pList.display();

    return 0;
}
