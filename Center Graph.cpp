#include <iostream>
#include <vector>
using namespace std;

int findCenter(vector<vector<int> >& edges) {
    // The center of the star graph will be the common node in the first two edges
    if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
        return edges[0][0];
    } else {
        return edges[0][1];
    }
}

int main() {
    // Initialize the edges vector using the constructor
    vector<vector<int> > edges;
    edges.push_back(vector<int>(2, 0));
    edges[0][0] = 1; edges[0][1] = 2;
    edges.push_back(vector<int>(2, 0));
    edges[1][0] = 2; edges[1][1] = 3;
    edges.push_back(vector<int>(2, 0));
    edges[2][0] = 4; edges[2][1] = 2;

    cout << "The center of the star graph is: " << findCenter(edges) << endl;
    return 0;
}
