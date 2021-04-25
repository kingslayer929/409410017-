#include <stdio.h>
#include <stdlib.h>

int main(){
    int seed, cnt;
    scanf("%d%d", &seed, &cnt);
    srand(seed);
    while(cnt--) printf("%d\n", rand());
    return 0;
}