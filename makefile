all: quick_sort.c merge_sort.c heap_sort.c dataset1_gen.c dataset2_gen.c
	gcc dataset1_gen.c -o dataset1_gen.exe
	gcc dataset2_gen.c -o dataset2_gen.exe
	gcc quick_sort.c -o quick_sort.exe
	gcc merge_sort.c -o merge_sort.exe
	gcc heap_sort.c -o heap_sort.exe
	