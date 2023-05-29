#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;

class Graph
{
public:
    vector<vector<int>> matrix;
    vector<string> v_list;
    map<string, int> v_index;
    stack<string> open;
    vector<bool> close;
    map<string, string> parent;
    map<string, int> shortesdistance;

public:
    void nhap(int v)
    {
        matrix = vector<vector<int>>(v, vector<int>(v, 0));
        close = vector<bool>(v, false);
        v_list.resize(v);
        for (int i = 0; i < v; i++)
        {
            string x;
            cin >> x;
            v_list[i] = x;
            v_index[x] = i;
        }
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
                cin >> matrix[i][j];
        }
    }

    void DFS(string x, string y, int v) 
    {
        open.push(x);
        close[v_index[x]] = true;
        parent[x] = "";
        shortesdistance[x] = 0;
        string path = "";
        string p;
        int dem = 0;
        int demdinh = 0;
        while (!open.empty())
        {
            p = open.top();
            open.pop();
           
            if (p == y)
            {
                string curr = y;
                while (curr != x)
                {
                    path = curr + " " + path;
                    curr = parent[curr];
                }
                path = x + " " + path;
                cout << path << endl;
                cout << demdinh + 1 << " " << shortesdistance[y] << endl;
                return;
            }
            for (int i = v-1 ; i >= 0; i--)
            {
                if (matrix[v_index[p]][i] != 0 && !close[i] )
                {
                    open.push(v_list[i]);
                    close[i] = true;
                    parent[v_list[i]] = p;
                    shortesdistance[v_list[i]] = shortesdistance[p] + matrix[v_index[p]][i];
                    dem++;
                    demdinh++;
                    //break;
                }  

                if(i == 0 && dem > 0) 
                {
                    open.push(parent[p]);
                    //parent.erase(parent.end());
                } 
            }
            
        }
        cout << "-unreachable-" << endl;
        cout << demdinh + 1 << " " << shortesdistance[y] << endl;
    }
};

int main()
{
    Graph G;
    int v;
    int n;
    cin >> v >> n;
    G.nhap(v);
    for (int i = 0; i < n; i++)
    {
        string start, end;
        cin >> start >> end;
        G.DFS(start, end, v);
        G.close = vector<bool>(v, false);
        
    }
    return 0;
}