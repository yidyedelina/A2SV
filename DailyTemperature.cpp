#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> dailyTemperatures(vector<int> &temperatures)
{
    vector<int> v;
    v.resize(temperatures.size());
    stack<int> monoStack;
    for (int i = temperatures.size() - 1; i >= 0; i--){
        while ((!monoStack.empty()) && temperatures[monoStack.top()] <= temperatures[i])
        {
            monoStack.pop();
        }
        if (monoStack.empty())
        {
            v[i] = 0;
            monoStack.push(i);
        }
        else
        {
            v[i] = monoStack.top() - i;
            monoStack.push(i);
        }
    }
    return v;
}
int main(){
    vector<int> v{73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> i =dailyTemperatures(v);
    for (int j: i){
        cout << j << endl;
    }
}