#include <iostream>
#include <random>
#include <iterator>

using namespace std;


void invert(int *arr, int size);
void rise(int *arr, int size);
void down(int *arr, int size);

int main() {
    int size = 20;
    int arr[size], first, sum = 0;
    void (*operation[])(int *arr, int size) = {invert, rise, down};
    //random
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, 1000);

    for(int i = 0; i < size; i++){
        arr[i] = dist(mt);
        cout << arr[i] << " ";
    }
    first = arr[0];
    for (int i = 1;i < size; i++){
        sum += arr[i];
    }
    cout << "sum is: " << sum << endl;
    if(first == sum){
        operation[0](arr, size);
    } else if (first < sum) {
        operation[1](arr, size);
    } else {
        operation[2](arr, size);
    }

    return 0;
}

void invert(int *arr, int size) {
    int j = size;
    for (int i = 0; i < j; i++, j--) {
        int tmp = arr[i];
        arr[i] = arr[j-i-1];
        arr[j-i-1] = tmp;
    }
    cout << "invert arr is: ";
    for (int i = 0; i < 20; i++) {
        cout << arr[i] << " ";
    }
}

void rise(int *arr, int size) {
    int temp;
    for (int k = 0; k < size - 1; k++) {
        for (int j = 0; j < size - k - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "rised array is: ";
    for (int k = 0; k < size; k++) {
        cout << arr[k] << " ";
    }
}

void down(int *arr, int size) {
    for(int i = 0;i < size;i++) {
        if (arr[i] < arr[i+1]) {
            int tmp = arr[i+1];
            arr[i+1]=arr[i];
            arr[i]=tmp;
        }
    }
    cout << "Down arr: ";
    for(int i = 0;i < size;i++){
        cout << arr[i] << " ";
    }
}