all: quick merge heap

quick: quick.h quick_sort.c
	gcc quick_sort.c -o quick

merge: merge.h merge_sort.c
	gcc merge_sort.c -o merge

heap: heap.h heap_sort.c
	gcc heap_sort.c -o heap

clean:
	rm -f quick merge heap
 