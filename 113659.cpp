#include <iostream>
#include <vector>
#include <map>

using namespace std;

int visit(map<int, vector<int>> &a, int k);

int visit(map<int, vector<int>> &a, int k) {
    int count = 1;
    if (a.find(k) == a.end()) {
        return count;
    }

    for (int i = 0; i < (int) a[k].size(); ++i) {
        count += visit(a, a[k][i]);
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n;
    map<int, vector<int>> a;
    for (int i = 0; i < n; ++i) {
        int num;
        int parent;
        cin >> num >> parent;
        if (parent == 0) {
            continue;
        }
        a[parent].push_back(num);
    }
    cin >> k;
    cout << visit(a, k) << endl;

    return 0;
}
