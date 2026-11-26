#include<bits/stdc++.h> //manggil vektor & list
using namespace std;

typedef  pair<int, int> iPair; //untuk menyimpan catatan di ipair

class Graph{ 
    int V;  // nyimpen total jumlah vertex 
    list<int> *adj; //untuk nentuin suatu vertex ada hubungannya ga dengan vertex yg lain
    vector< pair<int, iPair> > edges; // untuk nyimpen daftar jalan seberapa besar cost nya
    void DFS(int v, bool visited[]); // untuk menyusuri graf

public:
    Graph(int V);   // Constructor

    void addEdge(int u, int v, int w); // untuk nampung cost

    bool isConnected(); // untuk ngecheck, kalau dihapus graf nya putus apa engga

    void reverseDeleteMST(); // algoritma utama
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V]; //bikin graf kita sesuai seberapa banyak yg kita mau
}

void Graph::addEdge(int u, int v, int w){
    adj[u].push_back(v); 
    adj[v].push_back(u); 
    edges.push_back({w, {u, v}}); // bikin daftar, dan bikin cost
}

void Graph::DFS(int v, bool visited[]){
    visited[v] = true; // tandai sebagai sdh dikunjungi

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i, visited);
}


bool Graph::isConnected(){ // utk nyuruh si dfs utk nyari berapa byk vertex di graph
    bool visited[V];
    memset(visited, false, sizeof(visited)); // ngasih tau kalau ini udh dikunjungi apa blm

    DFS(0, visited); //dimulai dari vertex 0

    for (int i=1; i<V; i++) //kalau udh aman
        if (visited[i] == false)
            return false;

    return true;
}

// ------ Main Part of Reverse Delete -----
void Graph::reverseDeleteMST(){
    sort(edges.begin(), edges.end()); // mengurutkan dari cost terendah

    int mst_wt = 0; // utk total biaya akhir

    cout << "Edges in MST\n";

    for(int i = edges.size() - 1; i >= 0; i--){
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        // untuk nanya ini aman atau engga kalau dihapus
        adj[u].remove(v);
        adj[v].remove(u);

        if(isConnected() == false){ // kalau ga aman tinggal balikin nilai je
            adj[u].push_back(v);
            adj[v].push_back(u);

            cout << "( " << u << ", " << v << " )\n";
            mst_wt += edges[i].first;
        }
        
    }
    cout << "Total weight of MST is " << mst_wt;
}

int main(){
    int V = 9;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.reverseDeleteMST();
    return 0;
}