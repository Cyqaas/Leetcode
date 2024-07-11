using namespace std;
#include <iostream>
#include <vector>
#include <math.h>
#include <map>

int majorityElement(vector<int> &nums)
{
    int threshold = floor(nums.size() / 2);
    map<int, int> mp;
    pair<int, int> majority = make_pair(0, 0);

    // get the integer count of every element from the array
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }

    // then get the majority elemnent
    for (auto &it : mp)
    {
        if (it.second > majority.second)
        {
            majority = make_pair(it.first, it.second);
        }
    }

    return majority.first;
}

int main()
{
    vector<int> test = {3, 2, 3};
    int result = majorityElement(test);
    cout << result;
    return 0;
}