// To solve this problem, we can use a sliding window approach.
// We should consider all possible substrings of length kkk of sss one by one. We can slide a window of size kkk through the string and at each position, count the number of vowels in the window. We can then keep track of the maximum count of vowels seen so far
class Solution {

    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int count = 0, maxCount = 0;

        // count the number of vowels in the first window of length k
        for (int i = 0; i < k; i++)
            if (isVowel(s[i])) count++;
        maxCount = count;

        // slide the window through the string and count the number of vowels in each window
        for (int i = k; i < n; i++) {
            if (isVowel(s[i])) count++;
            if (isVowel(s[i-k])) count--;
            maxCount = max(maxCount, count);
        }
        
        return maxCount;
    }
};
