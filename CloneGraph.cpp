#include <iostream>

using namespace std;

// Definition for a Node in the graph.
class Node {
public:
    int val;
    Node** neighbors;
    int numNeighbors;

    Node(int _val, int _numNeighbors) {
        val = _val;
        numNeighbors = _numNeighbors;
        neighbors = new Node*[numNeighbors];
    }
};

// Array to store visited nodes to prevent cycles
Node* visited[100]; // Assume graph has at most 100 nodes

// Function to find if a node is already visited
Node* findVisited(Node* node) {
    for (int i = 0; i < 100; ++i) {
        if (visited[i] && visited[i]->val == node->val) {
            return visited[i];
        }
    }
    return NULL;
}

// Function to clone the graph
Node* cloneGraph(Node* node) {
    if (!node) return NULL;

    // If the node is already visited, return its clone
    Node* existingClone = findVisited(node);
    if (existingClone) {
        return existingClone;
    }

    // Create a new node (clone) with the value of the current node
    Node* cloneNode = new Node(node->val, node->numNeighbors);

    // Mark the current node as visited by adding it to the visited array
    for (int i = 0; i < 100; ++i) {
        if (!visited[i]) {
            visited[i] = cloneNode;
            break;
        }
    }

    // Clone the neighbors
    for (int i = 0; i < node->numNeighbors; ++i) {
        cloneNode->neighbors[i] = cloneGraph(node->neighbors[i]);
    }

    return cloneNode;
}

// Function to print the graph for testing
void printGraph(Node* node, bool visitedPrint[]) {
    if (!node || visitedPrint[node->val]) return;

    visitedPrint[node->val] = true;
    cout << "Node " << node->val << " has neighbors: ";
    for (int i = 0; i < node->numNeighbors; ++i) {
        cout << node->neighbors[i]->val << " ";
    }
    cout << endl;

    for (int i = 0; i < node->numNeighbors; ++i) {
        printGraph(node->neighbors[i], visitedPrint);
    }
}

int main() {
    // Example graph creation for testing (manual graph creation)
    Node* node1 = new Node(1, 2); // Node 1 with 2 neighbors
    Node* node2 = new Node(2, 2); // Node 2 with 2 neighbors
    Node* node3 = new Node(3, 2); // Node 3 with 2 neighbors
    Node* node4 = new Node(4, 2); // Node 4 with 2 neighbors

    // Manually linking the neighbors (like an adjacency list)
    node1->neighbors[0] = node2;
    node1->neighbors[1] = node4;
    node2->neighbors[0] = node1;
    node2->neighbors[1] = node3;
    node3->neighbors[0] = node2;
    node3->neighbors[1] = node4;
    node4->neighbors[0] = node1;
    node4->neighbors[1] = node3;

    // Initialize visited array with nulls
    for (int i = 0; i < 100; ++i) {
        visited[i] = NULL;
    }

    // Clone the graph
    Node* clone = cloneGraph(node1);

    // Print original graph
    bool visitedPrint[100] = {false};
    cout << "Original Graph:" << endl;
    printGraph(node1, visitedPrint);

    // Print cloned graph
    for (int i = 0; i < 100; ++i) visitedPrint[i] = false;
    cout << "Cloned Graph:" << endl;
    printGraph(clone, visitedPrint);

    return 0;
}
