#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int wk, ppl, time, s, c;
    scanf("%d", &wk);
    int i, j;
    for (i = 0; i < wk; i++) {
            scanf("%d", &ppl);
            time = 0; 
            for (j = 0; j < ppl; j++) {
                        scanf("%d %d", &s, &c);
                        if (s+c > time) time = s+c;
                    }
            if (time <= 230)
                printf("%d\n", 230-time);
            else 
                printf("0\n");
            
        
        }

    return 0;
}
