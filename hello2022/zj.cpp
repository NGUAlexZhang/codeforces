#include <iostream>
#include <cstring>
#include <set>

using namespace std;

const int N = 1e6 + 10;
int arr[N][3];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long ml = 1e11 + 10, mr = 0;
        long long tmp1, tmp2, tmp3 = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
            if (arr[i][0] < ml) {
                ml = arr[i][0];
                tmp1 = i;
            }
            if (arr[i][1] > mr) {
                mr = arr[i][1];
                tmp2 = i;
            }
            if (arr[i][0] == ml) {
                if (arr[i][2] < arr[tmp1][2])tmp1 = i;
            }
            if (arr[i][1] == mr) {
                if (arr[i][2] < arr[tmp2][2]) tmp2 = i;
            }
            if(arr[tmp3][0] == ml && arr[tmp3][1] == mr) {
                if (arr[i][0] == ml && arr[i][1] == mr && arr[i][2] < arr[tmp3][2]) tmp3 = i;
            }
            else if (arr[i][0] == ml && arr[i][1] == mr) tmp3 = i;

            if (arr[tmp3][0] > arr[tmp1][0] || arr[tmp3][1] < arr[tmp2][1]) {
                cout << arr[tmp2][2] + arr[tmp1][2] << endl;
                continue;
            }
            cout << min(arr[tmp3][2], arr[tmp2][2] + arr[tmp1][2]) << endl;
        }

    }
    return 0;
}
