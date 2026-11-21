#include <iostream>
#include <vector>

using namespace std;

bool keep(int step, int position) {
    if (step == 0) {
        return position % 2 == 1;
    }
    if (step == 1) {
        return position % 2 == 0;
    }
    return position % 3 != 0;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    int size = n;
    int step = 0;

    while (size > 1) {
        int newSize = 0;
        for (int i = 0; i < size; i++) {
            int position = i + 1;
            if (keep(step, position)) {
                a[newSize] = a[i];
                newSize++;
            }
        }
        size = newSize;
        step = (step + 1) % 3;
    }

    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}