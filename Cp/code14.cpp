#include <bits/stdc++.h>

using namespace std;

void solve() {}

int main() {
    // Input/Output ko fast karne ke liye.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        // Yeh do flags check karenge ki odd aur even positions par
        // strength '1' wala banda mila ya nahi.
        bool odd_pos_has_one = false;
        bool even_pos_has_one = false;

        // Chalo sab logon ki strength line se check karte hain.
        for (int i = 1; i <= n; ++i) {
            int strength;
            cin >> strength;

            // Humein sirf strength '1' walon se matlab hai,
            // kyunki wahi game changers hain.
            if (strength == 1) {

                // Position 'i' odd hai ya even, yeh check karo.
                if (i % 2 != 0) {
                    // Odd position
                    odd_pos_has_one = true;
                } else {
                    // Even position
                    even_pos_has_one = true;
                }
            }
        }

        // Ab final check ka time hai.
        if (odd_pos_has_one && even_pos_has_one) {
            // Agar dono odd aur even groups mein '1' wala banda hai,
            // toh sab log connected hain. Koi unreachable nahi hai.
            cout << "No\n";
        } else {
            // Warna, koi na koi group isolated hai.
            // Matlab ek unreachable pair exist karta hai.
            cout << "Yes\n";
        }
    }
    return 0;
}
