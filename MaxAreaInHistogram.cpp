#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int largestRectangleArea(vector<int> &heights)
{
    int maxArea = 0;
    stack<vector<int>> monoStack;
    for (int i = 0; i < heights.size(); i++)
    {
        while(!monoStack.empty() && monoStack.top()[1] > heights[i]){
            int h = monoStack.top()[1], j = monoStack.top()[0];
            monoStack.pop();
            int area = h * (monoStack.empty()? i: i - monoStack.top()[0] - 1);
            maxArea = max(maxArea, area);
        }
        vector b{i, heights[i]};
        monoStack.push(b);
    }
    int i = heights.size();
    while (!monoStack.empty())
    {
        int h = monoStack.top()[1], j = monoStack.top()[0];
        monoStack.pop();
        int area = h * (monoStack.empty() ? i : i - monoStack.top()[0] - 1);
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main(){
    vector b{2, 1, 2};
    int a = largestRectangleArea(b);
    cout << a;
}