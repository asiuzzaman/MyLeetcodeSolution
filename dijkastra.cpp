#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MXN 3003

//  cost, dest  source
vector< pair<int,int> > graph[MXN];
int dist[MXN];
int visited[MXN];

void initSetup(){

    for(int i=0; i<MXN; i++){
        dist[i] = 1e9;
        visited[i] = 0;
    }
}

int main(){

    int testCase;
    //cin>>testCase;
    initSetup();
    int node,edge;
    cin>>node;
    cin>>edge;
    for(int i=0; i<edge;i++) {
        int s,d,w;
        cin>>s>>d>>w;
        graph[s].push_back(make_pair(w,d));
        graph[d].push_back(make_pair(w,s));
    }
    int startingPosition;
    cin>>startingPosition;

    /// now dijkastra

    // take multiset as min heap

    multiset<pair<int,int> > minHeap;
    dist[startingPosition] = 0;
    visited[startingPosition] = 1;
    pair<int,int> t;
    t.first = 0;
    t.second = startingPosition;
    minHeap.insert(t);

    while(!minHeap.empty()) {
        auto front = minHeap.begin();
        minHeap.erase(minHeap.begin());
        int u = front->second;
        //int uw = front->first;

        for(int i=0; i<graph[front->second].size(); i++){
            int v = graph[front->second][i].second;
            int wei = graph[front->second][i].first;

            if(dist[v]> wei + dist[front->second] && visited[v] == 0 ) {
                dist[v] = wei + dist[front->second];
                minHeap.insert(make_pair(dist[v],v));
                visited[v] = 1;
            }

        }
    }


    for(int i=0; i<=node; i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;


}