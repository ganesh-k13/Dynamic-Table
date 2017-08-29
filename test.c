#include "include/dynamic_table.h"
#include "include/get_time.h"
#include "include/utils.h"
#include <string.h>

void test_insert(long int size, float factor) {
	struct timespec requestStart, requestEnd;
	DynamicTable *Table = init(size, factor);

	long int i, j;
	for(i = 0; i < 1000000; i++) {
		clock_gettime(CLOCK_REALTIME, &requestStart);
		push_back(Table, 5);
		clock_gettime(CLOCK_REALTIME, &requestEnd);
		printf("%f ", accum_time(requestStart, requestEnd));
	}
	
	free (Table);
}

void test_delete(long int size, float factor) {
	struct timespec requestStart, requestEnd;
	DynamicTable *Table = init(size, factor);

	long int i, j;
	for(i = 0; i < 1000000; i++) {
		// clock_gettime(CLOCK_REALTIME, &requestStart);
		push_back(Table, 5);
		// clock_gettime(CLOCK_REALTIME, &requestEnd);
		// printf("%f ", accum_time(requestStart, requestEnd));
	}

	for(i = 1; i < 1000000; i++) {
		clock_gettime(CLOCK_REALTIME, &requestStart);
		remove_element(Table);
		clock_gettime(CLOCK_REALTIME, &requestEnd);
		printf("%f ", accum_time(requestStart, requestEnd));
	
    }
    
    free (Table);
}

#if 0
void test_random(long int insert_times, long int delete_times) {
    bool *arr = malloc(sizeof(bool)*(insert_times + delete_times));
    arr = create_data(insert_times, delete_times);
    
    long int i = 0;
    
    for(i = 0 ; i < (insert_times + delete_times); i++) {
        if(arr[i]) {
            push_back(Table, 5);
        }
        else {
            
        }
    }
    
    free(arr);
}
#endif

void run_tests(char** args, int no_of_args) {
	int i = 0;
	if(!strcmp(args[0], "-i")) {
		test_insert(atol(args[1]), atof(args[2]));
	}

	if(!strcmp(args[0], "-d")) {
		test_delete(atol(args[1]), atof(args[2]));
	}
	
#if 0
	if(!strcmp(args[0], "-r")) {
        test_random(atol(args[1]), atol(args[1]));
    }
#endif
}

int main(int argl, char** argv) {
	// run_tests(argv + 1, argl - 1);
	
#if 0
	int i;
	
	DynamicTable *Table = init((size_t)0, (size_t)100, 1.25);
	
	push_back(Table, 5);
	// resize_(Table);
	
	for(i = 0; i < 1000000; i++) {
		push_back(Table, 5);
	}
	
	for(i = 0; i < 10000; i++) {
		remove_element(Table);
	}
	
	printf("%d\n", 1.25 > 1.255);
	
	delete_table(Table);
	
#endif
	
#if 0
    bool *arr = malloc(sizeof(bool)*(40000 + 60000));
	arr = create_data(40000, 60000);
    long int i;
    for(i = 0; i < 40000 + 60000; i++) {
        //printf("%d ", arr[i]);
    }
    free(arr);
#endif
	
	run_tests(argv + 1, argl - 1);
	
	return 0;
}
