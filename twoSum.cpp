#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for(int i = 0; i < nums.size(); i++) {
        int C = target - nums[i]; //Si cerca il complemento nella unordered list
        if (map.find(C) != map.end()) {
            return {map[C], i};
        }
        map[nums[i]] = i;
    }
    return {};
}

int main() {
    //Esempio di prova fornito da LeetCode
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> risultato = twoSum(nums, target);

    if (!risultato.empty()) {
        cout << "Target " << target << " trovato" << endl;
        cout << "Indici: [" << risultato[0] << ", " << risultato[1] << "]" << endl;
        cout << "Valori: " << nums[risultato[0]] << " + " << nums[risultato[1]] << " = " << target << endl;
    } else {
        cout << "Nessuna soluzione trovata per il target " << target << "." << endl;
    }

    return 0;
}