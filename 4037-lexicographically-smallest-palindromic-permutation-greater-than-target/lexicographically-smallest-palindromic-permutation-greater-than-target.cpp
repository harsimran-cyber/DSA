class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        
        int freq[26] = {0};

        for (char c : s) {
            freq[c - 'a']++;
        }

        // Check whether a palindromic permutation is possible
        int oddCount = 0;
        char middle = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                oddCount++;
                middle = 'a' + i;
            }

            // Only half of each character is used
            // in the first half of the palindrome
            freq[i] /= 2;
        }

        if (oddCount > 1) {
            return "";
        }

        int halfLen = s.length() / 2;

        // Try to match target's first half
        int matched = 0;

        while (matched < halfLen) {
            int ch = target[matched] - 'a';

            if (freq[ch] == 0) {
                break;
            }

            freq[ch]--;
            matched++;
        }

        // If the complete first half was matched,
        // construct the palindrome and check it.
        if (matched == halfLen) {
            string ans = target.substr(0, halfLen);

            if (oddCount == 1) {
                ans += middle;
            }

            string second = target.substr(0, halfLen);
            reverse(second.begin(), second.end());

            ans += second;

            if (ans > target) {
                return ans;
            }
        }

        /*
        Find the rightmost position where we can replace
        target[i] with a larger available character.
        */

        for (int i = matched; i >= 0; i--) {

            // If target[i] was already used while matching,
            // restore it.
            if (i < matched) {
                freq[target[i] - 'a']++;
            }

            int current = target[i] - 'a';

            // Find the smallest available character
            // strictly greater than target[i]
            for (int ch = current + 1; ch < 26; ch++) {

                if (freq[ch] > 0) {

                    string half = target.substr(0, i);

                    half += char('a' + ch);
                    freq[ch]--;

                    // Fill the remaining positions with
                    // smallest characters
                    for (int j = 0; j < 26; j++) {
                        while (freq[j] > 0) {
                            half += char('a' + j);
                            freq[j]--;
                        }
                    }

                    // Construct the complete palindrome
                    string ans = half;

                    if (oddCount == 1) {
                        ans += middle;
                    }

                    string second = half;
                    reverse(second.begin(), second.end());

                    ans += second;

                    return ans;
                }
            }
        }

        return "";
    }
};