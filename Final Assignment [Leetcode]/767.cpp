class Solution {
public:
    string reorganizeString(string s) {
                vector<int> cnt(26,0);
        for(char c: s) cnt[c-'a']++;
        priority_queue<pair<int,char>> pq;
        for(int i=0;i<26;i++) if(cnt[i]) pq.push({cnt[i], char('a'+i)});
        string res;
        while(pq.size() > 1){
            auto p1 = pq.top(); pq.pop();
            auto p2 = pq.top(); pq.pop();
            res.push_back(p1.second);
            res.push_back(p2.second);
            if(--p1.first > 0) pq.push(p1);
            if(--p2.first > 0) pq.push(p2);
        }
        if(!pq.empty()){
            if(pq.top().first > 1) return "";
            res.push_back(pq.top().second);
        }
        return res;
    }
};