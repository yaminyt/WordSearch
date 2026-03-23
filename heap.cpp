#include "dictionary.h"
#include "heap.h"
#include "d_except.h"
#include <fstream>

void dictionary::readWords(const string& filename)
{
    ifstream fin(filename.c_str());

    if (!fin)
        throw fileOpenError(filename);

    words.clear();
    maxWordLen = 0;

    string w;

    while (fin >> w)
    {
        words.push_back(w);

        if ((int)w.length() > maxWordLen)
            maxWordLen = (int)w.length();
    }
}

void dictionary::selectionSort()
{
    for (int i = 0; i < (int)words.size() - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < (int)words.size(); j++)
        {
            if (words[j] < words[minIndex])
                minIndex = j;
        }

        if (minIndex != i)
        {
            string temp = words[i];
            words[i] = words[minIndex];
            words[minIndex] = temp;
        }
    }
}

int partitionWords(vector<string>& arr, int low, int high)
{
    string pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (true)
    {
        while (i <= high && arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i >= j)
            break;

        swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}

void quickSortHelper(vector<string>& arr, int low, int high)
{
    if (low < high)
    {
        int p = partitionWords(arr, low, high);
        quickSortHelper(arr, low, p - 1);
        quickSortHelper(arr, p + 1, high);
    }
}

void dictionary::quickSort()
{
    if (!words.empty())
        quickSortHelper(words, 0, (int)words.size() - 1);
}

void dictionary::heapSort()
{
    heap h;
    h.initializeMaxHeap(words);
    words = h.heapSort();
}

int dictionary::binarySearch(const string& target) const
{
    int first = 0;
    int last = (int)words.size() - 1;

    while (first <= last)
    {
        int mid = (first + last) / 2;

        if (words[mid] == target)
            return mid;
        else if (words[mid] < target)
            first = mid + 1;
        else
            last = mid - 1;
    }

    return -1;
}

int dictionary::getMaxWordLength() const
{
    return maxWordLen;
}

int dictionary::size() const
{
    return (int)words.size();
}

ostream& operator<<(ostream& out, const dictionary& d)
{
    for (int i = 0; i < (int)d.words.size(); i++)
        out << d.words[i] << endl;

    return out;
}
