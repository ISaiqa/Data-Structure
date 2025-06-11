#include <iostream>
#include"HashMap.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	HashMap users;

    // Insert username-password pairs
    cout << "Inserting users...\n";
    users.insert("Janet", "pass123");
    users.insert("Martha", "pass456");
    users.insert("John", "pass789"); // Possible collision with Janet/Martha

    // Search for passwords
    cout << "\nSearching for passwords:\n";
    cout << "Janet's password: " << users.search("Janet") << endl; // Should print "pass123"
    cout << "Martha's password: " << users.search("Martha") << endl; // Should print "pass456"
    cout << "Unknown user's password: " << users.search("Alice") << endl; // Should print ""

    // Remove a user and verify
    cout << "\nRemoving Janet...\n";
    users.remove("Janet");
    cout << "Janet's password after removal: " << users.search("Janet") << endl; // Should print ""
    cout << "Martha's password after removal: " << users.search("Martha") << endl; // Should print "pass456"

	return 0;
}