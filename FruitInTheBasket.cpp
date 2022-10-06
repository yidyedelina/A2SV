#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int totalFruit(vector<int> &fruits)
{
    int maxLen = 0, curMax = 0;
    int left = 0, right = 0;
    int first = -1, second = -1;
    for (int i = 0; i < fruits.size(); i++){
        if(fruits[i] == first || fruits[i] == second){
            right++;
            curMax++;
            continue;
        }else if(first == -1){
            first = fruits[i];
            right++;
            curMax++;
            continue;
        }else if(second == -1){
            second = fruits[i];
            right++;
            curMax++;
            continue;
        }  
        maxLen = maxLen > curMax ? maxLen : curMax;
        int tmp = first;
        while(fruits[left] == tmp){
            left++;
        }
        first = second;
        second = fruits[i];
        curMax = right - left + 1;
        left++, right++;
    }
    return maxLen;
}
int main(){
    vector<int> b{1, 2, 1};
    int a = totalFruit(b);
    cout << a;
    return 0;
}