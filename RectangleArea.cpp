#include <iostream>
using namespace std;

class Solution{
    public:
        int computeArea(int A, int B, int C, int D, int E, int F, int G, int H){

            int s = (C-A)*(D-B)+(G-E)*(H-F);
            
            int x1 = A >= E ? A : E;
            int x2 = C <= G ? C : G;
            int a = x2 - x1;
            if (x1 >= x2)
                a = 0;

            int y1 = B >= F ? B : F;
            int y2 = D >= H ? H : D;
            int b = y2 - y1;
            if (y1 >= y2)
                b = 0;

            return s-a*b;
        }
};

int main(){
    Solution s;
    cout << s.computeArea(-2, -2, 2, 2, -2, -2, 2, 2) << endl;
}
