/*
* @Author: liaohch3
* @Date:   2020-02-11 19:55:14
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-11 20:36:10
*/

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <time.h>

using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void show(vector<int>& arr){
    for(int item: arr){
        cout << item << " ";
    }
    cout << endl;
}

bool check(vector<int>& arr){

    if(arr.size() <= 1)
        return true;

    for(int i = 0; i < arr.size() - 1; i++){
        if(arr[i] > arr[i+1]){
            return false;
        }
    }

    return true;
}

void merge(vector<int>& arr, int l, int m, int r){
    int i = l;
    int j = m;
    vector<int> res(r - l);
    int k = 0;
    while(i < m && j < r){
        if(arr[i] < arr[j]){
            res[k] = arr[i];
            i++;
        }else{
            res[k] = arr[j];
            j++;
        }
        k++;
    }

    while(i < m){
        res[k] = arr[i];
        i++;
        k++;
    }

    while(j < r){
        res[k] = arr[j];
        j++;
        k++;
    }

    for(int p = l; p < r; p++){
        arr[p] = res[p - l];
    }
}

void merge_sort(vector<int>& arr, int l, int r){
    if(r - l <= 1) return;

    int mid = l + (r - l) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid, r);
    merge(arr, l, mid, r);
}

void sort(vector<int>& arr){
    if(arr.size() <= 1) return;
    merge_sort(arr, 0, arr.size());
}

int main()
{
    int N = 0;
    srand((unsigned)time(NULL));
    vector<int> arr(N);
    for(int i = 0; i < N; i++)
        arr[i] = rand() % (5*(N+10));
    sort(arr);
    printf("N: %d success: %d\n", N, check(arr));

    N = 1;
    arr.resize(N);
    for(int i = 0; i < N; i++)
        arr[i] = rand() % (5*(N+10));
    sort(arr);
    printf("N: %d success: %d\n", N, check(arr));

    N = 10;
    arr.resize(N);
    for(int i = 0; i < N; i++)
        arr[i] = rand() % (5*(N+10));
    sort(arr);
    printf("N: %d success: %d\n", N, check(arr));

    N = 100;
    arr.resize(N);
    for(int i = 0; i < N; i++)
        arr[i] = rand() % (5*(N+10));
    sort(arr);
    printf("N: %d success: %d\n", N, check(arr));

    for(int i = 0; i < 5; i++){
        N = rand() % 10000;
        arr.resize(N);
        for(int i = 0; i < N; i++)
            arr[i] = rand() % (5*(N+10));
        sort(arr);
        printf("N: %d success: %d\n", N, check(arr));  
    }

    return 0;
}