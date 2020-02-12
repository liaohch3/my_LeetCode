/*
* @Author: liaohch3
* @Date:   2020-02-12 11:41:39
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-12 12:36:55
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

	int max = 1;

	for(int i = 0; i < arr.size(); i++){
		int now = arr[i];
		int round = 0;
		while(now){
			now /= 10;
			round++;
		}

		max = round > max ? round : max;
	}

	vector<vector<int> > bucket(10); 

	for(int i = 0; i < max; i++){
		int mod = 1;
		for(int j = 0; j < i; j++){
			mod *= 10;
		}

		for(int j = 0; j < arr.size(); j++){
			bucket[(arr[j] / mod) % 10].push_back(arr[j]);
		}
		int k = 0;
		for(int j = 0; j < 10; j++){
			for(int m = 0; m < bucket[j].size(); m++){
				arr[k] = bucket[j][m];
				k++;
			}
			bucket[j].clear();
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