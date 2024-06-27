class Solution {
public:
void floodFillHelper(vector<vector<int>>&image, int sr, int sc, int color, int initialColor)
{
    // return if we reach out of bound indexes to avoid out of bounds
    // exceptions, do nothing if the current cell's value is 0; 
    //cannot manipulate it or its neighbors
    if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] != initialColor || image[sr][sc] == color) 
    {
        return; 
    }

    // change the current cells color then, in 4-directionally order: 
    // up -> down -> left -> right 
    image[sr][sc] = color;
    floodFillHelper(image, sr - 1, sc, color, initialColor);
    floodFillHelper(image, sr + 1, sc, color, initialColor);
    floodFillHelper(image, sr, sc - 1, color, initialColor);
    floodFillHelper(image, sr, sc + 1, color, initialColor);
}

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    // problem breakdown: 
    // given initial root, perform a flood fill within the root's 
    // 4-directionally connected pixels. Then perform this flood fill with
    // the connected proxies (using recursion)
    // - pixels cannot be painted if they are already 0 BUT can be
    //  painted 0
    // - sr = rows, sc = columns, i = sr, j = sc

    // possible solution: 
    // start at the root, then use recursion to expand outwards, however, 
    // uncertain if the order/direction matters? up, down, left, right
    // up: [sr - 1] [sc]
    // down: [sr + 1] [sc]
    // left: [sr] [sc - 1]
    // right: [sr] [sc + 1]

    int initialColor = image[sr][sc]; 
    floodFillHelper(image, sr, sc, color, initialColor);
    return image; 
}
};
