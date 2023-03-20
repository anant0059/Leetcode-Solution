class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0, size = flowerbed.size();
        for(int i=0;i<size;++i){
            if(flowerbed[i]==0){
                int flag1 = 0, flag2 = 0;
                if((i-1>=0 && flowerbed[i-1]==0) || i-1<0) flag1 = 1;
                if((i+1<size && flowerbed[i+1]==0) || i+1>=size) flag2 = 1;
                if(flag1 && flag2){
                    count++;
                    flowerbed[i] = 1;
                }
            }
        }
        return n <= count;
    }
};