#include <stdlib.h>
#include <stdint.h>

typedef struct {
	char* data;
}string;

string write_to_chars(char* chars, const void* data, const void* data_size);
size_t string::get_data_size(const void* data);