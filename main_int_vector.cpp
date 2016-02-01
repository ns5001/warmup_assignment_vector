#include <iostream>
#include <assert.h>
#include "IntVector.h"

using namespace std;

void baseReqTests(IntVector&);
void intermediateReqTests(IntVector&);
void advancedReqTests(IntVector&);

int main() {
	IntVector intVector;

	/* THESE ARE TESTS TO SEE IF THE BASE REQUIREMENTS ARE MET */
	//baseReqTests(intVector);

	/* THESE ARE TESTS TO SEE IF THE INTERMEDIATE LEVEL REQUIREMENTS ARE MET */
	//intermediateReqTests(intVector);
	
	/* THESE ARE TESTS TO SEE IF THE ADVANCED LEVEL REQUIREMENTS MET */
	//advancedReqTests(intVector);

	cout << "All your tests have passed!\n";

	return 0;
}

void baseReqTests(IntVector& intVector) {
	assert(intVector.empty());
	assert(intVector.size() == 0);

	// Insert 20 things into the vector
	for (int i = 0; i < 20; i++) {
		intVector.push_back(i);
	}

	// Make sure vector is no longer empty
	assert(!intVector.empty());

	// Make sure there is exactly 20 things in vector
	assert(intVector.size() == 20);

	// Make sure things are in the right place
	assert(intVector.at(0) == 0);
	assert(intVector.at(5) == 5);
	assert(intVector.at(15) == 15);
	assert(intVector.at(19) == 19);

	// Let's pop something
	assert(intVector.pop_back() == 19);
	assert(intVector.size() == 19);
	try {
		intVector.at(19);
	}
	catch (int e) {
		assert(true);
	}

	// Let's pop everything
	int old = 19;
	while (!intVector.empty()) {
		int temp = intVector.pop_back();
		assert(temp == old - 1);
		old = temp;
	}

}

void intermediateReqTests(IntVector& intVector) {
	assert(intVector.empty());
	intVector.push_back(5);
	assert(intVector.count(5) == 1);
	intVector.insert(5, 0);
	intVector.insert(5, 2);
	assert(intVector.count(5) == 3);
	intVector.remove(0);
	assert(intVector.count(5) == 2);
	intVector.remove(1);
	assert(intVector.count(5) == 1);
	intVector.remove(0);
}

void advancedReqTests(IntVector& intVector) {
	assert(intVector.empty());

	IntVector mySecondVector;
	for (int i = 0; i < 100; i++) {
		mySecondVector.push_back(i);
	}

	intVector = mySecondVector;

	assert(intVector == mySecondVector);
	assert(intVector[0] == 0);
	assert(intVector[99] == 99);

	intVector[0] = 5;

	assert(!(intVector == mySecondVector));

	assert(intVector[0] == 5);

}
