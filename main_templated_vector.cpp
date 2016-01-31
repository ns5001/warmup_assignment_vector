/* 

	Use this main function to test your vector class
 	uncomment out these lines as you complete the appropriate functions

*/

#include <iostream>
#include <cstdlib>
#include "TemplatedVector.h"
using namespace std;

int main() {
	TemplatedVector<int> templatedVector;

	/* THESE ARE TESTS TO SEE IF THE BASE REQUIREMENTS ARE MET */
	baseReqCheck(templatedVector);

	/* THESE ARE TESTS TO SEE IF THE INTERMEDIATE LEVEL REQUIREMENTS ARE MET */
	intermediateRequirementsCheck(templatedVector);
	
	/* THESE ARE TESTS TO SEE IF THE ADVANCED LEVEL REQUIREMENTS MET */
	advancedReqCheck(templatedVector);

	return 0;
}

void baseReqTests(TemplatedVector<int>& templatedVector) {
	assert(templatedVector.empty());
	assert(templatedVector.size() == 0);

	// Insert 20 things into the vector
	for (int i = 0; i < 20; i++) {
		templatedVector.push_back(i);
	}

	// Make sure vector is no longer empty
	assert(!templatedVector.empty());

	// Make sure there is exactly 20 things in vector
	assert(templatedVector.size() == 20);

	// Make sure things are in the right place
	assert(templatedVector.at(0) == 0);
	assert(templatedVector.at(5) == 5);
	assert(templatedVector.at(15) == 15);
	assert(templatedVector.at(19) == 19);

	// Let's pop something
	assert(templatedVector.pop_back() == 19);
	assert(templatedVector.size() == 19))
	assert(templatedVector.at(19) == -1)

		// Let's pop everything
		int old = 19;
	while (!templatedVector.empty()) {
		int temp = templatedVector.pop_back();
		assert(temp == old - 1);
		old = temp;
	}

}

void intermediateReqTests(TemplatedVector<int>& templatedVector) {
	assert(templatedVector.empty());
	templatedVector.push_back(5);
	assert(templatedVector.count(5) == 1);
	templatedVector.insert(5, 0);
	templatedVector.insert(5, 2);
	assert(templatedVector.count(5) == 3);
	templatedVector.remove(0);
	assert(templatedVector.count(5) == 2);
	templatedVector.remove(1);
	assert(templatedVector.count(5) == 1);
	templatedVector.remove(0);
}

void advancedReqTests(TemplatedVector<int>& templatedVector) {
	assert(templatedVector.empty());

	TemplatedVector<int> mySecondVector;
	for (int i = 0; i < 100; i++) {
		mySecondVector.push_back(i);
	}

	templatedVector = mySecondVector;

	assert(templatedVector == mySecondVector);
	assert(templatedVector[0] == 0);
	assert(templatedVector[99] == 99);

	templatedVector[0] = 5;

	assert(!(templatedVector == mySecondVector));

	assert(templatedVector[0] == 5);

}
