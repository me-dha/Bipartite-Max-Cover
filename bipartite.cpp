#include <iostream>
#include<cstdlib>
#include<cstdbool>
#define m 5
#define n 5
using namespace std;
bool bpGraph[m][n];
bool bpMax(int u, bool visited[], int a[]) {
   for (int v = 0; v < n; v++) {
      if (bpGraph[u][v] && !visited[v]) {
         visited[v] = true;
         if (a[v] < 0 || bpMax(a[v], visited, a)) {
            a[v] = u;
            return true;
         }
      }
   }
   return false;
}
int maxMatch() {
   int a[n];
   for(int i = 0; i<n; i++)
      a[i] = -1;
   int count = 0;
   for (int u = 0; u < m; u++) {
      bool visited[n];
      for(int i = 0; i<n; i++)
         visited[i] = false;
      if (bpMax(u, visited, a))
         count++;
   }
   return count;
}
int main() {
    cout<<"Enter the matrix:\n";
    int i,j;
    int graph[m][n];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
        cin>>graph[i][j];
        bpGraph[i][j]=graph[i][j];
        }
    }
    cout<<"Maximum number of matching is : "<<maxMatch()<<endl;
}