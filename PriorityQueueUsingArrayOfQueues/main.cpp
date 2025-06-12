#include <iostream>

#
#include "PQ.h" // Assume PQ class is in PQ.h
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	
    int levels;
    cout << "Enter number of priority levels: ";
    cin >> levels;
    while (levels <= 0)
    {
        cout << "Error: Levels must be positive! Try again: ";
        cin >> levels;
    }

    PQ<int> pq(levels); // Test with int type
    int choice, priority, value;

    do
    {
        cout << "\nPriority Queue Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Check if Empty\n";
        cout << "4. Get Front Value\n";
        cout << "5. Get Rear Value\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Enqueue
            cout << "Enter value to enqueue: ";
            cin >> value;
            cout << "Enter priority (0 to " << levels - 1 << ", 0 = highest): ";
            cin >> priority;
            pq.enqueue(value, priority);
            break;

        case 2: // Dequeue
            if (!pq.isEmpty())
            {
                cout << "Dequeued value: " << pq.dequeue() << endl;
            }
            else
            {
                cout << "Error: Priority queue is empty!" << endl;
            }
            break;

        case 3: // Is Empty
            if (pq.isEmpty())
                cout << "Priority queue is empty!" << endl;
            else
                cout << "Priority queue is not empty!" << endl;
            break;

        case 4: // Front Value
            if (!pq.isEmpty())
            {
                cout << "Front value: " << pq.frontValue() << endl;
            }
            else
            {
                cout << "Error: Priority queue is empty!" << endl;
            }
            break;

        case 5: // Rear Value
            if (!pq.isEmpty())
            {
                cout << "Rear value: " << pq.rearValue() << endl;
            }
            else
            {
                cout << "Error: Priority queue is empty!" << endl;
            }
            break;

        case 6: // Exit
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 6);

   
	return 0;
}


