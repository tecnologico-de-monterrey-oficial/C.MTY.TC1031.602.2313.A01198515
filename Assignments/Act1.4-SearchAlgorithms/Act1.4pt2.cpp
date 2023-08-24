#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sequentialSearch(const string& str, char target, int& comparisons) {
    int count = 0;
    for (int i = 0; i < str.size(); ++i) {
        ++count;
        if (str[i] == target) {
            comparisons = count;
            return i;
        }
    }
    comparisons = count;
    return -1;
}

int binarySearch(const string& str, char target, int& comparisons) {
    int low = 0;
    int high = str.size() - 1;
    int count = 0;
    while (low <= high) {
        ++count;
        int mid = low + (high - low) / 2;
        if (str[mid] == target) {
            comparisons = count;
            return mid;
        } else if (str[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    comparisons = count;
    return -1;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // Consume newline

    for (int i = 0; i < n; ++i) {
        string str;
        getline(cin, str);

        sort(str.begin(), str.end()); // Ordena el string para que los caracteres duplicados estén juntos

        char uniqueChar = str[0]; // El primer carácter es único

        int seqComparisons, binComparisons;
        int seqIndex = sequentialSearch(str, uniqueChar, seqComparisons);
        int binIndex = binarySearch(str, uniqueChar, binComparisons);

        cout << uniqueChar << " " << seqComparisons << " " << uniqueChar << " " << binComparisons << endl;
    }

    return 0;
}

