/*
* @Author: liaohch3
* @Date:   2020-02-04 21:07:34
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-04 21:21:11
*/
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i = 0;
        int j = letters.size() - 1;
        int mid;
        int index = 0;
        while(i <= j){
        	mid = i + (j - i) / 2;
        	if(letters[mid] > target){
        		index = mid;
        		j = mid - 1;
        	}
        	else
        		i = mid + 1;
        }
        return letters[index];
    }
};

int main()
{

	vector<char> letters = {'c', 'f', 'j'};
	char target = 'a';
	cout << Solution().nextGreatestLetter(letters, target) << endl;

	letters = {'c', 'f', 'j'};
	target = 'c';
	cout << Solution().nextGreatestLetter(letters, target) << endl;

	letters = {'c', 'f', 'j'};
	target = 'd';
	cout << Solution().nextGreatestLetter(letters, target) << endl;

	letters = {'c', 'f', 'j'};
	target = 'g';
	cout << Solution().nextGreatestLetter(letters, target) << endl;

	letters = {'c', 'f', 'j'};
	target = 'j';
	cout << Solution().nextGreatestLetter(letters, target) << endl;

	letters = {'c', 'f', 'j'};
	target = 'k';
	cout << Solution().nextGreatestLetter(letters, target) << endl;

	return 0;
}