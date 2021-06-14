#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
//#include<cstdint>
using namespace std;

void MakeStep(int &u1, int &u2, int &w1, int &w2, int t, int d, int u, int w) {
    u1 = max(u1 - t, u - d);
    w1 = max(w1 - t, w - d);
    u2 = min(u2 + t, u + d);
    w2 = min(w2 + t, w + d);
}

void PrintResult(int u1, int u2, int w1, int w2) {
    int i = 0;
    for (int u = u1; u <= u2; u++) {
        for (int w = w1; w <= w2; w++) {
            if ((u + w) % 2 == 0) {
                i += 1;
            }
        }
    }
    cout << i << endl;
    for (int u = u1; u <= u2; u++) {
        for (int w = w1; w <= w2; w++) {
            if ((u + w) % 2 == 0) {
                cout << (u + w) / 2 << " "s << (u - w) / 2 << endl;
            }
        }
    }
}

int main() {
    int t, d, n;
    cin >> t >> d >> n;
    int x0 = 0;
    int y0 = 0;
    int x, y;
    int u1 = 0, u2 = 0, w1 = 0, w2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        int u = x + y;
        int w = x - y;
        MakeStep(u1, u2, w1, w2, t, d, u, w);
    }
    PrintResult(u1, u2, w1, w2);

    return 0;
}
