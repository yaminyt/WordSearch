#include "heap.h"
#include <algorithm>

int heap::parent(int i)
{
    return (i - 1) / 2;
}

int heap::left(int i)
{
    return 2 * i + 1;
}

int heap::right(int i)
{
    return 2 * i + 2;
}

string heap::getItem(int i) const
{
    return data[i];
}

void heap::initializeMaxHeap(const vector<string>& v)
{
    data = v;
    heapSize = (int)data.size();
    buildMaxHeap();
}

void heap::maxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l < heapSize && data[l] > data[largest])
        largest = l;

    if (r < heapSize && data[r] > data[largest])
        largest = r;

    if (largest != i)
    {
        swap(data[i], data[largest]);
        maxHeapify(largest);
    }
}

void heap::buildMaxHeap()
{
    for (int i = heapSize / 2 - 1; i >= 0; i--)
        maxHeapify(i);
}

vector<string> heap::heapSort()
{
    vector<string> savedData = data;
    int savedSize = heapSize;

    for (int i = heapSize - 1; i >= 1; i--)
    {
        swap(data[0], data[i]);
        heapSize--;
        maxHeapify(0);
    }

    vector<string> result = data;
    data = savedData;
    heapSize = savedSize;

    return result;
}
