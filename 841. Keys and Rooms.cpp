class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,false);
        visited[0]=true;
        stack<int> s;
        s.push(0);
        while(!s.empty()){
            int room = s.top();
            s.pop();
            visited[room]=true;
            for(int i:rooms[room]) if(!visited[i]) s.push(i);
        }
        for(bool b:visited) if(!b) return false;
        return true;
    }
};
