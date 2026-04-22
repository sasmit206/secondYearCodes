void fcfs(vector<int>req,int head){
    for(int i=0;i<req.size();i++){
        cost+=abs(head-req[i]);
        cout<<head<<"->";
        head=req[i];
    }
}

void sstf(vector<int> req, int head){
    vector<bool> vis(req.size(), false);
    int cost = 0;

    for(int i=0;i<req.size();i++){
        int mind = INT_MAX;
        int idx = -1;

        for(int j=0;j<req.size();j++){
            if(!vis[j]){   // ✅ important
                int dist = abs(req[j] - head);
                if(dist < mind){
                    mind = dist;
                    idx = j;
                }
            }
        }

        cout << head << " -> ";
        cost += abs(head - req[idx]);
        head = req[idx];
        vis[idx] = true;   // ✅ correct
    }

    cout << head << endl;
    cout << "Total Seek Time: " << cost << endl;
}

void clook(vector<int> req, int head){
    // sort(req.begin(),r.end());
    int i;
    // while(i<req.size()&&req[i]<head){
        i++;
    }
    for(int j=i-1;j>0;j--){
        cost+=abs(req[j]-head);
        head=req[j];
    }
    head=req[req.size()-1];
    for(int j=req.size()-1;j>=i;j--){
        cost+=abs(req[j]-head);
        head=req[j];
    }
}