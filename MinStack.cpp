#include <iostream>
#include <vector>
using namespace std;
class MinStack
{
public:
    vector<int> stack;
    int minIndex = 0;
    MinStack()
    {
    }

    void push(int val)
    {
        stack.push_back(val);
        if (val < stack[minIndex])
        {
            minIndex = stack.size() - 1;
        }
    }

    void pop()
    {
        if (minIndex == stack.size() - 1)
        {
            minIndex = 0;
            for (int i = 0; i < stack.size(); i++)
            {
                if (stack[i] < stack[minIndex])
                {
                    minIndex = i;
                }
            }
        }
        stack.pop_back();
    }

    int top()
    {
        stack.back();
    }

    int getMin()
    {
        return stack[minIndex];
    }
};