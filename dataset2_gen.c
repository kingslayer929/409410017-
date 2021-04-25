#include <stdio.h>
#include <stdlib.h>

int main(){
    int seed, len, cnt;
    scanf("%d%d%d", &seed, &len, &cnt);
    srand(seed);
    while(cnt--){
        for (int i = 0; i < len; i++)
            printf("%c", rand() % 95 + 32);
        printf("\n");
    }
    return 0;
}