#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int getMove(int **a, int x, int y, int r, int c, int moveR[], int moveC[]) {
    int i=0, j=0;
    if (r>0 && a[r-1][c]==a[r][c]+1) {
        moveR[i++] = r-1;
    }
    if (r<x-1 && a[r+1][c]==a[r][c]+1) {
        moveR[i++] = r+1;
    } 
    if (c>0 && a[r][c-1]==a[r][c]+1) {
        moveC[j++] = c-1;
    }
    if (c<y-1 && a[r][c+1]==a[r][c]+1) {
        moveC[j++] = c+1;
    }
    return i+j;
}

void initArray(int a[], int size, int val) {
    int i;
    for (i = 0; i < size; i++)
        a[i] = val;
}

int bfs(int **a, int x, int y, int r[], int c[]) {
    if (a[r[0]][c[0]]==a[r[1]][c[1]]) return 1;
    int moveR[4], moveC[4];
    initArray(moveR, 4, -1);
    initArray(moveC, 4, -1);
    if (getMove(a, x, y, r[0], c[0], moveR, moveC)==0) return 0;

    int i, ret = 0;
    int r0 = r[0], c0 = c[0];
    for (i = 0; moveR[i]!=-1 && ret==0; i++) {
        r[0] = moveR[i];
        ret = bfs(a, x, y, r, c);
    }
    if (ret==0) r[0] = r0;
    for (i = 0; moveC[i]!=-1 && ret==0; i++) {
        c[0] = moveC[i];
        ret = bfs(a, x, y, r, c);
    }
    if (ret==0) c[0] = c0;
    return ret;
}

int main(int argc, char *argv[]) {
    int n, x, y, tests;
    scanf("%d", &tests);
    int i, j;
    int row[2], col[2];
    char *boolean[] = {"false", "true"}; 
    for (i = 0; i < tests; i++) {
        if (scanf("%d", &n)==EOF) break;
        scanf("%d", &x);
        scanf("%d", &y);
        int **array = (int **)calloc(x, sizeof(int *));
        for (j = 0; j < x; j++)
            array[j] = (int *)calloc(y, sizeof(int));
        assert(array);
        
        for (j = 0; j < x*y; j++) {
            scanf("%d", &array[j/y][j%y]);
            if (array[j/y][j%y]==1) {
                row[0] = j/y;
                col[0] = j%y;
            } else if (array[j/y][j%y]==n) {
                row[1] = j/y;
                col[1] = j%y;
            }
        }

        printf("%s\n", boolean[bfs(array, x, y, row, col)]);
        free(array);
    
    }

    return 0;
}
