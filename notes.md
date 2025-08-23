**Helper Code** 
- 
Compile: \
g++ filename.cpp -o output_name

Include:
``` cpp
#include <iostream>
#include <vector>
using namespace std;
```

Helper:
```cpp
void printArray(vector<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << "\n";
}
```
Time Complexity: O(), Space Complexity: O()


**Array** 
- 
- Possible to use pointers to access directly points in the array
    - get how many smaller than the array and how many number larger in the array before starting a second pass that compose the answer
    - 2161. Partition Array According to Given Pivot
- If a problem seem like it needs 2 process that are unrelated, try using one for loop with one process starting from the left one starting from the right
    - calculating steps from the left and steps from the right in one for loop 
    - 1769. Minimum Number of Operations to Move All Balls to Each Box
- Note about preformance: vector inserts are slow, for (int i:nums) is faster and easier than a normal for loop
- How to sort vector
    ```cpp
    sort(nums.begin(), nums.end());
    ```
- How to check if vector is empty
    ```cpp
    nums.empty()
    ```
- tabluar approach:
    - process left-side, process right-side => combine them together [p238]
- A lot of times, to save time -> 2 pointers. go from both end at the same time.

**sliding window**
-
- basic sliding window for loop
    ```cpp
        for (int i = 0; i < nums.size(); i++) {
            curSum += nums[i];
            
            if ((i + 1) >= k) { // start sliding window
                maxSum = ((curSum > maxSum) ? curSum : maxSum);
                curSum -= nums[(i + 1) - k];
            }
        
        }
    ```
- intuition:
    - only check if condition to continue is not satified and then while loop move start of window until condition is satified again


**Hash Map / Set** (should revisit)
-
- A lot of problems contain "how many times does _ appear/does _ appear in A but not B"


**Stack**
-
- LIFO
- Given a list of things, have rules for how the list of thing interact with each other
- Iterate through the list and pop/push_back to a newlist based on the rules.


**Stack**
-
- FIFO


**Binary Tree - DFS**
-
- At each node, recurse on its left and right node
    ```cpp
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }
    ```


**Binary Tree - BFS**
-
- Use queue to denote which nodes to visit
    ```cpp
    if (!root) {
        return vector<int>();
    }

    queue<TreeNode *> visit;
    vector<int> ans;
    visit.push(root);

    while (!visit.empty()) {
        int size = visit.size();
        for (int i = 0; i < size; i++) {
            TreeNode *node = visit.front();

            if (node->left) {
                visit.push(node->left);
            }
            if (node->right) {
                visit.push(node->right);
            }

            if (i == size - 1) {
                ans.push_back(node->val);
            }
            visit.pop();
        }
    }
    ```




**Graph - DFS**
-
- similar to binary tree DFS, use recursion, keep a vector of visited nodes to prevent infinite loops
- Normally use when there are connected nodes and the connection matters
    - ie: finding how many connected clusters there are: 547_Number_of_Provinces


**Graph - BFS**
-
- similar to binary tree BFS, use queue and keep a visit vector
- Normally have at each step need to check radius as condition for updating
    - ie: 996_Rotting_Oranges


**Priority Queue**
- 
- a container adaptor that provides constant time lookup of the largest (by default) element, at the expense of logarithmic insertion and extraction.


**Misc** 
- 
- possible to convert char -> int with '1' - '0' = 1
- reminder for recusion: space complexity need to take into account the space take up by function calls
- how to get all subset of a set:
    ```cpp
    void subsetRecur(int i, vector<int>& arr, 
       vector<vector<int>>& res, vector<int>& subset) {
    
        // add subset at end of array
        if (i == arr.size()) {
            res.push_back(subset);
            return;
        }
        
        // include the current value and 
        // recursively find all subsets
        subset.push_back(arr[i]);
        subsetRecur(i+1, arr, res, subset);
        
        // exclude the current value and 
        // recursively find all subsets.
        subset.pop_back();
        subsetRecur(i+1, arr, res, subset);
    }
    ```
- how to find an item in a vector:
    ```cpp
    #include <algorithm>
    #include <vector>

    if ( std::find(vec.begin(), vec.end(), item) != vec.end() )
        do_this();
    else
        do_that();
    ```
- how to get a set from a vector
    ```cpp
    unordered_set<int> new_set(nums.begin(), nums.end());
    ```