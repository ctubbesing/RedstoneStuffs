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
    int loops = 0;
    int swaps = 0;

    cout << "swap  list" << endl;
    cout << "0     ";
    printList(list);
    cout << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - (i + 1); j++) {
            // swap adjacent elements if necessary
            if (list[j] > list[j + 1]) {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;

                swaps++;

                cout << swaps << "    " << (swaps > 9 ? "" : " ");
                printList(list);
                cout << endl;
            }

            loops++;
        }
    }

    cout << endl;
    cout << "Array is sorted in " << swaps << " swaps (" << loops << " loops)." << endl;
    cout << "First element: " << list.front() << endl;
    cout << "Last element: " << list.back() << endl;

    return list;
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
    vector<int> sortedList = bubbleSort(list);

    // return sorted list
    cout << "Sorted list:   ";
    printList(sortedList);
    cout << endl;
    
    cout << endl;
}