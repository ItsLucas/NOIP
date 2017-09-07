#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

set<int> v;

int main() {
    // srand(time(NULL));
    for (int i = 1; i <= 1000000; i++) {
        v.insert(rand());
    }
    return 0;
}
