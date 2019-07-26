#pragma once
#include<queue>
using namespace std;
/*
	Data structure that supports O(logN) insertion
	And O(1) lookup for median element
*/
template <class T>
class MedianDataStructure {
private:
	/*
	A priority queue is a container adaptor that provides
	constant time lookup of the largest (by default) element,
	at the expense of logarithmic insertion and extraction.

	It is most oftenly implemented as binary heap. 
	*/
	priority_queue<T, vector<T>, greater<T>> minHeap;
	priority_queue<T> maxHeap;
	T median;
	int counter;
public:
	MedianDataStructure() {
		median = 0;
		counter = 0;
	}
	void add(T element) {
		if (maxHeap.size() > minHeap.size()) {
			if (element < median) {
				minHeap.push(maxHeap.top());
				maxHeap.pop();
				maxHeap.push(element);
			} 
			else {
				minHeap.push(element);
			}
			median = (maxHeap.top() + minHeap.top()) * 0.5;
		}
		else if (maxHeap.size() == minHeap.size()) {
			if (element < median) {
				maxHeap.push(element);
				median = maxHeap.top();
			}
			else {
				minHeap.push(element);
				median = minHeap.top();
			}
		}
		else {
			if (element > median) {
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(element);
			}
			else {
				maxHeap.push(element);
			}

			median = (maxHeap.top() + minHeap.top()) * 0.5;
		}
		counter++;
	}
	T getMedian() {
		return median;
	}
	int size() {
		return counter;
	}
};
