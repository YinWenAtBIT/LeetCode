class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(numCourses<2)
            return true;
        
        vector<int> indegree(numCourses, 0);
        queue<int> que;
        int len = prerequisites.size();
        
        for(int i=0; i<len; i++)
        {
            int num = prerequisites[i].first;
            indegree[num]++;
        }
        
        int count =0;
        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i] ==0)
                que.push(i);
        }
        
        while(!que.empty())
        {
            int num = que.front();
            que.pop();
            count++;
            for(int i=0; i<len; i++)
            {
                if(prerequisites[i].second == num)
                {
                    int next = prerequisites[i].first;
                    indegree[next]--;
                    if(indegree[next] == 0)
                        que.push(next);
                }
                    
            }
        }
        
        return count == numCourses;
        
    }
};