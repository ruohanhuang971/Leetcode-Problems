Video Link: https://www.youtube.com/watch?v=Z_c4byLrNBU

# **Keyword -> Algorithm Cheat sheet**

| Pattern/Keyword | Algorithm/Technique | Example Problem |
|-----------------|---------------------|-----------------|
| **"Top k"** | Heap | K closest points |
| **"How many ways.."** | DFS | Decode ways |
| **"How many ways.."** | DP | Robot paths |
| **"Substring"** | Sliding window | Longest substring without repeating characters |
| **"Palindrome"** | Two pointers | Valid Palindrome |
| **"Palindrome"** | DFS | Palindrome Partitioning |
| **"Palindrome"** | DP | Palindrome Partitioning II |
| **"Tree"** | (shortest, level-order)BFS,  (else)DSF| Binary Tree Level-Order Traversal, Max Depth |
| **"Parentheses"** | Stack | Valid Parentheses |
| **"Subarray"** | Sliding window | Maximum subarray sum |
| **"Subarray"** | Prefix sum | Subarray sum |
| **"Subarray"** | Hashmap | Continuous subarray sum |
| **"Max subarray"** | Greedy | Kadane's Algorithm |
| **"X Sum"** | Two pointer | Two sum |
| **"Max/longest sequence"** | Dynamic programming, DFS | Longest increasing subsequence |
| **"Max/longest sequence"** | Mono deque | Sliding window maximum |
| **"Minimum/Shortest"** | Dynamic programming, DFS | Minimal path sum |
| **"Minimum/Shortest"** | BFS | Shortest path |
| **"Partition/split array/string"** | DFS | Decode ways |
| **"Subsequence"** | Dynamic programming, DFS | Longest increasing subsequence |
| **"Subsequence"** | Sliding window | Longest increasing subsequence |
| **"Matrix"** | BFS, DFS | Flood fill, Islands |
| **"Matrix"** | Dynamic programming | Maximal square |

# **Big O Notation:**
- **O(1) constant time:** 
    - No matter how big the input, time complexity never changes
    - ex: access by index in array, checking is something exist in set
- **O(log n) logarithmic time:** 
    - divide problem in half each time
    - ex: binary search
- **O(n) linear time:** 
    - going through each element once
    - ex: loop, traversing lists
- **O(nlogn):** 
    - almost always related to sorting 
    - note: input up to 10^5 need O(nlogn) or better
- **O(n^2):** 
    - nested loops (usually too slow for large inputs) 
    - ex: brute force comparisons


# **Data Structure**

### **Array**
- **Properties:**:
    - Access by index: O(1)
    - Append: O(1)
    - insert/delete: O(n)
- **Use Cases:**
    - traverse structure in order
    - access specific index
    - compare elements from both end
    - tricks such as: sliding window, prefix sum, etc

### **String**
- **Properties:**
    - array of characters
    - modifying string creates a new string (not in C++ tho)
- **Notes:**
    - string problems are almost never brute force character checking
        - common patterns: sliding window, two pointers

### **Set:**
- **Properties:**
    - can check if element exist in O(1)
        ```cpp
        std::vector<int> num = {1, 2, 3, 4, 5};
        std::unordered_set<int> s(num.begin(), num.end());  
        std::cout << (s.find(3) != s.end()) << std::endl;  // Outputs: 1 (true)
        ```
- **Use Cases:**
    - uniqueness
    - existence

### **Hash Map**
- **Properties:**
    - stores key-value pairs
        - lookup & insert: O(1)
- **Use Cases:**
    - finding an item that already exit: O(1)
    - frequency map
        ```cpp
        std::unordered_map<int, int> my_map;
        for (auto item : data) {
            my_map[item]++;  // Automatically initializes to 0 if not present, then increments
        }
        ```
    - allow O(n) solution because you can build & use the map in one-pass


# **Patterns**
### **Two Pointers:**
- use two pointers to move through a structure to avoid nested loops or repeated scanning
- *two pointers move in the same direction:*
    - do a single pass but keep track of a range of data rather than one element
    - ex: fast & slow 2 pointer set-up
        - if fast pointer reaches the end -> slow pointer is at the center
        - if fast pointer laps the slow pointer -> cycle
- *two points start at the ends and move towards the middle:*
    - find pair or combination in sorted array
    - compare symmetric part of a structure (palindromes)
