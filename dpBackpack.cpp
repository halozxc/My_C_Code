#include<stdio.h>
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int main(){
    int w[6] = {0, 3, 4, 7, 8, 9};
    int v[6] = {0, 4, 5, 10, 11, 13};
    int bagv = 15;
    int dp[6][bagv + 1] = {{0}};
    for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 16; j++) {
		 dp[i][j] =0;
		}
		
	}
    for (int i = 1; i <= 5;i++){
        for (int j = 1; j <= bagv;j++){
            if(j<w[i]){
                dp[i][j] = dp[i - 1][j];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);//
            }
        }
    }
    printf("w v 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15\n");
    for (int i = 0; i < 6; i++) {
        printf("%d %d ", w[i], v[i]);
      
        for (int j = 0; j < 16; j++) {
            printf("%d ",  dp[i][j]);
        }
        printf("\n");
    }
    return 0;
}
