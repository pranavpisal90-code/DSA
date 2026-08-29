


                            class Solution {
                            public:
                                int maxArea(vector<int>& heights) {
                                    int j=heights.size()-1;
                                    int max=0;
                                    int area=0;
                                    int small=1;
                                    int i=0;
                                       while(j>i){ 
                                        if(heights[i]>heights[j]){
                                            small=heights[j];
                                            area=(j-i)*small;
                                            j--;
                                        }
                                        else if(heights[i]<heights[j]){
                                            small=heights[i];
                                            area=(j-i)*small;
                                            i++;
                                        }
                                        else{
                                            small=heights[i];
                                            area=(j-i)*small;
                                            i++;
                                        }
                                        if(area>=max){
                                            max=area;
                                        }
                                       
                                    }
                                    return max;
                                }
                            };
