// class Solution {
// public:
//     std::vector<int> getRow(int rowIndex) {
//         std::vector<int> res(1, 1);
//         long long prev = 1;
//         for(int k = 1; k <= rowIndex; k++) {
//             long long next_val = prev * (rowIndex - k + 1) / k;
//             res.push_back(next_val);
//             prev = next_val;
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(1, 1);

        for (int i = 0; i < rowIndex; i++) {
            vector<int> newRow;
            newRow.push_back(1);
            for (int j = 1; j < row.size(); j++) {
                newRow.push_back(row[j - 1] + row[j]);
            }
            newRow.push_back(1);
            row = newRow;
        }

        return row;        
    }
};

