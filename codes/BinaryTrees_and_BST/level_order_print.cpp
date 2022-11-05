#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data) {
		val = data;
		left = NULL;
		right = NULL;
	}
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        // Return NULL vector if root empty
        if (!root)
        {
            return {};
        }

        // Vector for storing answers.
        vector<vector<int>> ans;
        // Queue for holding level values
        queue<TreeNode *> q;

        q.push(root);
        int level = 1;

        while (!q.empty())
        {
            int sz = q.size();
            vector<int> curr_level;
            while (sz--)
            {
                TreeNode *node = q.front();
                q.pop();
                curr_level.push_back(node->val);
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }

            if (level % 2 != 0)
            {
                ans.push_back(curr_level);
            }
            else
            {
                reverse(curr_level.begin(), curr_level.end());
                ans.push_back(curr_level);
            }
            level += 1;
        }

        return ans;
    }
};

//
// k=3