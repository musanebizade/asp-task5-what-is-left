#include <iostream>
#include <vector>

using namespace std;

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
            bool removed = false;

            if (step == 0 && position % 2 == 0) {
                removed = true;
            }
            if (step == 1 && position % 2 == 1) {
                removed = true;
            }
            if (step == 2 && position % 3 == 0) {
                removed = true;
            }

            if (!removed) {
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