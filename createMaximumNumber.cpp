#include <vector>
#include <stack>
using namespace std;

vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
{
    stack<int> st;
    stack<int> st2;
    vector<int> vs(k, 0);
    for (int i = 0; i < nums1.size(); i++){
        while(!st.empty() && st.top() < nums1[i]){
            st.pop();
        }
        st.push(nums1[i]);
    }

    for (int i = 0; i < nums2.size(); i++)
    {
        while (!st2.empty() && st2.top() < nums2[i])
        {
            st2.pop();
        }
        st2.push(nums2[i]);
    }
    for (int i = 0; i < k;i++){

    }
}