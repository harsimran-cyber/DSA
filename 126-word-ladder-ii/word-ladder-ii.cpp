class Solution {
public:

    void dfs(string word,
             string beginWord,
             unordered_map<string, vector<string>>& parent,
             vector<string>& path,
             vector<vector<string>>& ans) {

        // Reached beginWord
        if (word == beginWord) {
            vector<string> temp = path;

            reverse(temp.begin(), temp.end());

            ans.push_back(temp);

            return;
        }

        // Try every possible parent
        for (string p : parent[word]) {

            path.push_back(p);

            dfs(p, beginWord, parent, path, ans);

            path.pop_back();
        }
    }


    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        vector<vector<string>> ans;

        // endWord must exist
        if (st.find(endWord) == st.end()) {
            return ans;
        }

        queue<string> q;
        q.push(beginWord);

        st.erase(beginWord);

        unordered_map<string, vector<string>> parent;

        bool found = false;

        while (!q.empty() && !found) {

            int levelSize = q.size();

            // Words that will be removed after this level
            unordered_set<string> usedThisLevel;

            for (int k = 0; k < levelSize; k++) {

                string current = q.front();
                q.pop();

                string word = current;

                for (int i = 0; i < word.size(); i++) {

                    char original = word[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        if (ch == original)
                            continue;

                        word[i] = ch;

                        // Valid unvisited word
                        if (st.find(word) != st.end()) {

                            // Store current as a parent
                            parent[word].push_back(current);

                            // If discovered for the first time
                            // in this level, add to queue
                            if (usedThisLevel.find(word)
                                == usedThisLevel.end()) {

                                usedThisLevel.insert(word);
                                q.push(word);
                            }

                            if (word == endWord) {
                                found = true;
                            }
                        }
                    }

                    word[i] = original;
                }
            }

            // Remove all words discovered in this level
            // only AFTER processing the whole level
            for (string word : usedThisLevel) {
                st.erase(word);
            }
        }

        // No transformation possible
        if (!found) {
            return ans;
        }

        // Start backtracking from endWord
        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, parent, path, ans);

        return ans;
    }
};