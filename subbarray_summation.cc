/*
*   GeeksforGeeks Link: https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
*
*   My solution in C++ to a coding problem on GeeksforGeeks that entails finding a sequence of values in an unsorted array
*   such that the sequence is a summation equal to a value given by the user. If the sequence exists, print its starting and
*   ending index values, otherwise print -1.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int testcases, vecsize, usersum;
	cin >> testcases;
	for(int i = 0; i < testcases; ++i) {
	    int firstindex = 0, lastindex = 0, addup = 0; 
	    vector<int> vec;
	    cin >> vecsize;
	    cin >> usersum;

	    // Do work while loading values into the vector (save time).
	    for(int j = 0; j < vecsize; ++j) {
	        int vecvalue;
	        cin >> vecvalue;
	        vec.push_back(vecvalue);
	        addup += vecvalue;
	        lastindex = j;
            
	        while(addup > usersum) {        // Enter while loop if your sequence summation > sum.
	            addup -= vec[firstindex];   // Delete as many values from front of sequence as necessary.
	            firstindex++;
	        }
            
	        if(addup == usersum) {          // Found your answer! :D
	            cout << firstindex+1 << " " << lastindex+1 << endl;
	            j++;
	            // Get rest of user input before moving to next test case to avoid conflicts.
	            while(j < vecsize) {
	                cin >> vecvalue;
	                j++;
	            }
	        }
	    }

        // You found no answer. :(
	    if(addup != usersum) {
	        cout << -1 << endl;
	    }
	}
	return 0;
}