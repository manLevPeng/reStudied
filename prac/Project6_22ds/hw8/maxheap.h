#include<iostream>  
using namespace std; 

template<class T>
void ChangeSize1D(T*&a, const int oldSize, const int newSize);

template<class T>
class MaxHeap{
public:
	MaxHeap(int); //constructor
	void Push(const T& e);
	void Pop();
	bool IsEmpty() { return heapSize == 0; }
	T Top() {
		if (IsEmpty()) 
			throw "You can't call Top() for an empty Heap.";
		return heap[1];
	}
private:
	int heapSize;	//#elements in heap
	int capacity;	//size of thearay heap 
	T *heap;		//element array
template<class T2>
friend ostream&operator<<(ostream&, MaxHeap<T2>&);
};

template<class T>
void ChangeSize1D(T *&a, const int oldSize, const int newSize) 
{/*교재내에있음*/ }
template<class T>
ostream& operator<<(ostream& os, MaxHeap<T>& H) {
	os << "<Heap Contents>	";
	for (int i = 1; i <= H.heapSize; i++)
		os << i << ":" << H.heap[i] << " ";
	os << endl;
}
template<class T>
MaxHeap<T>::MaxHeap(int theCapacity = 10) : heapSize(0) {
	if (theCapacity < 1)	throw "Must be + ve";
	capacity = theCapacity;
	heap = new T[capacity + 1]; // heap[0]는사용안함
}  
template<class T>
// heap[0]는 사용 안하므로 Push에서 ChangeSize1의 호출을
// ChangeSize1D(heap, capacity + 1, 2 * capacity + 1); 로 바꾸시오 
void MaxHeap<T>::Push(const T& e) {
	if (heapSize == capacity) {
		ChangeSize1D(heap, capacity + 1, 2 * capacity + 1);
		capacity *= 2;
	}
	int currentNode = ++heapSize;
	while (currentNode != 1 && heap[currentNode / 2] < e) {
		heap[currentNode] = heap[currentNode / 2]; //move parent down
		currentNode /= 2;
	}
	heap[currentNode] = e;
}

template<class T>
void MaxHeap<T>::Pop() {
	if (IsEmpty()) throw "heap is empty. Cannot delete.";
	heap[1].~T();
	T lastE = heap[heapSize--];

	int currentNode = 1;
	int child = 2;
	while (child <= heapSize) {
		if (child < heapSize&&heap[child] < heap[child + 1])child++;
		if (lastE >= heap[child])break;

		heap[currentNode] = heap[child];
		currentNode = child;	child *= 2;
	}
	heap[currentNode] = lastE;
}