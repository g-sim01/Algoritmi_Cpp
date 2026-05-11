#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for(int i = 0; i < nums.size(); i++) {
        int C = target - nums[i]; //We search for the complement in the unordered map
        if (map.find(C) != map.end()) {
            return {map[C], i};
        }
        map[nums[i]] = i;
    }
    return {};
}

int main() {
    //Try test given by LeetCode
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        cout << "Target " << target << " found" << endl;
        cout << "Indexes: [" << result[0] << ", " << result[1] << "]" << endl;
        cout << "Values: " << nums[result[0]] << " + " << nums[result[1]] << " = " << target << endl;
    } else {
        cout << "No solution found for target " << target << "." << endl;
    }

    return 0;
}