
using namespace std;

// Node for hash map to store key-value pair
class HashNode {
	public:
    string key;   // Username (e.g., "Janet")
    string value; // Password (e.g., "pass123")
    HashNode* next;

    HashNode(string k = "", string v = "", HashNode* n = nullptr) 
	{
        key = k;
        value = v;
        next = n;
    }
    bool operator!=(const HashNode& other) const 
	{
        return key != other.key; // Compare usernames
    }
    bool operator==(const HashNode& other) const 
	{
    return key == other.key;
     }
};