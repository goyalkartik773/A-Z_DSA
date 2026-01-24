#include <bits/stdc++.h>

// User ke preferences ke anusaar, using namespace std.
using namespace std;

// Yeh function Poby aur Rekkles ke game ko simulate karta hai
// ek single number ke liye, jaisa aapke code me tha.
// Poby divide karta hai, Rekkles add karta hai.
int calculate_game_turns(long long initial_val) {
    int turn_count = 0;
    long long current_val = initial_val;

    // Loop tab tak chalega jab tak value itni choti na ho jaye
    // ki Poby ka agla move use 1 bana de.
    while (current_val >= 4) {
        turn_count++;
        // Poby's move and Rekkles's immediate response
        current_val = current_val / 2 + 1;
    }

    // Final move by Poby jo value ko 1 bana dega.
    if (current_val > 1) {
        turn_count++;
    }

    return turn_count;
}

// Yeh function check karta hai ki kya number (2^k) form ka hai.
// Aapke code me yeh val-1 ke liye tha, yahan thoda alag style me likha hai.
bool needs_correction(long long val) {
    if (val < 3) {
        return false;
    }
    long long n_minus_1 = val - 1;
    // Bitwise trick to check if a number is a power of two.
    return (n_minus_1 > 0) && ((n_minus_1 & (n_minus_1 - 1)) == 0);
}

// Har test case ke liye main logic.
void solve() {
    int n, q;
    cin >> n >> q;

    // 0-based indexing ka istemal karenge.
    vector<long long> initial_array(n);
    for (int i = 0; i < n; ++i) {
        cin >> initial_array[i];
    }

    // --- Precomputation Step ---
    // Yahan hum base turns aur correction flags ko precompute kar rahe hain.
    vector<int> base_turns(n);
    vector<int> correction_flags(n);
    for (int i = 0; i < n; ++i) {
        base_turns[i] = calculate_game_turns(initial_array[i]);
        correction_flags[i] = needs_correction(initial_array[i]);
    }

    // Ab in values ke liye prefix sums banayenge.
    // Prefix sum arrays ka size n+1 hota hai for easier calculation.
    vector<long long> turns_psa(n + 1, 0);
    vector<int> flags_psa(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        turns_psa[i + 1] = turns_psa[i] + base_turns[i];
        flags_psa[i + 1] = flags_psa[i] + correction_flags[i];
    }

    // --- Query Processing Step ---
    // Sab queries ka jawab denge.
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;

        // Query ke 1-based indices se range sum nikalenge.
        // For range [l, r], we need sum from index l-1 to r-1.
        // Using 1-indexed prefix sums, this is psa[r] - psa[l-1].
        long long total_base_turns = turns_psa[r] - turns_psa[l - 1];
        int total_flags = flags_psa[r] - flags_psa[l - 1];

        // Aapke code wala final formula.
        long long final_answer = total_base_turns + total_flags / 2;
        cout << final_answer << "\n";
    }
}

int main() {
    // Input/Output ko fast karne ke liye.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
