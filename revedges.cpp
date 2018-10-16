# include <iostream>
# include <cstdio>
# include <vector> 
# include <queue> 
# define NR_MAX 510
# define Q_MAX 1000001
# define INF 2000000000
# define neighbour Gaux[node][i]

using namespace std;

vector <int> Gaux[NR_MAX];
pair <int,int> queries[Q_MAX];
queue <int> Q;

int dist[NR_MAX][NR_MAX];
int G[NR_MAX][NR_MAX];
int n,m,q,x,y;


void read() 
{
    freopen("revedges.in", "r", stdin);
    scanf("%d %d %d\n", &n, &m, &q);
    for(int i=1; i<=m; ++i)
    {
        scanf("%d %d\n", &x, &y);
        G[x][y] = 1;
        Gaux[x].push_back(y);
        Gaux[y].push_back(x);
    }
    
    for(int i=1; i<=q; ++i)
        scanf("%d %d\n", &queries[i].first, &queries[i].second);
        
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            dist[i][j] = INF;
            
    fclose(stdin);
    return;
}


void BFS(int start_node)
{
    Q.push(start_node);
    dist[start_node][start_node] = 0;
    
    while(!Q.empty())
    {
        int node = Q.front();
        Q.pop();
        for(int i=0; i<Gaux[node].size(); ++i) 
        {
            int new_path_distance = dist[start_node][node] + (!G[node][neighbour]);
            if(new_path_distance < dist[start_node][neighbour])
            {
                dist[start_node][neighbour] = new_path_distance;
                Q.push(neighbour);
            }
        }
            
    }
    
    return;
}

void solve() 
{
    freopen("revedges.out", "w", stdout);
    
    for(int i=1; i<=n; ++i)
        BFS(i);
        
    for(int i=1; i<=q; ++i) 
        printf("%d\n", dist[queries[i].first][queries[i].second]);
        
    fclose(stdout);
    return;
}

int main()
{
    read();
    solve();
    return 0;
}

