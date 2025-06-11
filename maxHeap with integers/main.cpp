#include <iostream>
#include"Heap.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// Function to perform heapsort


// Function to demonstrate priority queue functionality


int main(int argc, char** argv) {

    /*Heap<int> h(3); // Create a heap with initial capacity 3

    // Check if heap is empty
    cout << "Is heap empty? " << (h.isEmpty() ? "Yes" : "No") << endl; // Should print "Yes"

    // Insert some elements
    h.insert(5);
    h.insert(3);
    h.insert(7);
    cout << "Is heap empty? " << (h.isEmpty() ? "Yes" : "No") << endl; // Should print "No"
    cout << "Is heap full? " << (h.isFull() ? "Yes" : "No") << endl;   // Should print "Yes"
    cout<<h.getRoot()<<endl;
    
    h.display();

    // Insert one more (will resize)
        // Should print 5

    // Remove all elements
    cout << "Removing remaining elements: ";
    cout << h.remove() << " "; // Should print 5
    cout << h.remove() << " "; // Should print 3
    cout << h.remove() << " "; // Should print 1
    cout << endl;

    // Check if heap is empty
    cout << "Is heap empty? " << (h.isEmpty() ? "Yes" : "No") << endl; // Should print "Yes"

    return 0;*/
    

    Heap<int> h;
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; ++i)
       	cout << arr[i] << " ";
    cout << "\n";

    h.heapSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    cout << "\n";

    

    return 0;
}

