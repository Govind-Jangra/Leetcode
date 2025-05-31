class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
     
        int t = n * n;
        map<int, int> ladder;
        map<int, int> snake;
        bool flag=0;
        if(n%2) flag=1;
        for (int i = 0; i < n; i++) {
            if(flag==0)
            for (int j = 0; j < n; j++) {
                if (board[i][j] != -1) {
                    if (board[i][j] > t)
                        ladder[t] = board[i][j];
                    else if(board[i][j] < t) 
                        snake[t] = board[i][j];
                }
                t--;
            }

            else 
             for (int j = n-1; j >=0; j--) {
                if (board[i][j] != -1) {
                    if (board[i][j] > t)
                        ladder[t] = board[i][j];
                    else if(board[i][j]<t) 
                        snake[t] = board[i][j];
                }
                t--;
            }

            flag=!flag;
            
        }
        
        vector<int> vis(n * n + 3, 0);
        int ans = 0;
        queue<int> q;
        q.push(1);
        vis[1] = 1;
        bool found = false;
        while (!q.empty() && found == false) {
            int size = q.size();
            while (size--) {
                int temp = q.front();
                q.pop();
                if (temp == n * n) {
                    return ans;
                }
                for (int move = 1; move <= 6; move++) {
                    int turn = move + temp;
                    if (turn == n * n) {
                        found = true;
                        break;
                    }
                    if (turn < n * n && ladder[turn] && vis[ladder[turn]] == 0 ) {
                        vis[ladder[turn]] = 1;
                        q.push(ladder[turn]);
                    } else if (turn < n * n && snake[turn] &&  vis[snake[turn]] == 0 ) {
                        vis[snake[turn]] = 1;
                        q.push(snake[turn]);
                    } else if (turn < n * n && vis[turn] == 0 && !snake[turn] && !ladder[turn]) {
                        vis[turn] = 1;
                        q.push(turn);
                    }
                }
            }
            ans++;
        }
        if(found) return ans;
        return -1;
    }
};
