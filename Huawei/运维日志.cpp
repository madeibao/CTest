
#include<bits/stdc++.h>
using namespace std;
string s[100000 + 5];

bool cmp(const pair<string, string> a, pair<string, string>b) {
    return a.second < b.second;
}

int main() {
    map<string, string>m;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        string xs = s[i];
        s[i] += '.';

        int time = 0;
        string ss;
        string sum;
        for (int j = 0; j < s[i].size(); j++) {

            if (s[i][j] != ':' && s[i][j] != '.') {
                ss += s[i][j];
                continue;
            }
            if (time == 0) {
                for (int x = 0; x < 2 - ss.length(); x++) {
                    sum += "0";
                }
                sum += ss + ":";
            }
            if (time == 1) {
                for (int x = 0; x < 2 - ss.length(); x++) {
                    sum += "0";
                }
                sum += ss + ":";
            }
            if (time == 2) {
                for (int x = 0; x < 2 - ss.length(); x++) {
                    sum += "0";
                }
                sum += ss + ":";
            }
            if (time == 3) {
                for (int x = 0; x < 3 - ss.length(); x++) {
                    sum += "0";
                }
                sum += ss;
            }
            time++;
            ss.clear();
        }
        m[xs] = sum;
    }

    vector<pair<string, string>>v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    map<string, string>::iterator it;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << endl;
    }

    return 0;
}
