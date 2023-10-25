class Solution {
public:
    int kthGrammar(int n, int k) {
        // Initialize a flag to track if the values of k and first element are the same.
        bool areValuesSame = true; 

        // Calculate the total number of elements in the nth row, which is 2^(n-1).
        n = pow(2, n - 1);

        // Continue until we reach the first row.
        while (n != 1) {
            // Halve the number of elements in the row.
            n /= 2;

            // If k is in the second half of the row, adjust k and toggle the flag.
            if (k > n) {
                k -= n;
                areValuesSame = !areValuesSame;
            }
        }

        // Return 0 if the flag indicates that the values are the same; otherwise, return 1.
        return ((areValuesSame) ? 0 : 1) ;
    }
};

// class Solution {
// public:
//     int kthGrammar(int n, int k) {
//         if (n == 1) {
//             return 0;
//         }

//         if (k % 2 == 0) {
//             return kthGrammar(n - 1, k / 2) == 0 ? 1 : 0;
//         } else {
//             return kthGrammar(n - 1, (k + 1) / 2) == 0 ? 0 : 1;
//         }
//     }
// };