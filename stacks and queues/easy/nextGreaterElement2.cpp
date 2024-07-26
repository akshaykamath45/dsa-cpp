// brute force - using the concept of circular array
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans;
        if (n == 1)
        {
            return {-1};
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j <= i + n - 1; j++)
            {
                int ind = j % n;
                if (arr[ind] > arr[i])
                {
                    ans.push_back(arr[ind]);
                    break;
                }
                else if (j == i + n - 1)
                {
                    ans.push_back(-1);
                    break;
                }
            }
        }
        return ans;
    }
};

// better - using stack , hypothetically doubling the array
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums2)
    {
        int n = nums2.size();
        vector<int> ans(nums2.size());
        stack<int> st;

        for (int i = 2 * nums2.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums2[i % n])
            {
                st.pop();
            }
            if (i < nums2.size())
            {
                if (st.empty())
                {
                    ans[i] = -1;
                }
                else
                {
                    ans[i] = st.top();
                }
            }

            st.push(nums2[i % n]);
        }
        return ans;
    }
};