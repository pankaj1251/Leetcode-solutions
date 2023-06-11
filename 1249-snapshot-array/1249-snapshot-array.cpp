class SnapshotArray {
public:
    vector<vector<pair<int, int>>>ans;
    int currSnap=0;

    SnapshotArray(int length) {
        ans.resize(length);
    }
    
    void set(int index, int val) {
        if(!ans[index].empty() and ans[index].back().first==currSnap){
            ans[index].back().second=val;
        }
        else{
            ans[index].push_back({currSnap, val});
        }
    }
    
    int snap() {
        currSnap++;
        return currSnap-1;
    }
    
    int get(int index, int snap_id) {
        int idx = upper_bound(ans[index].begin(), ans[index].end(), make_pair(snap_id, INT_MAX)) - ans[index].begin();
        if(idx==0)return 0;

        return ans[index][idx-1].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */