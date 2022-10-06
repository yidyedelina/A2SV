#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int numRescueBoats(vector<int> &people, int limit)
{
    int count = 0;
    sort(people.begin(), people.end());
    int left = 0, right = people.size() - 1;
    while (left <= right)
    {
        if (people[left] + people[right] <= limit)
        {
            count++;
            left++;
            right--;
        }
        else
        {
            count++;
            right--;
        }
    }
    return count;
}
int main(){
    vector<int> b{3, 2, 2, 1};
    int a = numRescueBoats(b, 3);
    cout << a;
}