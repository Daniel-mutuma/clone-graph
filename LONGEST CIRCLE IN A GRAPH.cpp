#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(int node, vector<int>& edges, vector<int>& visited, vector<int>& path) {
    visited[node] = 1;
    path[node] = 1;
    int next = edges[node];
    
    if (next != -1) {
        if (path[next]) { // Cycle detected
            return path.size() - path[next];
        }
        if (!visited[next]) { // Continue DFS if not yet visited
            int cycleLength = dfs(next, edges, visited, path);
            if (cycleLength != -1) {
                return cycleLength;
            }
        }
    }
    
    path[node] = 0; // Backtrack
    return -1;
}

int longestCycle(vector<int>& edges) {
    int n = edges.size();
    vector<int> visited(n, 0);
    int maxLength = -1;
    
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            vector<int> path(n, 0);
            int cycleLength = dfs(i, edges, visited, path);
            if (cycleLength != -1) {
                maxLength = max(maxLength, cycleLength);
            }
        }
    }
    return maxLength;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    
    vector<int> edges(n);
    cout << "Enter edges array (-1 for no outgoing edge): ";
    for (int i = 0; i < n; ++i) {
        cin >> edges[i];
    }
    
    int result = longestCycle(edges);
    if (result == -1) {
        cout << "No cycle exists." << endl;
    } else {
        cout << "Length of longest cycle: " << result << endl;
    }
    
    return 0;
}
