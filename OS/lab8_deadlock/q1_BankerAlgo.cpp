#include <iostream>
using namespace std;

int n, m;

// Safety check
bool isSafe(int avail[], int max[][10], int alloc[][10]) {
    int need[10][10], work[10], finish[10] = {0}, safe[10];

    // Need = Max - Allocation
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Work = Available
    for (int j = 0; j < m; j++) work[j] = avail[j];

    int count = 0;
    while (count < n) {
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < m; j++)
                    if (need[i][j] > work[j]) break;

                if (j == m) { // can execute
                    for (int k = 0; k < m; k++)
                        work[k] += alloc[i][k];

                    safe[count++] = i;
                    finish[i] = 1;
                    found = true;
                }
            }
        }

        if (!found) return cout << "Not Safe\n", false;
    }

    cout << "Safe sequence: ";
    for (int i = 0; i < n; i++) cout << "P" << safe[i] << " ";
    cout << "\n";
    return true;
}

// Resource request
void request(int avail[], int max[][10], int alloc[][10], int p) {
    int req[10], need[10][10];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    cout << "Enter request: ";
    for (int j = 0; j < m; j++) cin >> req[j];

    // Check validity
    for (int j = 0; j < m; j++) {
        if (req[j] > need[p][j]) return void(cout << "Exceeds need\n");
        if (req[j] > avail[j]) return void(cout << "Not available\n");
    }

    // Pretend allocation
    for (int j = 0; j < m; j++) {
        avail[j] -= req[j];
        alloc[p][j] += req[j];
    }

    // Safety check
    if (isSafe(avail, max, alloc))
        cout << "Request granted\n";
    else {
        cout << "Request denied\n";
        for (int j = 0; j < m; j++) { // rollback
            avail[j] += req[j];
            alloc[p][j] -= req[j];
        }
    }
}

int main() {
    int avail[10], max[10][10], alloc[10][10];

    cin >> n >> m;

    for (int j = 0; j < m; j++) cin >> avail[j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> max[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> alloc[i][j];

    isSafe(avail, max, alloc);

    int p; cin >> p;
    request(avail, max, alloc, p);
}