#include <stdlib.h>
#include <string.h>

void num_swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void str_swap(char **a, char **b){
    char *tmp = *a;
    *a = *b;
    *b = tmp;
}

void num_partition(int *arr, int begin, int end){
	if(begin < end){
		int pivot = arr[end];
        int j = begin;
        for (int i = begin; i < end; i++){
            if(arr[i] < pivot){
                num_swap(arr + i, arr + j);
                j++;
            }
        }
        num_swap(arr + end, arr + j);
        num_partition(arr, begin, j - 1);
        num_partition(arr, j + 1, end);
    }
}
void str_partition(char **strs, int begin, int end){
    if(begin < end){
        char *pivot = strs[end];
        int j = begin;
        for (int i = begin; i < end; i++){
            if(strcmp(pivot, *(strs + i)) > 0){
                str_swap(strs + i, strs + j);
                j++;
            }
        }
        str_swap(strs + end, strs + j);
        str_partition(strs, begin, j - 1);
        str_partition(strs, j + 1, end);
    }
}

void num_quick_sort(int *arr, int len){
    num_partition(arr, 0, len - 1);
}
void str_quick_sort(char **strs, int len){
    str_partition(strs, 0, len - 1);
}

void num_recursive(int *arr, int *reg, int begin, int end){
	if(begin >= end) return ;
	int len = end - begin, mid = len / 2 + begin;
	int begin_1 = begin, end_1 = mid;
	int begin_2 = mid + 1, end_2 = end;
	num_recursive(arr, reg, begin_1, end_1);
	num_recursive(arr, reg, begin_2, end_2);
	int k = begin;
	while(begin_1 <= end_1 && begin_2 <= end_2){
		if(arr[begin_1] <= arr[begin_2])
			reg[k++] = arr[begin_1++];
		else reg[k++] = arr[begin_2++];
	}
	while(begin_1 <= end_1) reg[k++] = arr[begin_1++];
	while(begin_2 <= end_2) reg[k++] = arr[begin_2++];
	for(int i = begin; i <= end; i++) arr[i] = reg[i];
	return ;
}
void str_recursive(char **strs, char **reg, int begin, int end){
	if(begin >= end) return ;
	int len = end - begin, mid = len / 2 + begin;
	int begin_1 = begin, end_1 = mid;
	int begin_2 = mid + 1, end_2 = end;
	str_recursive(strs, reg, begin_1, end_1);
	str_recursive(strs, reg, begin_2, end_2);
	int k = begin;
	while(begin_1 <= end_1 && begin_2 <= end_2){
		if(strcmp(strs[begin_2], strs[begin_1]) > 0)
			reg[k++] = strs[begin_1++];
		else reg[k++] = strs[begin_2++];
	}
	while(begin_1 <= end_1)	reg[k++] = strs[begin_1++];
	while(begin_2 <= end_2)	reg[k++] = strs[begin_2++];
	for(int i = begin; i <= end; i++) strs[i] = reg[i];
	return ;
}

int num_reg[1000000];
char *str_reg[1000000];

void num_merge_sort(int *arr, int len){
	num_recursive(arr, num_reg, 0, len - 1);
}
void str_merge_sort(char **strs, int len){
	str_recursive(strs, str_reg, 0, len - 1);
}

void num_heapify(int *arr, int begin, int end){
	int dad = begin;
	int son = dad * 2 + 1;
	while (son <= end){
		if(son + 1 <= end && arr[son + 1] >= arr[son])
			son++;
		if(arr[dad] > arr[son]) return;
		else{
			num_swap(arr + dad, arr + son);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}
void str_heapify(char **strs, int begin, int end){
	int dad = begin;
	int son = begin * 2 + 1;
	while(son <= end){
		if(son + 1 <= end && strcmp(*(strs + son + 1), *(strs + son)) > 0)
			son++;
		if(strcmp(*(strs + dad), *(strs + son)) > 0) return;
		else{
			str_swap(strs + dad, strs + son);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void num_heap_sort(int *arr, int len){
	for (int i = len / 2 - 1; i >= 0; i--)
		num_heapify(arr, i, len - 1);
	for (int i = len - 1; i > 0; i--){
		num_swap(arr, arr + i);
		num_heapify(arr, 0, i - 1);
	}
}
void str_heap_sort(char **strs, int len){
	for (int i = len / 2 - 1; i >= 0; i--)
		str_heapify(strs, i, len - 1);
	for (int i = len - 1; i > 0; i--){
		str_swap(strs, strs + i);
		str_heapify(strs, 0, i - 1);
	}
}
