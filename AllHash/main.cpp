#include <iostream>
#include"Hash.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Hash<int> h_int(5);
    h_int.insertV(12);
    h_int.insertV(18);
    h_int.displayAll(); // e.g., Empty at [0] Empty at [1] At [2]( 18 12 ) Empty at [3] Empty at [4]
    cout << "Search 12: " << h_int.search(12) << endl; // 1

    Hash<char> h_char(5);
    h_char.insertV('J');
    h_char.insertV('M');
    h_char.displayAll(); // e.g., Empty at [0] Empty at [1] Empty at [2] Empty at [3] At [4]( M J )
    cout << "Search J: " << h_char.search('J') << endl; // 1

    Hash<string> h_string(5);
    h_string.insertV("Janet");
    h_string.insertV("Martha");
    h_string.displayAll(); // e.g., depends on hash, e.g., At [3]( Martha Janet )
    cout << "Search Janet: " << h_string.search("Janet") << endl; // 1

	
	return 0;
}