
class Solution {
public:

    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis) {

        if (vis[node] == 1)
            return false;

        if (vis[node] == 2)
            return true;

        vis[node] = 1;

        for (int child : graph[node]) {

            if (!dfs(child, graph, vis))
                return false;
        }

        vis[node] = 2;

        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> vis(n, 0);
        vector<int> answer;

        for (int i = 0; i < n; i++) {

            if (dfs(i, graph, vis)) {
                answer.push_back(i);
            }
        }

        return answer;
    }
};
