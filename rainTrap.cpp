#include <vector>
#include <stack>
#include <iostream>
using namespace std;
int trap(vector<int> &height)
{
    int area = 0;
    stack<int> st;

    for (int i = 0; i < height.size(); i++)
    {
        while (!st.empty() && height[st.top()] < height[i])
        {
            int pop_height = height[st.top()];
            st.pop();

            // If the stack does not have any
            // bars or the popped bar
            // has no left boundary
            if (st.empty())
                break;

            // Get the distance between the
            // left and right boundary of
            // popped bar
            int distance = i - st.top() - 1;

            // Calculate the min. height
            int min_height = min(height[st.top()], height[i]) - pop_height;

            area += distance * min_height;
        }
        st.push(i);
    }
    return area;
}

int main(){
    vector<int> b{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int a = trap(b);
    cout << a;
}