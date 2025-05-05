#include<iostream>
#include<vector>
using namespace std;
int main(){
    int cost[10][10],i,j,k,n,v,e,visit[10],visited[10],top,stk[10];
    cout<<"Enter number of vertices:";
    cin>>n;
    cout<<"Enter number of edges:";
    cin>>e;
    cout<<"Enter start and end vertex of edges:";
    for(k=1;k<=n;k++){
        cin>>i>>j;
        cost[i][j]=1;
    }
    cout<<"Enter initial vertex to start dfs traversal:";
    cin>>v;
    cout<<"DFS traversal :";
    cout<<v<<" ";
    visited[v]=1;
    k=1;
    while(k<n){
        for(j=n;j>=1;j--){
            if(cost[v][j]!=0&&visited[j]!=1&&visit[j]!=1){
                visit[j]=1;
                stk[top]=j;
                top++;
            }
        }
        v=stk[--top];
        cout<<v<<" ";
        k++;
        visit[v]=0;
        visited[v]=1;
    }
    cout<<"\n\n\n";
    return 0;
}