- *benefit:*
    - reduce # of iterations
    - track relationship between two indices
    - avoid extra space
- *use cases:*
    - brute force method is checking all pairs or repeated scans
    - palindrome
    - reversal
    - merging sorted data
    - "k" sized comparison

### **Siding Window:**
- process different parts of the structure without revisiting elements 
    ```cpp
    int sliding_window_flexible_longest(vector<int>& input) {
        initialize window, ans;
        int left = 0;

        for (int right = 0; right < input.size(); right++) {
            append input[right] to window
            while invalid(window):
                remove input[left] from window
                left += 1
            ans = max(ans, window)
        }
    }
    ```
- *use case:*
    - substring, sub-array, group of consecutive elements
        - "Find the length of the longest substring with at most K unique characters."
        - "What's the smallest sub-array with a sum greater than a target?"
        - "Return the longest window where a certain rule is valid."


### **Binary Search:**
- valid search for any array that is monolithic [only changes in one direction].
    - ex: an array where if the condition is satisfied it is always satisfied, find first instance of condition being satisfied
    ```cpp
    int binary_search(vector<int> List, target: int) {
        int left = 0; int right = List.size() - 1;
        int first_true_index = -1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (feasible(mid)) { // checks if mid satisfies some condition
                first_true_index = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return first_true_index;
    }
    ```

### **BFS:**
- property:
    - find shortest number of step to reach something
    - find first match/closest to root
    - care about depth, distant, level 
- key:
    - uses a queue to traverse node in the order of discovery
    ```cpp
    void bfs(Node* root) {
        queue<Node*> q;
        unordered_set<Node*> visited;
        
        q.push(root);
        visited.insert(root);
        
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            
            vector<Node*> neighbors = getNeighbors(node);
            for (Node* neighbor : neighbors) {
                if (visited.find(neighbor) != visited.end()) {
                    continue;
                }
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
    ```

### **DFS:**
- uses:
    - puzzles / state exploration
    - graph coloring
    - recursive traversal
    - backtracking
- key:
    - implemented recursively
    ```cpp
    void dfs (Node* node, vector<Node*> visited) {
        vector<Node*> neighbors = getNeighbors(node);
        for (Node* neighbor : neighbors) {
            if (visited.find(neighbor) != visited.end()) {
                continue;
            }
            visited.insert(neighbor);
            dfs(neighbor, visited);
        }
    }
    ```

### **Backtracking:**
- uses:
    - combination, permutation
    - building up partial solution step by step
    - want all possible solutions
    - need to discard bad path early
- key:
    ```cpp
    void dfs (pair<int, int> index, vector<pair<int, int>> path /* additional states*/) {
        if (isLeaf(index)) {
            ans.push_back(path);
        }
        
        vector<pair<int, int>> neighbors = getNeighbors(index);
        for (pair<int, int> neighbor : neighbors) {
            if (!is_valid(neighbor)) {
                continue;
            }
            path.add(neighbor);

            // update states if necessary

            dfs(neighbor, path);
            
            path.pop();
        }
    }
    ```

### **Priority Queue:**
- properties:
    - insertion & removal: O(logn)
- use cases:
    - Repeatedly extract the smallest/largest item
    - Maintaining a top-k or bottom-k set of values
    - Real-time ranking, greedy selection, etc.
    - Need to sort on the fly, faster than O(n log n)






# **Tricks**
- in-order traversal of BST:
    ```cpp
    void helper(TreeNode* node) {
        if (!node) return;

        // go all the way left
        helper(node->left);
        cout << node->val << " ";
        
        helper(node->right);
    }
    ```
- line sweep algorithm:
    - usually used for how many meeting room needed given start and end time:
        - count++ when meeting start and count-- when meeting end
        - at the end return max count [ie: the most # of the meeting happening at the same time]
    ```cpp
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> starts, ends;

        // get vector of start and end times
        for (auto& interval : intervals) {
            starts.push_back(interval[0]);
            ends.push_back(interval[1]);
        }

        // Sort both arrays
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int rooms = 0;
        int maxRooms = 0;
        int startPtr = 0;
        int endPtr = 0;

        while (startPtr < intervals.size()) {
            if (starts[startPtr] < ends[endPtr]) {
                rooms++;
                maxRooms = max(maxRooms, rooms);
                startPtr++;
            } else {
                rooms--;
                endPtr++;
            }
        }

        return maxRooms;
    }
    ```