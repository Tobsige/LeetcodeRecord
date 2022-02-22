#include <vector>
using namespace std;
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
        vector<int> num2;
        if (nums[len2] < target && nums[len - 1] > target) {
            num2.assign(len2, len - 1);
        }
        else if (nums[len2] > target && nums[0] > target) {
            num2.assign(0, len2);
        }
        return search(num2, target);
    }
};