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
    int newSize = 0;
    for (int i = 0; i < size; i++) {
        int position = i + 1;
        if (position % 2 == 1) {
            a[newSize] = a[i];
            newSize++;
        }
    }
    size = newSize;

    newSize = 0;
    for (int i = 0; i < size; i++) {
        int position = i + 1;
        if (position % 2 == 0) {
            a[newSize] = a[i];
            newSize++;
        }
    }
    size = newSize;

    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}