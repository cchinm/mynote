// 名称：数字三角形
// 1
// 12 123
// 23 213 21312
// 到底层的最大和，约束只能走正下方/右下方
// 作者：cchinm
// 时间：20190811

#include<iostream>
#include<algorithm>

using namespace std;

#define MAX 101

int D[MAX][MAX];
int n;
int maxSum[MAX][MAX];

int MaxSum(int, int);
int CalMaxSum();


int main(){
    int i, j;
    cin >> n;
    for (i=1; i<=n; i++)
        for(j=1; j<=i; j++) {
            cin >> D[i][j];
            maxSum[i][j] = -1;
        }
    cout << CalMaxSum() << endl;
    return 0;
}

// DP 
int MaxSum(int i, int j){
    if (maxSum[i][j] != -1){
        return maxSum[i][j];
    }

    if (i == n)
        maxSum[i][j] = D[i][j];
    else{
        int x = MaxSum(i+1, j);
        int y = MaxSum(i+1, j+1);
        maxSum[i][j] = max(x, y) + D[i][j];
    }
    return maxSum[i][j];

}

// improve space use.
// It dont use maxSum array. 
int CalMaxSum(){
    int x, y;
    for (x=n; x>1 ; x--)
        for(y=1; y<=x-1; y++){
            D[n][y] = max(D[n][y], D[n][y+1]) + D[x-1][y];
            cout << D[n][y] << endl;
        }
    return D[n][1];
}