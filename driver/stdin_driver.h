#pragma once
#include "driver.h"
#include "instrumentation.h"
#include <global_types.h>

void * stdin_create(char * options, instrumentation_t * instrumentation, void * instrumentation_state,
	mutator_t * mutator, void * mutator_state);
void stdin_cleanup(void * driver_state);
int stdin_test_input(void * driver_state, char * buffer, size_t length);
int stdin_test_next_input(void * driver_state);
char * stdin_get_last_input(void * driver_state, int * length);
char * stdin_help(void);

struct stdin_state
{
	//Options
	char * path;         //The path to the fuzzed executable
	char * arguments;    //Arguments to give the binary
	int timeout;         //Maximum number of seconds to allow the executable to run
	double input_ratio;  //the ratio of the maximum input size

	//The handle to the fuzzed process instance
	HANDLE process;

	//The instrumentation module
	instrumentation_t * instrumentation;

	//The instrumentation's state
	void * instrumentation_state;

	mutator_t * mutator;
	void * mutator_state;
	char * mutate_buffer;
	size_t mutate_buffer_length;
	int mutate_last_size;
};
typedef struct stdin_state stdin_state_t;
