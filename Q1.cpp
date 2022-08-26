// Name : Divanshu Sharma
// Roll_No : 2010993535 || G-21
// Paper Set :  5
// Question: 1

#include <iostream>
#include <unordered_map>
using namespace std;

void findMaxLenSubarray(int nums[], int n, int S)
{

    unordered_map<int, int> map;

    map[0] = -1;

    int target = 0;

    int len = 0;

    int ending_index = -1;

    // traverse the given array
    for (int i = 0; i < n; i++)
    {
        // sum of elements so far
        target += nums[i];

        // if the sum is seen for the first time, insert the sum with its
        // into the map
        if (map.find(target) == map.end())
        {
            map[target] = i;
        }

        if (map.find(target - S) != map.end() && len < i - map[target - S])
        {
            len = i - map[target - S];
            ending_index = i;
        }
    }

    // print the subarray
    cout << "The largest subarray is ";
    cout << "{";
    for (int i = (ending_index - len + 1); i <= ending_index; i++)
    {
        cout << nums[i] << ",";
    }
    cout << "}";
    cout << " having length " << (ending_index - (ending_index - len + 1) + 1);
}

int main()
{
    int nums[100], n;
    cout << "Enter no of elements ";
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int target;
    cout << "Enter target ";
    cin >> target;

    findMaxLenSubarray(nums, n, target);

    return 0;
}
