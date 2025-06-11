// Hash map class to store username-password pairs
#include "C:\Users\abc\OneDrive\Desktop\LinkedList1\LinkedList.h"
#include"HashNode.h"

class HashMap 
{
	private:
    	LinkedList<HashNode>** arr; // Dynamic array of LinkedList pointers
    	int size;                   // Table size (default 5)
    	int hashF(string key);      // Hash function for strings

	public:
		HashMap(int size=5) 
		{
    		this->size = size;
    		arr = new LinkedList<HashNode>*[size];
    		for (int i = 0; i < size; i++) 
			{
        		arr[i] = nullptr;
    		}
		}                
		~HashMap() 
		{
    		for (int i = 0; i < size; i++) 
			{
        		if (arr[i]) 
				{
            		delete arr[i];
       			}
    		}
    		delete[] arr;
		}// Destructor
    	void insert(string username, string password); // Insert or update pair
    	string search(string username); // Search for password
    	void remove(string username);  // Remove pair
};
// Hash function: Sum ASCII values mod size
int HashMap::hashF(string key) 
{
    int sum = 0;
    for (char c : key) 
	{
        sum += c; // Sum ASCII values
    }
    /*
    for (int i = 0; i < key.length(); i++) 
	{
  		sum += key[i];
	}

	*/
    return sum % size;
}

// Insert or update username-password pair
void HashMap::insert(string username, string password) 
{
    int i = hashF(username);
    if (arr[i] == nullptr) 
	{
        arr[i] = new LinkedList<HashNode>();
    }
    // Check if username exists to update password
    Node<HashNode>* node = arr[i]->Search(HashNode(username));
    if (node != nullptr) 
	{
        node->getInfo().value = password; // Update password
    } 
	else 
	{
        arr[i]->addToHead(HashNode(username, password)); // Add new pair
    }
}

// Search: Return password or empty string
string HashMap::search(string username) 
{
    int i= hashF(username);
    if (arr[i] == nullptr) 
	{
        return ""; // Not found
    }
    Node<HashNode>* node = arr[i]->Search(HashNode(username, ""));
    if (node == nullptr) 
	{
        return ""; // Not found
    }
    return node->getInfo().value; // Return password
}

// Remove: Delete username-password pair
void HashMap::remove(string username) 
{
    int i= hashF(username);
    if (arr[i] == nullptr) 
	{
        return; // Not found
    }
    arr[i]->deleteBySearch(HashNode(username, ""));
}

