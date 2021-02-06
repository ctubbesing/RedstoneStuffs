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
                int swap_val = list[j];
                list[j] = list[j + 1];
                list[j + 1] = swap_val;

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

void quickSort(vector<int> &list);

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
    bubbleSort(sortedList);
    // quickSort(sortedList);

    // return sorted list
    cout << "Sorted list:   ";
    printList(sortedList);
    cout << endl;
    
    cout << endl;
}
