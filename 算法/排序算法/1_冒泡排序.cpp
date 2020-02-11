/*
* @Author: liaohch3
* @Date:   2020-02-11 15:48:08
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-11 20:35:47
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

void sort(vector<int>& arr){
	
	if(arr.size() <= 1)	return;

	for(int i = 0; i < arr.size(); i++){
		for(int j = 0; j < arr.size() - 1 - i; j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
			}
		}
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