#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int val, vector<int> &nums)
    {

        int l = 0;
        int r = nums.size() - 1;
        int idx = -1;
        while (l <= r)
        {

            int mid = (l + r) / 2;
            if (nums[mid] < val)
            {
                l = mid + 1;
                idx = mid;
            }
            else if (nums[mid] > val)
            {
                r = mid-1;
            }
            else
            {
                idx = mid;
                l = mid+1;
            }
        }
        return idx;
    }

public:
    int minOperations(vector<int> &nums, int target)
    {

        sort(nums.begin(), nums.end());
        int f_sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            f_sum += nums[i];
        }
        if(f_sum < target)
            return -1;

        vector<int> bits(32, 0);
        int msbit = 0;
        for (int i = 0; i <= 31; i++)
        {
            if ((1 << i) & target)
            {
                bits[i] = 1;
                msbit = i;
            
            }
        }

        int cnt = 0;
        for (int j = 0; j <= msbit; j++)
        {
            if (bits[j])
            {
                int sum = (1 << j);
                while (sum > 0)
                {

                    int idx = solve(sum, nums);
                    int k = idx;
                    // cout << "idx " << idx << " : ";
                    // for(int i = 0; i < nums.size(); i++){
                    //     cout << nums[i] << " ";
                    // }
                    int flag = 0;
                    int s = 0;
                    while(k >= 0 )
                    {
                        s += nums[k];
                        k--;
                        if(s == sum){
                            flag = 1;
                            break;
                        }
                    }
                    if(flag){
                        // cout << "found " << 1+k << ", " << idx << endl; 
                        nums.erase(nums.begin()+k+1, nums.begin()+idx+1);
                        break;
                    }
                    else
                    {
                        auto it = upper_bound(nums.begin(), nums.end(), sum);
                        int idx = (it - nums.begin());
                        int new_val = nums[idx];
                        // cout << "newval " << new_val << endl;
                        nums.erase(nums.begin() + idx);
                        nums.insert(nums.begin() + idx, 2, new_val / 2);
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
int main(){
    vector<int> nums{1, 128, 1, 128, 64};
    int sum = 4;
    Solution obj;
    cout << endl;
    cout <<  obj.minOperations(nums, sum) << " = res";
    return 0;
}