#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 11

using namespace std;

typedef pair<int, int> pl;

void dijkstra(vector<vector<int> >&graph, vector<int>&dist, vector<bool>&visit, int node){
    priority_queue<pl, vector<pl>, greater<pl> > pq; // pair로 우선순위큐 사용 시 앞에 인자를 기준으로 내림차순 정렬이며 기본은 맥스힙이고 greater를 통해 민힙 구조 사용가능
    dist[node] = 0;
    
    pq.push(make_pair(graph[node][node], node));
    
    while(!pq.empty()){
        int temp_node = pq.top().second; // 가중치가 제일 작은 node 가져옴
        pq.pop();
        visit[temp_node] = true; // 미리 해버리면 최단경로 갱신에서 오류 생김
        for(int i=1; i<=graph.size()-1; i++){
            
            if(graph[temp_node][i] != -1 && visit[i] == false){ //연결된 노드가 방문이 가능하면
                if(dist[i] > dist[temp_node] + graph[temp_node][i]){ // 현재 경로가 최단인 경우
                    dist[i] = dist[temp_node] + graph[temp_node][i]; // 갱신
                    pq.push(make_pair(graph[temp_node][i], i));
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    int vertex = 0;
    int edge = 0;
    int start_node = 0;
    cin >> vertex >> edge >> start_node;
    vector<vector<int> >graph(vertex+1, vector<int>(vertex+1, -1)); // 0은 제외
    vector<int>dist(vertex+1, INF);
    vector<bool>visit(vertex+1, false);
    
    int v1, v2, w;

    for(int i=0; i<edge; i++){
        cin >> v1 >> v2 >> w;
        graph[v1][v2] = w;
    } // 그래프 생성
     
    dijkstra(graph, dist, visit, start_node); // 다익스트라 탐색 시작
    for(int i=1; i<=vertex; i++){ // INF가 아닌 경우만 출력
        if(dist[i] != INF)
            cout << dist[i] << "\n";
        else
            cout << "INF" << "\n";
    }

    return 0;
}