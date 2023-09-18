// https://jypark1111.tistory.com/manage/posts/

#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
#define MAXSIZE 20001

using namespace std;

typedef pair<int, int> pi;
vector<pi> node[MAXSIZE];
vector<int>dist(MAXSIZE, INF);

void dijkstra(int start){
    priority_queue<pi, vector<pi>, greater<pi> > pq; // pair로 우선순위큐 사용 시 앞에 인자를 기준으로 내림차순 정렬이며 기본은 맥스힙이고 greater를 통해 민힙 구조 사용가능
    
    dist[start] = 0;
    pq.push(make_pair(dist[start], start));
    
    while(!pq.empty()){
        int cost = pq.top().first; 
        int curr = pq.top().second; // 가중치가 제일 작은 src 가져옴
        pq.pop();
        if(dist[curr] < cost) // 이미 최단경로가 맞다면 진행 불필요
            continue;
        
        for(int i=0; i<node[curr].size(); i++){
            int nnode = node[curr][i].first;
            int ncost = node[curr][i].second;
             
            if(dist[nnode] > cost + ncost){ // 현재 경로가 최단인 경우
                dist[nnode] = cost + ncost; // 갱신
                pq.push(make_pair(dist[nnode], nnode));
            }
        }
    }
}

void print(int vertex){
    for(int i=1; i<=vertex; i++){
            cout << " i value is : " << i <<"\n";
            for(int j=0; j<node[i].size(); j++){
                cout << "연결된 노드 is : " << node[i][j].first << "  가중치 is : " << node[i][j].second << "\n";
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
    
    int v1, v2, w;

    for(int i=0; i<edge; i++){
        cin >> v1 >> v2 >> w;
        node[v1].push_back(make_pair(v2,w));
    } // 그래프 생성

    // print(vertex);
    
    
    dijkstra(start_node); // 다익스트라 탐색 시작
    for(int i=1; i<=vertex; i++){ // INF가 아닌 경우만 출력
        if(dist[i] != INF)
            cout << dist[i] << "\n";
        else
            cout << "INF" << "\n";
    }

    return 0;
}