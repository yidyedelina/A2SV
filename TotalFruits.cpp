#include <vector>
#include <iostream>
using namespace std;
int totalFruit(vector<int> &fruits)
{
    int maxW = 0;
    int left = 0, right = 0;
    vector<int> b1;
    vector<int> b2;
    while (right < fruits.size())
    {
        
        if (!b1.empty() && b1[0] == fruits[right])
            b1.push_back(fruits[right]);
        else if (!b2.empty() && b2[0] == fruits[right])
            b2.push_back(fruits[right]);
        else if (b2.empty())
            b2.push_back(fruits[right]);
        else if (b1.empty())
            b1.push_back(fruits[right]);
        else {
            int width = (b1.size() + b2.size());
            maxW = max(maxW, width);
            while(!b1.empty() && !b2.empty()){
                if(b1[0] == fruits[left]){
                    b1.pop_back();
                }else
                    b2.pop_back();
                left++;
            }
            b1.empty() ? b1.push_back(fruits[right]) : b2.push_back(fruits[right]);
        }
        right++;
    }
    int s = (b1.size() + b2.size());
    int r = max(maxW, s);
    return r;
}
int main(){
    vector<int> fruits{0, 1, 2, 2};
    int n = totalFruit(fruits);
    cout << n;
}