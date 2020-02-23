/*
* @Author: liaohch3
* @Date:   2020-02-23 14:28:00
* @Last Modified by:   liaohch3
* @Last Modified time: 2020-02-23 15:36:15
*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <time.h>

using namespace std;

class Solution {
public:

    bool isNumber(string s) {

        // 不能为空且不能以E,e结尾
        if(s.empty() || s.back() == 'e' || s.back() == 'E'){
            return false;
        }

        // 拿到第一个非空字符下标
        int i = 0;
        while(i < s.size()){
            if(s[i] == ' '){
                i++;
            }else{
                break;
            }
        }

        // 全为空
        if(i == s.size()){
            return false;
        }

        // 对正负号的处理
        if(s[i] == '+' || s[i] == '-'){
            i++;
            // 只有一个正负号
            if(i == s.size()){
                return false;
            }
        }

        if(s[i] == '.'){
            if(i == s.size() - 1){
                return false;
            }else if(s[i+1] < '0' || s[i+1] > '9'){
                return false;
            }
        }

        // 开始正式的判断
        if(s[i] >= '0' && s[i] <= '9' || s[i] == '.'){
            bool point = false;
            while(i < s.size()){
                if(s[i] >= '0' && s[i] <= '9'){
                    i++;
                }else if(s[i] == '.'){
                    // 排除两个小数点的情况
                    if(point){
                        return false;
                    }else{
                        point = true;
                        i++;
                    }
                }else if(s[i] == 'E' || s[i] == 'e'){
                    i++;
                    break;
                }else if(s[i] == ' '){
                    while(i < s.size()){
                        if(s[i] == ' '){
                            i++;
                        }else{
                            return false;
                        }
                    }
                }else{
                    return false;
                }
            }

            // 对E后面是否为整数判断
            // 对正负号的处理
            if(s[i] == '+' || s[i] == '-'){
                i++;
                // 只有一个正负号
                if(i == s.size()){
                    return false;
                }
            }
            
            bool eAfterNumber = false;
            while(i < s.size()){
                if(s[i] >= '0' && s[i] <= '9'){
                    eAfterNumber = true;
                    i++;
                }else if(s[i] == ' '){
                    if(!eAfterNumber){
                        return false;
                    }
                    break;
                }else{
                    return false;
                }
            }

            if(s[i] == ' '){
                while(i < s.size()){
                    if(s[i] == ' '){
                        i++;
                    }else{
                        return false;
                    }
                }
            }

            return true;
        }else{
            return false;
        }
        
    }
};


int main()
{

	// cout << Solution().isNumber("0") << endl;
	// cout << Solution().isNumber(" 0.1 ") << endl;
	// cout << Solution().isNumber("abc") << endl;
	// cout << Solution().isNumber("1 a") << endl;
	// cout << Solution().isNumber("2e10") << endl;
	// cout << Solution().isNumber(" -90e3   ") << endl;
	// cout << Solution().isNumber(" 1e") << endl;
	// cout << Solution().isNumber("e3") << endl;
	// cout << Solution().isNumber(" 6e-1") << endl;
	// cout << Solution().isNumber(" 99e2.5 ") << endl;
	// cout << Solution().isNumber("53.5e93") << endl;
	// cout << Solution().isNumber(" --6 ") << endl;
	// cout << Solution().isNumber("-+3") << endl;
	// cout << Solution().isNumber("95a54e53") << endl;
	// cout << Solution().isNumber("     ") << endl;
	// cout << Solution().isNumber("14E") << endl;
 //    cout << Solution().isNumber("14.E4") << endl;
	// cout << Solution().isNumber("14E4.33") << endl;
 //    cout << Solution().isNumber(".1") << endl;
 //    cout << Solution().isNumber(".1E4") << endl;
 //    cout << Solution().isNumber(".") << endl;
 //    cout << Solution().isNumber(" .") << endl;
 //    cout << Solution().isNumber("12.") << endl;
 //    cout << Solution().isNumber("0E") << endl;
 //    cout << Solution().isNumber("0E ") << endl;

 //    cout << Solution().isNumber(".1") << endl;
 //    cout << Solution().isNumber("-.1") << endl;
 //    cout << Solution().isNumber("1.") << endl;
 //    cout << Solution().isNumber(" 005047e+6") << endl;
 //    cout << Solution().isNumber("46.e3") << endl;
 //    cout << Solution().isNumber(".2e81") << endl;
    
 //    cout << Solution().isNumber(".") << endl;
 //    cout << Solution().isNumber("+e") << endl;
    
    cout << Solution().isNumber(" -.") << endl;

 
    return 0;
}