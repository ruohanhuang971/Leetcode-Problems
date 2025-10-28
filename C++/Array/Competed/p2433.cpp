/* 
    Prompt: You are given an integer array pref of size n. Find and return the array arr of size n that satisfies:
    pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i].
    Note that ^ denotes the bitwise-xor operation.
*/

#include <iostream>
#include <vector>
using namespace std;

// Time = O(N), Space = O(N)
vector<int> findArray(vector<int>& pref) {
    vector<int> ans;

    ans.push_back(pref[0]);
    for (int i = 1; i < pref.size(); i++) {
        int result = pref[i - 1] ^ pref[i];
        ans.push_back(result);
    }

    return ans;
}

void printArray(vector<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> pref = {5,2,0,3,1};
    vector<int> ans = findArray(pref);
    printArray(ans);
}