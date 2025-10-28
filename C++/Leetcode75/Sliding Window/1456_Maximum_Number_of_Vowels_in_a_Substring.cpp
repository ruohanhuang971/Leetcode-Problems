#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    Sliding window approach with twist:
        it takes too long to construct an actual substring everytime
        so just count the vowels in a certain region and after moving out
        of that region subtract from count

    Time Complexity: O(N), Space Complexity: O(1)
*/

int maxVowels(string s, int k) {
    int maxVowels = 0;
    int curVowels = 0;

    for (int i = 0; i < s.size(); i++) {
        if (isVowel(s[i])) {
            curVowels++;
        }

        if ((i + 1) >= k) {  // start sliding window
            maxVowels = max(curVowels, maxVowels);
            if (isVowel(s[(i + 1) - k])) {
                curVowels--;
            }
        }
    }

    return maxVowels;
}

bool isVowel(char s) {
    vector<char> vowel = {'a', 'e', 'i', 'o', 'u'};
    return find(vowel.begin(), vowel.end(), s) != vowel.end();
}