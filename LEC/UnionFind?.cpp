
// Union Find

/*
6 4
1 4
2 3
2 4
5 6
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int FindParent(vector<int>& parent, int x)
{
    if (parent[x] != x)
        parent[x] = FindParent(parent, parent[x]);

    return x;
}

void UnionParent(vector<int>& parent, int& a, int& b)
{
    a = FindParent(parent, a);
    b = FindParent(parent, b);

    if (a < b) {
        parent[b] = a;
    }else {
        parent[a] = b;
    }
}


int main()
{
    int v, e; cin >> v >> e;    // v : 노드수, e : 간선수
    vector<int> parentTable(v+1);
    iota(parentTable.begin(), parentTable.end(), 0);

    int a, b; cin >> a >> b;
    UnionParent(parentTable, a, b);

    cout << "각 원소의 루트 노드" << endl;
    for (int i = 0; i < v + 1; ++i) {
        cout << FindParent(parentTable, i) << ' ';
    }
    cout << endl;

    cout << "부모 테이블" << endl;
    for (int n : parentTable) {
        cout << n << ' ';
    }

}

