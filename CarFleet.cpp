#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int carFleet(vector<int> position, vector<int> speed, int target){
    vector<double> monoStack;
    vector<pair<int, int>> newArray;
    for (auto i = position.begin(), j = speed.begin(); i < position.end(); i++, j++){
        newArray.push_back(pair<int, int>(*i, *j));
    }
    sort(newArray.begin(), newArray.end(), [](auto a, auto b)
         { return a.first < b.first; });
    for (auto itr = newArray.end() - 1; itr >= newArray.begin(); itr--)
    {
        double time = (double)(target - (*itr).first) / (double)(*itr).second;
        monoStack.push_back(time);
      
        if (monoStack.size() >= 2)
        {
            if(monoStack[monoStack.size() - 2] >= time)
                monoStack.pop_back();
        }
    }
    return monoStack.size();
}

int main(){
    vector<int> position{10, 8, 0, 5, 3};
    vector<int> speed{2, 4, 1, 1, 3};
    int target = 12;
    int answer = carFleet(position, speed, target);
    cout << answer;
}