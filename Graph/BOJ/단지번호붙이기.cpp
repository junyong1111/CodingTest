// https://jypark1111.tistory.com/112

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;
typedef struct point{
	ll x;
	ll y;
}point;

ll dx[4] = {0, 0, 1, -1}; // 상, 하, 좌, 우 
ll dy[4] = {1, -1, 0, 0}; // 상, 하, 좌, 우

bool indexCheck(point p, ll n){
	if(p.x < 0 || p.x >= n) 
		return false;
	if(p.y < 0 || p.y >= n)
		return false;
	return true;
}

void dfs(vector<vector<ll> >&map, point p, ll n, ll *cnt)
{
	point new_p; 
	*cnt = *cnt + 1; // 집 갯수 1개 증가
	map[p.y][p.x] = 0; // 탐색된 집 삭제
	for(ll i=0; i<n; i++){ // 연결된 집 탐색(상, 하, 좌, 우)
		new_p.x = p.x + dx[i]; 
		new_p.y = p.y + dy[i];
		if((indexCheck(new_p, n) == true) and map[new_p.y][new_p.x] == 1){ // 해당위치가 map을 벗어나지 않았으며 집이 있는 경우(연결된 경우)
			dfs(map, new_p, n, cnt); // 연결된 집 탐색
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// freopen("input.txt", "r" ,stdin);

	ll n = 0;
	string str;
	cin >> n;

	vector<vector<ll> >map(n, vector<ll>(n, 0));
	for(ll i=0; i<n; i++){
		cin >> str;
		for(ll j=0; j<n; j++){
			map[i][j] = str[j] - 48; 
		}
	}

	ll number = 0; // 총 단지 갯수를 세기 위한 변수
	vector<ll>answer; // 각각의 단지의 집의 갯수를 저장할 vector
	point p;
	for(ll i=0; i<n; i++){
		for(ll j=0; j<n; j++){ // 모든 map 탐색 
			if(map[i][j] == 1){ // 만약 집이 있다면 
				ll cnt = 0; // 집의 갯수를 counting 하기 위한 변수 
				p.x = j;
				p.y = i;  //지도에서 현재 집의 위치를 저장
				dfs(map, p, n, &cnt); // 연결된 집 탐색
				answer.push_back(cnt);
				number ++;
			}
		}
	}

	sort(answer.begin(), answer.end());

	cout << number << "\n";
	for(auto a : answer){
		cout << a << "\n";
	}
	return 0;
}