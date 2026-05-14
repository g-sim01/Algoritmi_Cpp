#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last_seen(256, -1); //Index of last appearence

        int max_len=0;
        int i=0; //Starting point of the interval [i,j]
        for(int j=0; j<s.length(); ++j) {
            char curr = s[j];
            if(last_seen[curr]>=i) {
                i = last_seen[curr] + 1;
            }
            last_seen[curr] = j;
            max_len = max(max_len, j - i + 1);
        }
        return max_len;
    }
};

int main() {
    //Try tests given by LeetCode
    Solution sol;
    
    // Test 1
    string test1 = "abcabcbb";
    cout << "Input: " << test1 << endl;
    cout << "Result: " << sol.lengthOfLongestSubstring(test1) << endl;
    cout << "Expected: 3\n" << endl;

    // Test 2
    string test2 = "bbbbb";
    cout << "Input: " << test2 << endl;
    cout << "Result: " << sol.lengthOfLongestSubstring(test2) << endl;
    cout << "Expected: 1\n" << endl;

    // Test 3
    string test3 = "pwwkew";
    cout << "Input: " << test3 << endl;
    cout << "Result: " << sol.lengthOfLongestSubstring(test3) << endl;
    cout << "Expected: 3\n" << endl;

    // Test 4
    string test4 = "";
    cout << "Input: \"" << test4 << "\" (Empty)" << endl;
    cout << "Result: " << sol.lengthOfLongestSubstring(test4) << endl;
    cout << "Expected: 0\n" << endl;

    // Test 5
    string test5 = " ";
    cout << "Input: \"" << test5 << "\" (Space)" << endl;
    cout << "Result: " << sol.lengthOfLongestSubstring(test5) << endl;
    cout << "Expected: 1" << endl;

    // Test 6
    string test6 = "dvdf";
    cout << "Input: " << test6 << endl;
    cout << "Result :" << sol.lengthOfLongestSubstring(test6) << endl;
    cout << "Expected: 3" <<  endl;
    
    return 0;
}