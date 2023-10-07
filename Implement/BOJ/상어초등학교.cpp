// https://jypark1111.tistory.com/164
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1,-1, 0, 0};

typedef struct stu{
    ll s;
    ll stu1;
    ll stu2;
    ll stu3;
    ll stu4;
}stu;


typedef struct point{
    ll x;
    ll y;
}point;

ll findMax(vector<vector<ll> >&possible);
void case1(vector<vector<ll> >&room, stu s);
void case2(vector<vector<ll> >&room, vector<vector<ll> >&possible, stu& s);
void case3(vector<vector<ll> >&room, vector<vector<ll> >&emptyspace, stu& s);

bool indexCheck(point p, ll size){
    if(p.x < 0 || p.x >=size){
        return false;
    }
    if(p.y < 0 || p.y >= size){
        return false;
    }
    return true;
}

bool findpeople(stu s, ll room){
    if (s.stu1 == room)
        return true;
    if (s.stu2 == room)
        return true;
    if (s.stu3 == room)
        return true;
    if (s.stu4 == room)
        return true;
    return false;
}

bool countmax(vector<vector<ll> >&room, vector<vector<ll> >&possible, stu &s)
{
    ll max = findMax(possible);
    ll cnt = 0;
    for(ll i=0; i<possible.size(); i++){
        for(ll j=0; j<possible.size(); j++){
            if(max == possible[i][j])
                cnt++;
            if(cnt > 1)
                return false;
        }
    }
    for(ll i=0; i<possible.size(); i++){
        for(ll j=0; j<possible.size(); j++){
            if(max == possible[i][j])
                room[i][j] = s.s;
        }
    }
    return true;
}
ll findMax(vector<vector<ll> >&possible){
    ll size = possible.size();
    ll i =0;
    ll j =0;
    ll max = 0;
    bool flag = false;
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            if(possible[i][j] != 0){
                flag = false;
                break;
            }   
                
        }
    }

    if(flag) // 모두 0인경우 
    {
        return max;
    }
        

    point p;
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            if(max <= possible[i][j])
                max = possible[i][j];
        }
    }

    return max;
}

void print(vector<vector<ll> >&v, ll size){
    for(ll i=0; i<size; i++){
        for(ll j=0; j<size; j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}
void case1(vector<vector<ll> >&room, stu s){
    point p;
    ll size = room.size();
    vector<vector<ll> >possible(size, vector<ll>(size, 0));
    ll likepeople = 0;
    for(ll i=0; i<size; i++){
        for(ll j=0; j<size; j++){
            likepeople = 0;
            if(room[i][j] == 0){
                for(ll k=0; k<4; k++){
                    p.x = j+ dx[k];
                    p.y = i+ dy[k];
                    if(indexCheck(p, size) == true){
                        if(findpeople(s, room[p.y][p.x]) == true){
                            likepeople ++;
                        }
                            
                    }
                }
                possible[i][j] = likepeople;
            }
        }
    }
    bool check = countmax(room, possible, s);
    if(check == true){ // max가 1개로 바로 삽입가능
        return ;
    }

    // print(possible, size);
    // cout << "===========case1================\n";
    case2(room ,possible, s);
}

void case2(vector<vector<ll> >&room, vector<vector<ll> >&possible, stu& s){
    ll size = room.size();
    ll max = findMax(possible);
    vector<vector<ll> >emptyspace(size, vector<ll>(size, 0));
    ll empMax = 0;
    point p;
    ll emptyplace;
    

    for(ll i=0; i<size; i++){
        for(ll j=0; j<size; j++){
            emptyplace = 0;
            if(max == possible[i][j] and room[i][j] == 0 ){
                emptyplace++;
                for(ll k=0; k<4; k++){
                    p.x = j+ dx[k];
                    p.y = i+ dy[k];
                    if(indexCheck(p, size) == true and room[p.y][p.x] == 0){
                        emptyplace++;
                    }
                }
                emptyspace[i][j] = emptyplace;
            }
        }
    }
    
    bool check = countmax(room, emptyspace, s);
    if(check == true){ // max가 1개로 바로 삽입가능
        return ;
    }

    // print(emptyspace, size);
    // cout << "===========case2================\n";
    case3(room, emptyspace, s);
}

void case3(vector<vector<ll> >&room, vector<vector<ll> >&emptyspace, stu& s){
    ll size = room.size();
    ll max =findMax(emptyspace);
    for(ll i=0; i<size; i++){
        for(ll j=0; j<size; j++){
            if(max == emptyspace[i][j]){
                room[i][j] = s.s;
                return;
            }
                
        }
    }
}
stu findStu(vector<stu>&cls, ll target){
    ll i =0;
    for(i=0; i<cls.size(); i++){
        if(target == cls[i].s)
            break;
    }
    return cls[i];
    
}
ll answer(vector<vector<ll> >&room, vector<stu>&cls)
{
    ll size = room.size();
    ll ans = 0;
    point p ;

    for(ll i=0; i<size; i++){
        for(ll j=0; j<size; j++){
            ll target = room[i][j];
            stu s = findStu(cls, target);
            ll people = 0;
            for(ll k=0; k<4; k++){
                p.x = j + dx[k];
                p.y = i + dy[k];
                if(indexCheck(p, size) == true and findpeople(s, room[p.y][p.x])){
                    people++;
                }
            }
            if(people == 0)
                ans += 0;
            if(people == 1)
                ans += 1;
            if(people == 2)
                ans += 10;
            if(people == 3)
                ans += 100;
            if(people == 4)
                ans += 1000;         
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    ll n = 0;
    cin >> n;
    ll stu_n = n*n;
    vector<stu>cls(stu_n);
    vector<vector<ll> >room(n, vector<ll>(n, 0));

    stu st;

    for(ll i=0; i<stu_n; i++){
        cin >> st.s >> st.stu1 >> st.stu2 >> st.stu3 >> st.stu4;
        cls[i] = st;
    }
   
    for(ll i=0; i<stu_n; i++){
        case1(room, cls[i]);
    }
    // print(room, n);
    ll ans = answer(room, cls);
    cout << ans << "\n";

    return 0;
}