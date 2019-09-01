/*
*   GeeksforGeeks Link: https://practice.geeksforgeeks.org/problems/remove-duplicates/0
*
*   My solution in C++ to a coding problem on GeeksforGeeks that entails reading in a string, and build a string that
*   contains only one instance of each distinct character. Print the new string. Examples below:
*   
*   mississippi -> misp         missIsSipPi -> misISpP          green beans -> gren bas
*
*   NOTE: When testing this code on GeeksforGeeks, the testcases do not output the same result as when testing
*   on my Visual Studio Code editor. I believe this edition to be correct. If you notice an error, please
*   leave a message. Thanks! :)
*/


#include <iostream>
#include <math.h>
#include <limits>
#include <string.h>
using namespace std;

int main() {
	string original_str = "", new_str = "";
	int testcases;
    int hash[256] = {0};
    // Hash[] allows you to check if a unique char has been read. 0 = not previously read, 1 = previously read.
    // For example, hash[32] is the index for the char '\t' (space). If hash[32] == 1, you have already found a space, so do nothing.
 	
	cin >> testcases;
	cin.ignore();
	for(int i = 0; i < testcases; ++i) {
	    getline(cin, original_str);
	    for(int j = 0; j < original_str.length(); ++j) {
            int index = (int)original_str[j];               // Grab the index for this char.
            if(hash[index] == 0) {                          // You found a new char! :D
	            new_str += original_str[j];
	            hash[index] = -1;
	        }
	    }
        cout << new_str << endl;
	}
	return 0;
}