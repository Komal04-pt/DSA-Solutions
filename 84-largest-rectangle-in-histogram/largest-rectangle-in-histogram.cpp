class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxarea = 0;

        for(int i=0; i<=n; i++){
            int currHeight = (i==n)?0:heights[i];

            while(!st.empty() && heights[st.top()] > currHeight){
                int height = heights[st.top()];
                st.pop();

                int width;
                if(st.empty()){
                    width = i;
                }else{
                    width = i-st.top()-1;
                }

                int area = height*width;
                maxarea = max(area, maxarea);
            }
            st.push(i);
        }
        return maxarea;
    }
};