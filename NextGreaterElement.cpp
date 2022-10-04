#include <iostream>
#include <vector>
#include <stack>

using namespace std;
//next greater element

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    int v[nums2.size()];
    stack<int> monoStack;
    for (int i = nums2.size() - 1; i >=0; i--){
        
        while((!monoStack.empty()) && monoStack.top() < nums2[i]){
            monoStack.pop();
        }
        if(monoStack.empty()){
            v[i] = -1;
            monoStack.push(nums2[i]);
        }else{
            int a = monoStack.top();
            v[i] = a;
            monoStack.push(nums2[i]);
        }
    }
    vector<int> nextGreater;
    nextGreater.reserve(nums1.size() * (sizeof(int)));
    for (int j = 0; j < nums1.size(); j++)
    {
        for (int k = 0; k < nums2.size(); k++){
            if(nums1[j] == nums2[k]){
                nextGreater.push_back(v[k]);
                break;
            }
        }
    }
        return nextGreater;
}
//next greater integer
//next integer



int main(){
    vector<int> s{4, 1, 2};
    vector<int> s2{1, 3, 4, 2};
    vector<int> print = nextGreaterElement(s, s2);
    for(int i: print){
        cout << i << endl;
    }
}