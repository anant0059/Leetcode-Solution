class Solution {
public:
    void fill(vector<vector<int>> &image, int i, int j, int &color, int &pixel){
        //cout<<i<<" "<<j<<" "<<image[i][j]<<" "<<pixel<<endl;
        if(i<0 || i>=image.size() || j<0 || j>=image[0].size() || image[i][j]!=pixel) return;
        //cout<<i<<" "<<j<<endl;
        image[i][j]=color;
        fill(image, i+1, j, color, pixel);
        fill(image, i-1, j, color, pixel);
        fill(image, i, j+1, color, pixel);
        fill(image, i, j-1, color, pixel);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        int pixel=image[sr][sc];
        fill(image, sr, sc, color, pixel);
        return image;
    }
};