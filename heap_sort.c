#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "sort.h"

int arr[1000000];
char *strs[1000000];

int main(int argc, char **argv){
	int cnt = 0;
    int strMode = 0;
    if(argc == 2){
        if(strcmp(argv[1], "-n") == 0){
            strMode = 0;
        }else if(strcmp(argv[1], "-s") == 0){
            strMode = 1;
        }
    }else if(argc > 2){
        printf("format error\n");
        exit(0);
    }

    if(strMode){
        char input[1024];
        while(fgets(input, 1023, stdin)){
            strs[cnt] = strdup(input);
            cnt++;
        }
    }else{
        while(scanf("%d", &arr[cnt]) != EOF){
            cnt++;
        }
    }

	struct timeval start;
    struct timeval end;
    unsigned long diff;

    gettimeofday(&start, NULL);
	if(strMode){
		str_heap_sort(strs, cnt);
	}else{
		num_heap_sort(arr, cnt);
	}
    gettimeofday(&end, NULL);

    diff = 1000000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);

	printf("Heap Sort\ndata count: %d\n", cnt);
	printf("sec: %f s\nusec: %ld us\n", diff / 1000000.0, diff);

	// if(strMode){
    //     for (int i = 0; i < cnt; i++){
    //         printf("%s", strs[i]);
    //     }
    // }else{
    //     for (int i = 0; i < cnt; i++){
    //         printf("%d\n", arr[i]);
    //     }
    // }

	return 0;
}
