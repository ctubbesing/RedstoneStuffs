#include <iostream>
#include <vector>

using namespace std;

void printList(vector<int> &list)
{
    cout << "{ ";

    for (int i = 0; i < list.size() - 1; i++) {
        cout << list[i] << ", ";
    }

    cout << list.back() << " }";
}

vector<int> bubbleSort(vector<int> &list)
{
    int n = list.size();
    int swaps = 0;
    int loops = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - (i + 1); j++) {
            // swap if left bigger than right
            if (list[j] > list[j + 1]) {
                int swapVal = list[j];
                list[j] = list[j + 1];
                list[j + 1] = swapVal;

                swaps++;
            }

            loops++;
        }
    }

    cout << endl;
    cout << "Array is sorted in " << swaps << " swaps (" << loops << " loops)." << endl;
    cout << "First element: " << list.front() << endl;
    cout << "Last element: " << list.back() << endl << endl;

    return list;
}

int qCount;
int qSort_split(vector<int> &list, int start, int end)
{
    int pivot = list[end];
    int left = start;
    int right = end - 1;

    while (left <= right) {
        // locate pair to swap
        while (list[left] < pivot && left < end) {
            left++;
        }
        while (list[right] > pivot && right >= start) {
            right--;
        }

        // either swap pair or put pivot into position
        if (left < right) {
            int swapVal = list[left];
            list[left] = list[right];
            list[right] = swapVal;
        }
        else {
            list[end] = list[left];
            list[left] = pivot;
        }

        qCount++;
    }

    return left;
}

void qSort_sublist(vector<int> &list, int start, int end)
{
    // base case
    if (start >= end) {
        return;
    }

    // split list into sublists
    int pivotPos = qSort_split(list, start, end);

    // recursively sort sublists
    qSort_sublist(list, start, pivotPos - 1);
    qSort_sublist(list, pivotPos + 1, end);
}

void quickSort(vector<int> &list)
{
    qCount = 0;
    qSort_sublist(list, 0, list.size() - 1);
    cout << qCount << " swaps." << endl;
}

int b_qSort_split(vector<int> &list, int start, int end)
{
    int pivot = list[end];
    int left = start;
    int right = end - 1;

    while (left <= right) {
        // find a pair to swap
        while (list[left] < pivot && left < end) {
            left++;
        }
        while (list[right] > pivot && right >= start) {
            right--;
        }

        // swap pair or put pivot into position
        if (left < right) {
            int swapVal = list[left];
            list[left] = list[right];
            list[right] = swapVal;
        }
        else {
            list[end] = list[left];
            list[left] = pivot;
        }
    }

    return left;
}

void b_qSort_sublist(vector<int> &list, int start, int end)
{
    // base case
    if (start >= end) {
        return;
    }

    // split into sublists
    int pivotPos = b_qSort_split(list, start, end);

    // recursively sort sublists
    b_qSort_sublist(list, start, pivotPos - 1);
    b_qSort_sublist(list, pivotPos + 1, end);
}

void b_quickSort(vector<int> &list)
{
    b_qSort_sublist(list, 0, list.size() - 1);
}

void b_bubbleSort(vector<int> &list)
{
    int n = list.size();
    int swaps = 0;
    int loops = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - (i + 1); j++) {
            // swap if necessary
            if (list[j] > list[j + 1]) {
                int swapVal = list[j];
                list[j] = list[j + 1];
                list[j + 1] = swapVal;

                swaps++;
            }
            loops++;
        }
    }
    cout << swaps << " swaps, " << loops << " loops" << endl;
}

int main()
{
    // get list to sort
    vector<int> list;
    // list = { 3, 2, 1 };
    list = { 10, 3, 28, 44, 1, 2, 0, 100, 83, 27, 45 };
    cout << "Original list: ";
    printList(list);
    cout << endl;

    // sort list
    vector<int> sortedList = list;
    b_bubbleSort(sortedList);
    // quickSort(sortedList);

    // return sorted list
    cout << "Sorted list:   ";
    printList(sortedList);
    cout << endl;
    
    cout << endl;
}
