#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Job Queue Class
class JobQueue {
private:
    queue<string> jobQueue;

public:
    // Function to add a job to the queue
    void addJob(const string& job) {
        jobQueue.push(job);
        cout << "Job added: " << job << endl;
    }

    // Function to delete a job from the queue
    void deleteJob() {
        if (jobQueue.empty()) {
            cout << "No jobs to delete. The queue is empty.\n";
        } else {
            cout << "Job deleted: " << jobQueue.front() << endl;
            jobQueue.pop();
        }
    }

    // Function to display the current job queue
    void displayJobs() {
        if (jobQueue.empty()) {
            cout << "The job queue is empty.\n";
            return;
        }

        cout << "Current job queue:\n";
        queue<string> tempQueue = jobQueue; // Create a temporary copy of the queue
        while (!tempQueue.empty()) {
            cout << tempQueue.front() << endl;
            tempQueue.pop();
        }
    }
};

// Main Function
int main() {
    JobQueue queue;
    int choice;
    string job;

    while (true) {
        cout << "\nJob Queue Menu:\n";
        cout << "1. Add Job\n";
        cout << "2. Delete Job\n";
        cout << "3. Display Jobs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter job name: ";
                cin.ignore(); // Ignore leftover newline from previous input
                getline(cin, job);
                queue.addJob(job);
                break;

            case 2:
                queue.deleteJob();
                break;

            case 3:
                queue.displayJobs();
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
