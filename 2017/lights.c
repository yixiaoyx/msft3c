#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int square(unsigned int a[], int n) {
    int i, count=0;
    for (i = 1; i <=sqrt(n); i++) {
            a[i*i] = i;
        } 
    for (i = 1; i <=n; i++) {
            if (a[i]) count++;
        }
    return count;
}

int main(int argc, char *argv[]) {
    unsigned int n;
    while (scanf("%u", &n)!=EOF) {
            if (n==0||n==1) {
                        printf("0\n");
                        continue;
                    }
            unsigned int *array = (unsigned int *)calloc(n+1, sizeof(unsigned int));
            assert(array);
            printf("%u\n", n-square(array, n));
            free(array); 
        }

    return 0;
}
