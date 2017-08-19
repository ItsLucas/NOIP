#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

priority_queue<string, vector<string>, greater<string> > q;

int n;
string str, T, top;

int main() {
    freopen("words.in", "r", stdin);
    freopen("words.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        q.push(str);
    }
    cin >> T;
    while (!q.empty()) {
        top = q.top();
        if (!top.find(T))
            cout << top << endl;
        q.pop();
    }
    return 0;
}
