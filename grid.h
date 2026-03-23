#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <string>

using namespace std;

class heap
{
public:
    void initializeMaxHeap(const vector<string>& v);
    void maxHeapify(int i);
    void buildMaxHeap();
    vector<string> heapSort();

    int parent(int i);
    int left(int i);
    int right(int i);
    string getItem(int i) const;

private:
    vector<string> data;
    int heapSize;
};

#endif
