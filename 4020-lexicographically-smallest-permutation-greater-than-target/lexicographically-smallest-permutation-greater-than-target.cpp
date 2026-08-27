class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        int n = s.length();
        int freq[26] = {0};

        for(char c : s) {
            freq[c - 'a']++;
        }

        string prefix = "";

        for(int i = 0; i < n; i++) {

            int current = target[i] - 'a';

            // Try to keep the answer equal to target
            if(freq[current] > 0) {
                prefix += target[i];
                freq[current]--;
                continue;
            }

            // Cannot continue matching target.
            // Find smallest available character greater than target[i]
            for(int j = current + 1; j < 26; j++) {
                if(freq[j] > 0) {

                    prefix += char('a' + j);
                    freq[j]--;

                    // Add remaining characters in sorted order
                    for(int k = 0; k < 26; k++) {
                        while(freq[k] > 0) {
                            prefix += char('a' + k);
                            freq[k]--;
                        }
                    }

                    return prefix;
                }
            }

            // Need to go back and change a previous character
            break;
        }

        // Backtracking: find a previous position
        // where we can increase the character
        for(int i = prefix.length() - 1; i >= 0; i--) {

            int current = prefix[i] - 'a';
            freq[current]++;

            for(int j = current + 1; j < 26; j++) {

                if(freq[j] > 0) {

                    prefix[i] = char('a' + j);
                    freq[j]--;

                    // Remove everything after i
                    prefix = prefix.substr(0, i + 1);

                    // Append remaining smallest characters
                    for(int k = 0; k < 26; k++) {
                        while(freq[k] > 0) {
                            prefix += char('a' + k);
                            freq[k]--;
                        }
                    }

                    return prefix;
                }
            }
        }

        return "";
    }
};