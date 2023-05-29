#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>

using namespace std;
class Graph
{
private:
    vector<vector<int>> matrix;
    vector<string> names;
    map<string, int> v_index;
public:
    void nhap(int e)
    {
        int  v = e ;
        matrix = vector<vector<int>>(v,vector<int>(v,0));
        for (int i = 0; i < e; i++)
        {
            string x,y;
            cin >> x >> y;
            if(v_index.find(x) == v_index.end())
            {
                names.push_back(x);
                v_index[x] = v_index.size() - 1;
            }
            if(v_index.find(y) == v_index.end())
            {
                names.push_back(y);
                v_index[y] = v_index.size() - 1;
            }
            int xi = v_index[x];
            int yi = v_index[y];
            matrix[xi][yi] = 1;
            matrix[yi][xi] = 1;
        }

    }
    bool weighted_graph()
    {
        int v = matrix.size();
        for (int i = 0; i < v; i++)
        {
            for (int j = i+1; j < v; j++)
            {
                if(i != j && matrix[i][j] == 0)
                    return false;
            }
            
        }
        return true;
        
    }
};


int main() {
    Graph G;
    int e;
    cin >> e;
    G.nhap(e);
 
    if(G.weighted_graph())
        cout <<"TRUE" <<endl;
    else
        cout << "FALSE" << endl;
    

    return 0;
}
