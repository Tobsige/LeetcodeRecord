#include <vector>
#include <algorithm>
using namespace std;
/**
 *
 * first version --recursion
 * /
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto len = nums.size();
        decltype(len) len2 = len / 2;
        
        if (len == 1) {
            if (target == nums[0]) { return 0;}
            return -1;
        }
        else if (len == 2) {
            if (target == nums[0]) { return 0;}
            else if(target == nums[1]) { return 1;}
            return -1;
        }
        if (nums[len2] == target) {
            return len2;
        }

        if (nums[len2] < target && nums[len - 1] > target) {
            auto first = nums.begin() + len2;
            auto second = nums.end();
            vector<int>num2(first, second);
            int itv = search(num2, target);
            if (itv == -1) {
                return -1;
            }
            return (int) len2 + itv;
        }
        else if (nums[len2] > target && nums[0] < target) {
            auto first = nums.begin();
            auto second = nums.begin() + len2;
            vector<int>num2(first, second);
            return search(num2, target);
        } else if (target == nums[0]) {
            return 0;
        } else if (target == nums[len - 1]) {
            return (int) len - 1;
        }
        return -1;
    }
};
class Solution {
public:
    int search(vector<int> nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (high - low) / 2 + low;
            int num = nums[mid];
            if (num == target) {
                return mid;
            } else if (num > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};*/

/**
 * long time but small storage, open section
*/
class Solution {
public:
    //704
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        if (target > nums[high] || target < nums[0]) { return -1; }
        if (high == 0 || high == 1) {
            for (int i = 0; i <= high; i++) {
                if (nums[i] == target) {
                    return i;
                }
            }
            return -1;
        }

        while (low < high) {
            int mid = (high + low) / 2;
            int num = nums[mid], right = nums[high], left = nums[low];
            if (num == target) {
                return mid;
            } else if(left == target) {
                return low;
            } else if(right == target) {
                return high;
            }  else if (num > target) {
                high = mid - 1;
            } else if (num < target) {
                low = mid + 1;
            }
        }
        return -1;
    }
    /**
    * 278： first bad version. bool isBadVersion(int version); bad >= 1;
    */
    bool isBadVersion(int version) { return true; }
    int firstBadVersion(int n) {
        int low = 1, high = n;
        if (high == low) {
            return 1;
        }
        while (high - low > 1) {
            int mid = (high - low) / 2 + low; // (high + low) / 2 would overflow
            if (isBadVersion(mid)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if (isBadVersion(high) ^ isBadVersion(low)) {
            return high;
        } else {
            return low;
        }
    }
    /**
     * 35, length >= 1, 10^4 timeCost->O(logN)
     * @param nums
     * @param target
     * @return index or index where should be inserted
     */
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        if (target <= nums[0]) {
            return 0;
        }
        if (target > nums[high]) {
            return high + 1;
        } // not >=

        while (high - low > 1) {
            int mid = (high - low) / 2 + low;
            int num = nums[mid];
            if (num == target) {
                return mid;
            } else if (num > target) {
                high = mid;
            } else {
                low = mid;
            }
        }
        if (target <= nums[low]) {
            return low;
        } else {
            return high;
        }
    }
    /**
     * 977
     * @param nums for >= order
     * @return square vector for >= order
     * */
    vector<int> sortedSquares(vector<int>& nums) {
        /** sort O(n + nLogn), O(nlogn)
        for(auto i = nums.begin(); i != nums.end(); i++) {
            *i = (*i) * (*i);
        }
        sort(nums.begin(), nums.end());
        return nums; */
        int left = 0, right = nums.size() - 1, len = right;
        vector<int> rst;
        int l = nums[left] * nums[left];
        int r = nums[right] * nums[right];
        while (left < right) {
            if(l < r) {
                rst.push_back(r);
                right--;
                r = nums[right] * nums[right];
            } else if (l > r) {
                rst.push_back(l);
                left++;
                l = nums[left] * nums[left];
            } else {
                rst.push_back(l);
                rst.push_back(l);
                right--;
                r = nums[right] * nums[right];
                left++;
                l = nums[left] * nums[left];
            }
        }
        if (left == right) {
            rst.push_back(l);
        }
        vector<int> rstt;
        for(int i = 0, j = len; i <= len; i++, j--) {
            rstt.push_back(rst[j]);
        }
        return rstt;
    }
    /**
     * 189: rotate array. reverse: [first, last)
     * @param nums
     * @param k
     */
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        /**  of time limit
        if(k >= len) k = k % len;
        int id = len - k;
        for(int i = 0; i < id; i++) {
            nums.push_back(nums[0]);
            nums.erase(nums.begin());
        }*/
        k = k % len;
        reverse(nums.begin(), nums.begin() + len - k);
        reverse(nums.begin()+ len - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
