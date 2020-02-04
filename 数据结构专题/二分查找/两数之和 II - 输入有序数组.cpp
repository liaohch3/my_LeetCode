/*
* @Author: liaohch3
* @Date:   2020-02-04 22:15:35
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-04 22:33:38
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
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res(2, 0);

        int left = 0;
        int right = numbers.size() - 1;

        while(left < right){
            if(numbers[left] + numbers[right] == target){
                res[0] = left + 1;
                res[1] = right + 1;
                break;
            }
            else if(numbers[left] + numbers[right] < target)
                left++;
            else
                right--;
        }

        return res;
    }
};

int main()
{
    return 0;
}