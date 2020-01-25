#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {


        for(int i = 0; i < numbers.size() - 1; i++)
        {
            for(int j = i + 1; j < numbers.size(); j++)
            {
                if(numbers[i] + numbers[j] == target)
                {
                    vector<int> res;
                    res.push_back(i+1);
                    res.push_back(j+1);
                    return res;
                }
                else if(numbers[i] + numbers[j] > target)
                    break;
            }
        }

        vector<int> res;
        res.push_back(0);
        res.push_back(0);
        return res;
    }
};

int main()
{

    return 0;
}