/*
* @Author: liaohch3
* @Date:   2020-02-12 10:58:57
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-12 11:20:34
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

void heapify(vector<int>& arr, int n, int i){

	if(i >= n)	return;

	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int max = i;

	if(l < n && arr[l] > arr[max]){
		max = l;
	}
	if(r < n && arr[r] > arr[max]){
		max = r;
	}
	if(max != i){
		swap(arr[max], arr[i]);
		heapify(arr, n, max);
	}

}

void sort(vector<int>& arr){
	if(arr.size() <= 1)	return;

	int last_node = arr.size() - 1;
	int parent = (last_node - 1) / 2;
	for(int i = parent; i >= 0; i--){
		heapify(arr, arr.size(), i);
	}

	for(int i = arr.size() - 1; i >= 0; i--){
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
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