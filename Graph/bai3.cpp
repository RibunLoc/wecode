#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int v, e;
    cin >> v >> e;

    map<string, int> degrees;
    vector<string> vertices;


    for (int i = 0; i < v; i++) {
        string vertex;
        cin >> vertex;
        degrees[vertex] = 0;
        vertices.push_back(vertex);
    }


    for (int i = 0; i < e; i++) {
        string u, v;
        cin >> u >> v;
        degrees[u]++;
        degrees[v]++;
    }

  
    stringstream output;
    for (const auto& vertex : vertices) {
        output << degrees[vertex] << " ";
    }

    
    cout << output.str() << endl;

    return 0;
}
