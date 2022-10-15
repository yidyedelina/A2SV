#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int findUnsortedSubarray(vector<int> &nums)
{
    int n = nums.size() - 1;
    int start = n, end = 0;
    stack<int> st;
    stack<int> st2;
    for (int i = 0; i < nums.size(); i++)
    {
        while(!st.empty() && nums[st.top()] > nums[i]){
            start = min(start, st.top());
            st.pop();
        }
        st.push(i);
    }
    for (int i = n; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] > nums[i])
        {
            end = max(end, st.top());
            st.pop();
        }
        st.push(i);
    }
    if (end <= start)
        return 0;
    return (end - start);
}

int main(){
    vector b{2, 6, 4, 8, 10, 9, 15};
    int a = findUnsortedSubarray(b);
    cout << a;
}