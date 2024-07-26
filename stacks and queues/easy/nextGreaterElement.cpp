// brute force - using 3 loops
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums2[j] == nums1[i])
                {
                    for (int k = j; k < nums2.size(); k++)
                    {
                        if (nums2[k] > nums2[j])
                        {
                            ans.push_back(nums2[k]);
                            break;
                        }
                        else if (k == nums2.size() - 1)
                        {
                            ans.push_back(-1);
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

// better - using stack
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mpp;
        stack<int> st;
        vector<int> ans(nums1.size());

        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums2[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                mpp[nums2[i]] = -1;
            }
            else
            {
                mpp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i++)
        {
            ans[i] = mpp[nums1[i]];
        }
        return ans;
    }
};