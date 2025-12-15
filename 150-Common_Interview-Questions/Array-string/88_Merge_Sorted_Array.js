// Given: two sorted arrays
// Return: merged single array sorted in non-decreasing order. store in nums1

// Time: O(n + m), space: O(1)

var merge = function(nums1, m, nums2, n) {
    for (let i = nums1.length - 1; i >= 0; i--) {
        let largest;
        if (m > 0 && n > 0) {
            if (nums1[m - 1] >= nums2[n - 1]) {
                m--;
                largest = nums1[m];
            } else {
                n--;
                largest = nums2[n];
            }
        } else if (m == 0) {
            n--;
            largest = nums2[n];
        } else {
            m--;
            largest = nums1[m];
        }
        nums1[i] = largest;
    }
};