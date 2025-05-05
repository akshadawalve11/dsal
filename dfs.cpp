#include<iostream>
using namespace std;
int G[10][10],visited[10],n;

void dfs(int i){
    cout<<"\n"<<i;
    visited[i]=1;
    for(int j=0;j<n;j++){
        if(!visited[j]&&G[i][j]==1){
            dfs(j);
        }
    }
}
int main(){
    int i,j;
    cout<<"Enter number of vertices:";
    cin>>n;
    cout<<"Enter adjacency matrix of graph:\n";
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>G[i][j];        }
    }
    for(i=0;i<n;i++){
        visited[i]=0;
    }
    dfs(0);
    return 0;
}