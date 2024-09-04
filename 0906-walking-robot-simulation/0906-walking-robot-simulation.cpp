class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> st;
        for (int i = 0; i < obstacles.size(); i++) {
            st.insert({obstacles[i][0], obstacles[i][1]});
        }
        int x = 0;
        int y = 0;
        int direction = 0;
        int eq_distance=INT_MIN;
        int value=0;
        vector<string>dir = { "north", "east", "south", "west" };
        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] == -1) {
                direction = (direction + 1) % 4;

            } else if (commands[i] == -2) {
                direction = (direction - 1 + 4) % 4;
            } else {
                if (dir[direction] == "north") {
                    for (int j = 1; j <= commands[i]; j++) {
                        if (st.find({x, y + 1}) == st.end()) {
                            y = y + 1;
                        } else {
                            break;
                        }
                    }
                     value=pow(x,2)+pow(y,2);
                     eq_distance=max(eq_distance,value);
                     
                } else if (dir[direction] == "east") {
                    for (int j = 1; j <= commands[i]; j++) {
                        if (st.find({x + 1, y}) == st.end()) {
                            x = x + 1;
                        } else {
                            break;
                        }
                    }
                     value=pow(x,2)+pow(y,2);
                     eq_distance=max(eq_distance,value);

                } else if (dir[direction] == "west") {
                    for (int j = 1; j <= commands[i]; j++) {
                        if (st.find({x - 1, y}) == st.end()) {
                            x = x - 1;
                        } else {
                            break;
                        }
                    }
                    value=pow(x,2)+pow(y,2);
                    eq_distance=max(eq_distance,value);
                } else {
                    for (int j = 1; j <= commands[i]; j++) {
                        if (st.find({x, y - 1}) == st.end()) {
                            y = y - 1;
                        } else {
                            break;
                        }
                    }
                     value=pow(x,2)+pow(y,2);
                     eq_distance=max(eq_distance,value);
                }
            }
        }
        
        return eq_distance;
    }
};