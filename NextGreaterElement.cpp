#include <iostream>
#include <vector>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> v;
    for (int i = 0; i < nums1.size(); i++){
        int key = nums1[i];
        int found = 0;
        for (int j = 0; j < nums2.size(); j++)
        {
            if(nums2[j] == key){
                for (int k = j + 1; j < nums2.size(); j++){
                    if(nums2[k] > key){
                        v.push_back(nums2[k]);
                        found = 1;
                        break;
                    }
                }
                break;
            }
        }
        if(found == 0)
            v.push_back(-1);
    }
        return v;
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