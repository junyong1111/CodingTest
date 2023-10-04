// https://jypark1111.tistory.com/163
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

void preorder(map<char, pair<char, char> >&tree, char node) {//전위순회 루-왼-오
	cout << node; //현재 노드의 데이터 출력
	if (tree[node].first != '.') { //왼쪽 자식이 있다면
		preorder(tree, tree[node].first);
	}
	if (tree[node].second != '.') { //오른쪽 자식이 있다면
		preorder(tree, tree[node].second);
	}
}

void inorder(map<char, pair<char, char> >&tree, char node) {//중위순회 왼-루-오
	if (tree[node].first != '.') { //왼쪽 자식이 있다면
		inorder(tree, tree[node].first);
	}
    cout << node; // 중간 출력
	if (tree[node].second != '.') { //오른쪽 자식이 있다면
		inorder(tree, tree[node].second);
	}
}

void postorder(map<char, pair<char, char> >&tree, char node) {//후위순회 왼-오-루
	if (tree[node].first != '.') { //왼쪽 자식이 있다면
		postorder(tree, tree[node].first);
	}
	if (tree[node].second != '.') { //오른쪽 자식이 있다면
		postorder(tree, tree[node].second);
	}
    cout << node; // 마지막 출력
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    map<char, pair<char, char> >tree;
    ll nodes = 0;
    char node, left, right;
    cin >> nodes;

    for(ll i=0; i<nodes; i++){
        cin >> node >> left >> right;
        tree[node] = make_pair(left, right);
    }
    
    preorder(tree, 'A');
    cout << "\n";
    inorder(tree, 'A');
    cout << "\n";
    postorder(tree, 'A');
    cout << "\n";

    return 0;
}