#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// using namespace std;

void main() {
    int n;
    scanf("%d", &n);
    char c1, c2;
    scanf("%c", &c1);
    scanf("%c", &c2);
    int x;
    scanf("%d", &x);
    int mat1[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(c1 == 'R')
                scanf("%d", &mat1[i][j]);
            else
                scanf("%d", &mat1[j][i]);
        }
    }
    int mat2[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (c2 == 'R')
                scanf("%d", &mat2[i][j]);

            else
                scanf("%d", &mat2[j][i]);
        }
    }

    int mn1[n], mn2[n], mx1[n], mx2[n];
    for(int i = 0; i < n; i++) {
        mn1[i] = INT_MAX;
        mn2[i] = INT_MAX;
        mx2[i] = INT_MIN;
        mx1[i] = INT_MIN;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // cout << mat1[i][j];
            if (mn1[i] < mat1[i][j])
                mn1[i] = mat1[i][j];
            if (mx1[i] > mat1[i][j])
                mx1[i] = mat1[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // cout << mat2[j][i] << endl;
            if(mn2[i] < mat2[j][i])
                mn2[i] = mat2[j][i];
            if(mx2[i] > mat2[j][i])
                mx2[i] = mat2[j][i];
        }
    }
 
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(x == 1) {
                ans += mx1[i] * mx2[j];
            } else {
                ans += mn1[i] * mn2[j];
            }
        }
    }
    printf("%d", ans);
    
}