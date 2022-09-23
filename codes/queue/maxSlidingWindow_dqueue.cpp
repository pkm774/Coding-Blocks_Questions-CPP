#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        // Vector for storing answers.
        vector<int> ans;
        // dq for storing index.
        deque<int> dq;

        for (int i = 0; i < nums.size(); ++i)
        {
            while (!dq.empty() and -dq.front() >= k)
            {
                dq.pop_front();
            }

            while (!dq.empty() and nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};

// 
// k=3