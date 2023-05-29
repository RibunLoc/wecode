/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

//###INSERT CODE HERE -
class Graph
{
private:
    vector<vector<int>> matrix;
    vector<string> names;
    map<string, int> v_index;
public:
    void nhap(int v, int e)
    {
        //khai báo kích thước ma trânj
        matrix=vector<vector<int>>(v, vector<int>(v,0));

        names = vector<string>(v, " ");
        for (int i = 0; i < v; i++)
        {
            string s;cin >> s;
            names[i] = s;
            v_index[s] = i;
        }
        for (int i = 0; i < e; i++)
        {
            string x,y;cin >> x >> y;
            int xi = v_index[x];
            int yi = v_index[y];
            matrix[xi][yi] = 1;
            
        }
        
    }
    void myProcess(int n)
    {
        for (int i = 0; i < n; i++)
        {
            int choice;
            cin >> choice;
            if(choice == 1)
            {
                string u, v;
                cin >> u >> v;
                int ui =v_index[u];
                int vi = v_index[v];
                if(matrix[ui][vi] == 1 )
                {
                    cout << "TRUE"<< endl;
                }
                else
                {
                    cout << "FALSE"<<endl;
                }
            }
            else if(choice == 2)
            {
                string u, v;
                cin >> u ;
                int ui = v_index[u];
                vector<string> other;
                for (int j = 0; j < matrix[ui].size(); j++)
                {
                    if(matrix[ui][j] == 1 && j != ui)
                    {
                        other.push_back(names[j]);
                    }
                }
                if(other.empty())
                {
                    cout << "NONE"<< endl;
                }
                else
                {
                    for (const string& name : other)
                    {
                        cout << name << " ";
                    }
                    
                    cout << endl;
                }
            }
        }
        
    }
};


int main()
{
    Graph G;
    int v, e, n; cin >> v >> e >> n;
    G.nhap(v, e);
    G.myProcess(n);
    return 0;
}

