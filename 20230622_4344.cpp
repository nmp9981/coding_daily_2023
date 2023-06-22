#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;//이름공간 선언

const int maxi = 1001;
int arr[maxi];

int main() {
    int t;
    //입력
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        memset(arr, -1, sizeof(arr));//초기화
        int sum = 0;
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
            sum += arr[j];
        }

        //평균
        double av;
        av = (double)sum / (double)n;

        //평균이 넘는 학생들의 비율
        int count = 0;
        for (int k = 0; k < n; k++) {
            if (arr[k] > av) {
                count += 1;
            }
        }
        double result;
        result = 100 * (double)count / (double)n+0.00005;
        //소수점 3째자리까지
        cout << fixed;
        cout.precision(3);
        cout << result << "%" << endl;

    }
    return 0;
}
