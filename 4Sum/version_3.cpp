class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& num, int target) {
        sort(num.begin(),num.end());
        vector<vector<int> > ret;
        unordered_map<int,vector<pair<int,int> > > mp;
        unordered_map<int,int> cnt;
        for(unsigned int a=0;a<num.size();){
            for(unsigned int b=a+1;b<num.size();){
                mp[num[a]+num[b]].push_back(pair<int,int> {num[a],num[b]});
                b++;
                while(b<num.size()&&num[b-1]==num[b])    b++;
            }
            a++;
            while(a<num.size()&&num[a-1]==num[a])    a++;
        }
        for(unsigned int a = 0;a<num.size();a++)
            cnt[num[a]]++;


        for(unordered_map<int,vector<pair<int,int> > >::iterator it1=mp.begin();it1!=mp.end();it1++){
            unordered_map<int,vector<pair<int,int> > >::iterator it2=mp.find(target - it1->first);
            if(it2!=mp.end()){
                if(it1->first > it2->first) continue;
                for(int i=0;i<it1->second.size();i++){
                    for(int j=0;j<it2->second.size();j++){
                        int a = it1->second[i].first,b = it1->second[i].second,c = it2->second[j].first,d = it2->second[j].second;
                        if(max(a,b)<=min(c,d)){
                            bool flag = true;
                            cnt[a]--;
                            cnt[b]--;
                            cnt[c]--;
                            cnt[d]--;
                            if(cnt[a]<0||cnt[b]<0||cnt[c]<0||cnt[d]<0)  flag = false;
                            cnt[a]++;
                            cnt[b]++;
                            cnt[c]++;
                            cnt[d]++;
                            if(flag){
                                vector<int> tmp = {a,b,c,d};
                                sort(tmp.begin(),tmp.end());
                                ret.push_back(tmp);
                            }
                        }
                    }
                }
            }
        }
        return ret;
    }
};