#include <iostream>
using namespace std;

class Solution {
public:
    double power(double a, int e) {
        long long expo = e;

        if (expo < 0) {
            a = 1.0 / a;
            expo = -expo;
        }

        double ans = 1.0;

        while (expo > 0) {
            if (expo % 2 == 1) {
                ans *= a;
                expo--;
            } else {
                a = a * a;
                expo /= 2;
            }
        }

        return ans;
    }
};

int main() {
    double a;
    int e;

    cin >> a >> e;

    Solution obj;
    cout << obj.power(a, e) << endl;

    return 0;
}