//
// Created by xxy on 2022/2/24.
//

#ifndef IDE_SOLUTIONDS_H
#define IDE_SOLUTIONDS_H
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class SolutionDS {
public:
    /**
     * 217: contains duplicate
     * @param nums
     * @return
     */
    bool containsDuplicate(vector<int>& nums) {
        /**
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = 0, j = 1; i < len && j < len; i++, j++) {
            if (nums[i] == nums[j]) return true;
        }
        return false; */
        unordered_set<int> s;
        for (int i : nums) {
            if (s.find(i) != s.end()) return true;
            s.insert(i);
        }
        return false;
    }
    /**
     * 53: maximum-subarray
     * @param nums
     * @return
     */
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], pre = 0;
        for (int i : nums) {
            pre = max(pre + i, i);
            maxSum = max(pre, maxSum);
        }
        return maxSum;
    }
    /**
     struct Status {
        int lSum, rSum, mSum, iSum;
    };

    Status pushUp(Status l, Status r) {
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return (Status) {lSum, rSum, mSum, iSum};
    };

    Status get(vector<int> &a, int l, int r) {
        if (l == r) {
            return (Status) {a[l], a[l], a[l], a[l]};
        }
        int m = (l + r) >> 1;
        Status lSub = get(a, l, m);
        Status rSub = get(a, m + 1, r);
        return pushUp(lSub, rSub);
    }

    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }

     */

};
#endif //IDE_SOLUTIONDS_H
