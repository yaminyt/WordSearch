#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class dictionary
{
public:
    void readWords(const string& filename);
    void selectionSort();
    void quickSort();
    void heapSort();

    int binarySearch(const string& target) const;
    int getMaxWordLength() const;
    int size() const;

    friend ostream& operator<<(ostream& out, const dictionary& d);

private:
    vector<string> words;
    int maxWordLen = 0;
};

#endif
