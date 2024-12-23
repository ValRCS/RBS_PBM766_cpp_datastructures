//let's implement a Graph class
//we will use Node struct with simple string id
//we will use Edge struct with src and dest string id of Node names and double weight representing the edge weight
//we will use unordered set to store the nodes and edges
//we will use unordered map to store the adjacency list of the graph

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set> //this is ordered set in C++! meaning O(logn) operations
#include <vector>
#include <string>
#include <fstream>
#include <sstream> //sstream is needed for string stream

using namespace std;

struct Node {
    string id;
    //simple constructor
    Node(string id) : id(id) {}
};

struct Edge {
    string src;
    string dest;
    double weight;
    //simple constructor
    Edge(string src, string dest, double weight) : src(src), dest(dest), weight(weight) {}
};

class Graph {
    //unordered set to store the nodes
    unordered_set<Node*> nodes;
    //set of node ids to make it simpler to check if node exists
    unordered_set<string> nodeIds;
    //unordered set to store the edges
    unordered_set<Edge*> edges;
    //unordered map to store the adjacency list of the graph
    unordered_map<string, vector<pair<string, double>>> adjList;

public:
    //add node to the graph //not really needed publicly anymore since we are adding nodes when adding edges
    void addNode(string id) {
        Node* node = new Node(id);
        nodes.insert(node);
        nodeIds.insert(id);
    }

    //add edge to the graph
    void addEdge(string src, string dest, double weight) {
        //let's add nodes if they are not in the graph
        if (nodeIds.find(src) == nodeIds.end()) {
            addNode(src);
        }
        if (nodeIds.find(dest) == nodeIds.end()) {
            addNode(dest);
        }
        //could add a check to see if src and dest are the same and if Edge already exists
        Edge* edge = new Edge(src, dest, weight);
        edges.insert(edge);
        adjList[src].push_back({dest, weight});
    }

    //print the graph
    void print() {
        cout << "Graph:" << endl;
        //how many total nodes
        cout << "Node count: " << nodes.size() << endl;
        for (auto node : nodes) {
            cout << node->id << " -> ";
            for (auto neighbor : adjList[node->id]) {
                cout << "Neighbor:" << neighbor.first << "(weight:" << neighbor.second << ") ";
            }
            cout << endl;
        }
    }
    //simple constructor
    Graph() {
        cout << "Creating graph" << endl;
    }

    //let's add a constructor that takes csv file name and reads the graph from the file
    //graph is stored in csv file where each line represents an edge, first column is source node, second column is destination node, third column is edge weight
    Graph(string filename) {
        cout << "Creating graph from file" << endl;
        //open the file
        ifstream file(filename);
        //read the file line by line
        string line;
        while (getline(file, line)) {
            //parse the line
            stringstream ss(line);
            string src, dest;
            double weight;
            getline(ss, src, ',');
            getline(ss, dest, ',');
            ss >> weight;
            //add the edge to the graph
            addEdge(src, dest, weight);
        }
        cout << "Graph created from file" << endl;
    }

    //destructor
    ~Graph() {
        cout << "Deleting graph" << endl;
        for (auto node : nodes) {
            delete node;
        }
        for (auto edge : edges) {
            delete edge;
        }
        cout << "Graph deleted" << endl;
    }

    //lets add a Depth First Search that check whether one can reach dst from src
    //let's return a path if it exists or empty vector if it does not exist
    vector<string> dfs(string src, string dst) {
        //create a visited set
        unordered_set<string> visited;
        //lets use vector to store the path
        vector<string> path;
        //call the recursive helper function
        bool isPath = dfsHelper(src, dst, visited, path);
        return isPath ? vector<string>(path.begin(), path.end()) : vector<string>();
    }

    //recursive helper function for dfs
    bool dfsHelper(string src, 
                string dst, 
                unordered_set<string>& visited,
                vector<string>& path) {
        //base case if src is dst return true
        if (src == dst) {
            path.push_back(src);
            return true;
        }
        //mark src as visited
        visited.insert(src);
        path.push_back(src);
        //check all neighbors
        for (auto neighbor : adjList[src]) {
            //if neighbor is not visited call dfsHelper recursively
            if (visited.find(neighbor.first) == visited.end()) {
                //so we do a recursive call
                if (dfsHelper(neighbor.first, dst, visited, path)) {
                    return true;
                }
            }
        }
        //if we reach here that means we cannot reach dst from src
        return false;
    }

    //let's make a function that takes in path and returns cost of the path
    double pathCost(vector<string> path) {
        //this function will return true cost as long as the path is valid
        //otherwise it will only return cost the valid part of the path
        double cost = 0;
        for (size_t i = 0; i < path.size() - 1; i++) {
            for (auto neighbor : adjList[path[i]]) {
                if (neighbor.first == path[i + 1]) {
                    cost += neighbor.second;
                    break;
                }
            }          
        }
        return cost;
    }
};

//lets add argc and argv if there is an argument that means a a csv file name is provided
int main(int argc, char* argv[]) {
    if (argc == 2) {
        Graph graph(argv[1]);
        graph.print();
        return EXIT_SUCCESS;
    }
    //if there are 4 arguments then we are checking if we can reach dst from src from that graph
    if (argc == 4) {
        Graph graph(argv[1]);
        vector<string> path = graph.dfs(argv[2], argv[3]);
        if (path.size() > 0) {
            cout << "Path exists: ";
            for (auto node : path) {
                cout << node << " ";
            }
            cout << endl;
            cout << "Path cost: " << graph.pathCost(path) << endl;
        } else {
            cout << "Path does not exist" << endl;
        }
        return EXIT_SUCCESS;
    }

    Graph graph;
    //no need to add nodes anymore since we are adding nodes when adding edges
    // graph.addNode("A");
    // graph.addNode("B");
    // graph.addNode("C");
    // graph.addNode("D");
    graph.addEdge("A", "B", 1);
    graph.addEdge("A", "C", 3);
    graph.addEdge("B", "C", 2);
    graph.addEdge("C", "D", 3);
    graph.addEdge("D", "A", 4);
    graph.print();
    return EXIT_SUCCESS;
}