 int largestRectangleArea(vector<int>& heights) 
    {
        heights.push_back(0);
        int n = heights.size();
        int area = 0;
        stack<int> idx;
        
        for(int i = 0; i < n; i++)
        {
            while(!idx.empty() && heights[idx.top()] > heights[i])
            {
                int h = heights[idx.top()];
                idx.pop();
                int l = idx.empty() ? -1 : idx.top();
                area = max(area, h * (i-l-1));
            }
            idx.push(i);
        }
        return area;
    }
    /*********************************************************/
    vector<int> nextsmaller(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
    int num = arr[i];
        while(s.top()!=-1 && arr[s.top()]>=num){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
    vector<int> prevsmaller(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int>ans(n);
    for(int i=0;i<n;i++){
    int num = arr[i];
        while(s.top()!=-1 && arr[s.top()]>=num){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
    int largestRectangleArea(vector<int>& heights) {
       
        int n=heights.size();
        vector<int> next(n);
        vector<int>prev(n);
        next=nextsmaller(heights,n);
        prev=prevsmaller(heights,n);
        int area=INT_MIN;
        for(int i=n-1;i>=0;i--){
        
         int l=heights[i];
            
            if(next[i]==-1){
                    next[i]=n;}
            int b=next[i]-prev[i]-1;
            int newarea=l*b;
            
            area=max(area,newarea);
        }
       return area; 
    }