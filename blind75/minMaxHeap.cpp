#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    int parent(int index) {
        return (index - 1) / 2;
    }

    int leftChild(int index) {
        return 2 * index + 1;
    }

    int rightChild(int index) {
        return 2 * index + 2;
    }

    void heapifyUp(int index) {
        while (index > 0 &&
            heap[index] > heap[parent(index)]) {

            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();

        while (true) {
            int largest = index;
            int left = leftChild(index);
            int right = rightChild(index);

            if (left < size && heap[left] > heap[largest]) {
                largest = left;
            }

            if (right < size && heap[right] > heap[largest]) {
                largest = right;
            }

            if (largest == index) {
                break;
            }

            swap(heap[index], heap[largest]);
            index = largest;
        }
    }

public:
    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }

        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty()) {
            heapifyDown(0);
        }
    }

    int top() const {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }

        return heap[0];
    }

    bool empty() const {
        return heap.empty();
    }

    int size() const {
        return heap.size();
    }

    void print() const {
        for (int value : heap) {
            cout << value << ' ';
        }
        cout << '\n';
    }
};

int main() {
    MaxHeap heap;

    heap.push(10);
    heap.push(30);
    heap.push(20);
    heap.push(5);
    heap.push(40);

    heap.print();        // Example: 40 30 20 5 10
    cout << heap.top();  // 40
    cout << '\n';

    heap.pop();

    heap.print();        // Example: 30 10 20 5

    return 0;
}