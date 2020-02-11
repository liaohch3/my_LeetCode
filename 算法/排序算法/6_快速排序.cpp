/*
* @Author: liaohch3
* @Date:   2020-02-11 20:44:55
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-11 21:16:58
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

int get_index(vector<int>& arr, int left, int right){
	int pivot = arr[left];
	while(left < right){
		while(left < right && arr[right] >= pivot) 
			right--;
		arr[left] = arr[right];

		while(left < right && arr[left] <= pivot) 
			left++;
		arr[right] = arr[left];
	}

	arr[left] = pivot;
	return left;
}

void quick_sort(vector<int>& arr, int left, int right){
	if(left < right){
		int index = get_index(arr, left, right);
		quick_sort(arr, left, index - 1);
		quick_sort(arr, index + 1, right);
	}
}

void sort(vector<int>& arr){
	if(arr.size() <= 1)	return;
	quick_sort(arr, 0, arr.size() - 1);
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