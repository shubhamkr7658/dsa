class Solution { 
public: 
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) { 
        
        sort(rs.begin(), rs.end());

        int count = 0;
        int j = 0;
        int occupiedRows = 0;

        while (j < rs.size()) {

            int row = rs[j][0];
            occupiedRows++;

            unordered_set<int> seat;

            // collect all reserved seats of this row
            while (j < rs.size() && rs[j][0] == row) {
                seat.insert(rs[j][1]);
                j++;
            }

            int k = 2;

            while (k <= 6) {

                bool possible = true;

                for (int p = 0; p <= 3; p++) {
                    if (seat.find(k + p) != seat.end()) {
                        possible = false;
                        break;
                    }
                }

                if (possible) {
                    count++;
                    k += 2;
                }

                k += 2;
            }
        }

        // Rows which have no reservation
        count += (n - occupiedRows) * 2;

        return count;
    }
};