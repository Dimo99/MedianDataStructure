#include<iostream>
#include "MedianDataStructure.h"
#include<fstream>
#include <chrono>
#include<cstdlib>
using namespace std;


// Performence testing
int main() {
	MedianDataStructure<double> medianDataStructure;

	auto start = chrono::high_resolution_clock::now();
	// Insert 1_000_000 elements
	for (int i = 0; i < 1000000; i++) {
		medianDataStructure.add(i);
	}
	auto finish = chrono::high_resolution_clock::now();
	auto microseconds = chrono::duration_cast<std::chrono::microseconds>(finish - start);
	cout << microseconds.count() << endl;

	start = chrono::high_resolution_clock::now();
	// Insert 1_000_000 on top of that and getMedian on every insertion
	for (int i = 0; i < 1000000; i++) {
		medianDataStructure.add(i);
		medianDataStructure.getMedian();
	}
	finish = chrono::high_resolution_clock::now();
	microseconds = chrono::duration_cast<std::chrono::microseconds>(finish - start);
	cout << microseconds.count() << endl;

	system("pause");
	return 0;
}