#include <iostream>
#include <vector>
using namespace std;
/**
 * @brief return number of pair identical number can make on condition i < j
 * 
 * @param nums 
 * @return int 
 */
int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size();j++){
                if(nums[i] == nums[j]){
                    count++;
                }
            }
        }
        return count;
    }
