#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    string s;
    vector<int> v(26);

    cin >> s;

    for(auto i : s)
        v[i-'a']++;

    for(auto i : v)
        cout << i << " ";

    return 0;
}