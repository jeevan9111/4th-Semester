//
// Created by jeevan on 9/5/17.
//

#include "iostream"

using namespace std;

void BubbleSort(int *data, int n) {
    bool done = false;
    for (int pass = 0; pass < n-1 && !done; pass++) {
        done = true;
        for (int i = 0; i < n - pass - 1; i++) {
            if (data[i] > data[i + 1]) {
                int temp = data[i + 1];
                data[i + 1] = data[i];
                data[i] = temp;
                done = false;
            }
        }
    }
    cout << endl << "After Bubble Sort" << endl;
    for (int i = 0; i < n; i++)
        cout << data[i] << endl;
}


void Merge(int *data, int start, int mid, int end) {
    int duplicateData[end - start + 1];

    for (int i = start; i <= end; i++)
        duplicateData[i - start] = data[i];

    int i = start, j = mid + 1, k = start;

    for (; i <= mid && j <= end; k++) {
        if (data[i] <= data[j]) {
            data[k] = duplicateData[i - start];
            i++;
        } else {
            data[k] = duplicateData[j - start];
            j++;
        }
    }

    for (; i <= mid; i++, k++)
        data[k] = duplicateData[i - start];

    for (; j <= end; j++, k++)
        data[k] = duplicateData[j - start];
}


void mergeSort(int *data, int start, int end) {
    if (start < end) {
        int mid = (end + start) / 2;
        mergeSort(data, start, mid);
        mergeSort(data, mid + 1, end);
        Merge(data, start, mid, end);
    }
}

void MergeSort(int *data, int n) {
    mergeSort(data, 0, n - 1);
    cout << endl << "After Merge Sort" << endl;
    for (int i = 0; i < n; i++)
        cout << data[i] << endl;
}


void InsertionSort(int *data, int n) {
    for (int i = 1; i < n; i++) {
        int k = i;
        for (int j = i - 1; j >= 0; j--) {
            if (data[k] < data[j]) {
                int temp = data[k];
                data[k] = data[j];
                data[j] = temp;
                k = j;
            }
        }
    }

    cout << endl << "After Insertion Sort" << endl;
    for (int i = 0; i < n; i++)
        cout << data[i] << endl;
}

void SelectionSort(int *data, int n) {

    for (int i = 0; i < n; i++) {
        int min = data[i];
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (data[j] < min) {
                min = data[j];
                k = j;
            }
        }
        if (k != i) {
            data[k] = data[i];
            data[i] = min;
        }
    }

    cout << endl << "After Selection Sort" << endl;
    for (int i = 0; i < n; i++)
        cout << data[i] << endl;
}

int PartitionforQuickSort(int *data, int start, int end) {
    int pivot = data[end];
    int pivotIndex = start;
    for (int i = start; i < end - 1; i++) {
        if (data[i] < pivot) {
            data[i] = data[pivotIndex];
            data[pivotIndex++] = data[i];
        }
    }
    data[end] = data[pivotIndex];
    data[pivotIndex] = pivot;
    return pivotIndex;
}

void QuickSort(int *data, int start, int end) {
    if (start < end) {
        int partitionIndex = PartitionforQuickSort(data, start, end);
        QuickSort(data, start, partitionIndex - 1);
        QuickSort(data, partitionIndex + 1, end);
    }
}

void QuickSort(int *data, int n) {
    QuickSort(data, 0, n - 1);
    cout << endl << "After Quick Sort" << endl;
    for (int i = 0; i < n; i++)
        cout << data[i] << endl;
}


int main() {
    int n;
    int *data;
    cout << "Enter number of Data \t: ";
    cin >> n;
    data = new int[n];
    cout << "Enter the Data" << endl;
    for (int i = 0; i < n; i++)
        cin >> data[i];

    BubbleSort(data, n);

    delete data;
    return 0;
}