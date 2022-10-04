#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string kthLargestNumber(vector<string>& nums, int k) {
    partial_sort(nums.begin(), nums.end(),nums.begin() + k,[](const string& a, const string& b){
        if(a.size() < b.size()) return 0;
        else if(a.size() == b.size() && a < b) return 0;
        return 1;
    });
    return nums[k - 1];
}
