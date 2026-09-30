class Solution {
public:

    int directions[4][2] = {
        {0, 1},
        {0, -1},
        {-1, 0},
        {1, 0}
    };

    struct State {
        int row;
        int col;
        int energyLeft;
        int collectedMask;

        State(int row, int col, int energyLeft, int collectedMask) {
            this->row = row;
            this->col = col;
            this->energyLeft = energyLeft;
            this->collectedMask = collectedMask;
        }
    };

    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int maxEnergy = energy;

        vector<vector<int>> litterBit(m, vector<int>(n, -1));

        int litterCount = 0;
        int startRow = 0;
        int startCol = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (classroom[r][c] == 'S') {
                    startRow = r;
                    startCol = c;
                }
                else if (classroom[r][c] == 'L') {
                    litterBit[r][c] = litterCount;
                    litterCount++;
                }
            }
        }

        if (litterCount == 0)
            return 0;

        int allCollected = (1 << litterCount) - 1;

        vector<vector<vector<vector<bool>>>> seen(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    maxEnergy + 1,
                    vector<bool>(1 << litterCount, false)
                )
            )
        );

        queue<State> q;

        q.push(State(startRow, startCol, maxEnergy, 0));

        seen[startRow][startCol][maxEnergy][0] = true;

        int moves = 0;

        while (!q.empty()) {

            int currSize = q.size();

            while (currSize--) {

                State current = q.front();
                q.pop();

                if (current.collectedMask == allCollected)
                    return moves;

                if (current.energyLeft == 0)
                    continue;

                for (auto& dir : directions) {

                    int nextRow = current.row + dir[0];
                    int nextCol = current.col + dir[1];

                    if (nextRow < 0 || nextRow >= m ||
                        nextCol < 0 || nextCol >= n)
                        continue;

                    if (classroom[nextRow][nextCol] == 'X')
                        continue;

                    int nextEnergy = current.energyLeft - 1;
                    int nextMask = current.collectedMask;

                    char cell = classroom[nextRow][nextCol];

                    if (cell == 'R') {
                        nextEnergy = maxEnergy;
                    }
                    else if (cell == 'L') {
                        nextMask |= (1 << litterBit[nextRow][nextCol]);
                    }

                    if (!seen[nextRow][nextCol][nextEnergy][nextMask]) {

                        seen[nextRow][nextCol][nextEnergy][nextMask] = true;

                        q.push(
                            State(
                                nextRow,
                                nextCol,
                                nextEnergy,
                                nextMask
                            )
                        );
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};