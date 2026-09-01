

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int startX = -1, startY = -1;
        vector<pair<int, int>> litter;
        
        // Find 'S' and index all 'L' positions
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    startX = i;
                    startY = j;
                } else if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }
        
        int totalLitter = litter.size();
        int targetMask = (1 << totalLitter) - 1;
        
        // Map (r, c) of each litter to its bit index
        auto getLitterIndex = [&](int r, int c) {
            for (int i = 0; i < totalLitter; ++i) {
                if (litter[i].first == r && litter[i].second == c) {
                    return i;
                }
            }
            return -1;
        };
        
        // Check initial state if start is on a litter
        int initialMask = 0;
        int initIdx = getLitterIndex(startX, startY);
        if (initIdx != -1) {
            initialMask |= (1 << initIdx);
        }
        
        if (initialMask == targetMask) return 0;

        // Queue stores: {x, y, bitmask, energy_remaining}
        queue<tuple<int, int, int, int>> q;
        q.push({startX, startY, initialMask, energy});
        
        // bestEnergy[x][y][mask] stores the max remaining energy seen so far for that state
        vector<vector<vector<int>>> bestEnergy(m, vector<vector<int>>(n, vector<int>(1 << totalLitter, -1)));
        bestEnergy[startX][startY][initialMask] = energy;
        
        int steps = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c, mask, e] = q.front();
                q.pop();
                
                if (mask == targetMask) return steps;
                if (e == 0) continue; // Out of energy, cannot move further from here
                
                for (auto& d : dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];
                    
                    // Boundary check and obstacle check
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || classroom[nr][nc] == 'X') {
                        continue;
                    }
                    
                    int nextEnergy = e - 1;
                    int nextMask = mask;
                    
                    // Reset energy if stepping onto 'R'
                    if (classroom[nr][nc] == 'R') {
                        nextEnergy = energy;
                    } 
                    // Collect litter if stepping onto 'L'
                    else if (classroom[nr][nc] == 'L') {
                        int idx = getLitterIndex(nr, nc);
                        if (idx != -1) {
                            nextMask |= (1 << idx);
                        }
                    }
                    
                    // Pruning: process state only if we arrive with strictly higher energy
                    if (nextEnergy > bestEnergy[nr][nc][nextMask]) {
                        bestEnergy[nr][nc][nextMask] = nextEnergy;
                        q.push({nr, nc, nextMask, nextEnergy});
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};