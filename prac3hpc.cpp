#include <iostream>
#include <omp.h>
using namespace std;

// Minimum
int minval(int arr[], int n){
    int minval = arr[0];
    #pragma omp parallel for reduction(min : minval)
    for(int i = 0; i < n; i++){
        if(arr[i] < minval) minval = arr[i];
    }
    return minval;
}

// Maximum
int maxval(int arr[], int n){
    int maxval = arr[0];
    #pragma omp parallel for reduction(max : maxval)
    for(int i = 0; i < n; i++){
        if(arr[i] > maxval) maxval = arr[i];
    }
    return maxval;
}

// Sum
int sum(int arr[], int n){
    int sum = 0;
    #pragma omp parallel for reduction(+ : sum)
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}

// Average
double average(int arr[], int n){
    return (double)sum(arr, n) / n;
}

int main(){
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];   // dynamic array (works in GCC)

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Minimum value: " << minval(arr, n) << '\n';
    cout << "Maximum value: " << maxval(arr, n) << '\n';
    cout << "Sum: " << sum(arr, n) << '\n';
    cout << "Average: " << average(arr, n) << '\n';

    return 0;
}

/* sudo apt update
sudo apt install g++ */

// g++ -fopenmp file_name.cpp -o program
// ./program
