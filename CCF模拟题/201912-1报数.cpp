#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool check(int num){
	if(num % 7 == 0)
		return true;

	while(num){
		if(num % 10 == 7)
			return true;
		num /= 10;
	}
	return false;
}

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;

	int i = 1;
	int count = 0;

	int n;
	cin >> n; 

	while(count < n){
		if(check(i)){
			a++;
		}else{
			cout << "a: " << i << endl;
			count++;
			if(count == n)
				break;
		}
		i++;

		if(check(i)){
			b++;
		}else{
			cout << "b: " << i << endl;
			count++;
			if(count == n)
				break;
		}
		i++;

		if(check(i)){
			c++;
		}else{
			cout << "c: " << i << endl;
			count++;
			if(count == n)
				break;
		}
		i++;

		if(check(i)){
			d++;
		}else{
			cout << "d: " << i << endl;
			count++;
			if(count == n)
				break;
		}
		i++;

	}

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;

	return 0;
}
