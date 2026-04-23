class Solution {
public:
    vector<int> getPSE(vector<int>& heights){

        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i=0; i<n; i++){

            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            ans[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
        return ans;
    }
    vector<int> getNSE(vector<int>& heights){

        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--){

            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            ans[i] = st.empty() ? n : st.top();

            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights){

        int n = heights.size();

        vector<int> pse = getPSE(heights);
        vector<int> nse = getNSE(heights);

        int largestArea = 0;
        int area;

        for(int i=0; i<n; i++){

            area = heights[i] * (nse[i] - pse[i] - 1);
            largestArea = max(area, largestArea);
        }
        return largestArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int m = matrix.size(); // rows
        int n = matrix[0].size(); // columns

        vector<int> heights(n,0);
        int maxArea = 0;

        for(int i=0; i<m; i++){

            for(int j=0; j<n; j++){
                if(matrix[i][j] == '0')
                    heights[j] = 0;
                else
                    heights[j]++;
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
};