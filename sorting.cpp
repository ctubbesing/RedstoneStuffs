#include <iostream>
#include <vector>

using namespace std;

bool doOut = true;

void printList(vector<int> &list, int start = -1, int end = -1)
{
    cout << "{ ";

    for (int i = 0; i < list.size() - 1; i++) {
        if ((i >= start && i <= end) || start == -1) {
            cout << list[i] << ", ";
        }
    }

    cout << list.back() << " }";
}

void bubbleSort(vector<int> &list)
{
    int n = list.size();
    int loops = 0;
    int swaps = 0;

    if (doOut) cout << "swap  list" << endl;
    if (doOut) cout << "0     ";
    if (doOut) printList(list);
    if (doOut) cout << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - (i + 1); j++) {
            // swap adjacent elements if necessary
            if (list[j] > list[j + 1]) {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;

                if (doOut) swaps++;

                if (doOut) cout << swaps << "    " << (swaps > 9 ? "" : " ");
                if (doOut) printList(list);
                if (doOut) cout << endl;
            }

            if (doOut) loops++;
        }
    }

    if (doOut) cout << endl;
    if (doOut) cout << "Array is sorted in " << swaps << " swaps (" << loops << " loops)." << endl;
    if (doOut) cout << "First element: " << list.front() << endl;
    if (doOut) cout << "Last element: " << list.back() << endl;
}

int qSortSwaps, qSortLoops, qSortLevel;
int qSort_split(vector<int> &list, int start, int end)
{
    int pivot = list[end];
    int left = start;
    int right = end - 1;

    while (left <= right) {
        // move pointers until a pair to swap is found
        while (list[left] < pivot && left < end) {
            left++;
        }
        while (list[right] > pivot && right >= start) {
            right--;
        }

        // either swap pair or place pivot into position if done
        if (left < right) {
            int swap_val = list[left];
            list[left] = list[right];
            list[right] = swap_val;
        }
        else {
            list[end] = list[left];
            list[left] = pivot;
        }
        if (doOut) qSortSwaps++;
    }

    return left;
}

void qSort_sublist(vector<int> &list, int start, int end)
{
    if (doOut) {
        qSortLevel++;

        for (int i = 0; i < qSortLevel; i++) {
            cout << "--";
        }
        cout << " Sorting sublist: ";
        printList(list, start, end);
        cout << endl;
    }

    // base case: list is 0 or 1 elements long
    if (start >= end) {
        if (doOut) qSortLevel--;
        return;
    }

    // divide into 2 sublists
    int pivotPos = qSort_split(list, start, end);

    // sort each sublist
    qSort_sublist(list, start, pivotPos - 1);
    qSort_sublist(list, pivotPos + 1, end);
}

void quickSort(vector<int> &list)
{
    if (doOut) qSortSwaps = 0;
    if (doOut) qSortLoops = 0;
    // sort with initial sublist containing the entire list
    qSort_sublist(list, 0, list.size() - 1);

    if (doOut) cout << "Array is sorted in " << qSortSwaps << " swaps." << endl;
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
    // bubbleSort(sortedList);
    quickSort(sortedList);

    // return sorted list
    cout << "Sorted list:   ";
    printList(sortedList);
    cout << endl;
    
    cout << endl;
}