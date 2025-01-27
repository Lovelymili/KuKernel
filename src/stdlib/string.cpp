#include <stdlib.h>
#include <stdint.h>
#include "stdlib/string.h"

class string
{
public:
	
	string write_to_chars(char* chars, const void* data, const void* data_size);
	size_t string::get_data_size(const void* data);

};

size_t string::get_data_size(const void* data)
{
	char* byte_data = static_cast<const void*>(data);
	size_t length = 0;
	while (byte_data[length] != '\0')
	{
		length++;
	}
	return length;
}
string string::tostr(char* chars, const void* data)
{
	string return_data;
	const uint8_t* byte_data = static_cast<const uint8_t*>(data);
	for (int i = 0; i < string::get_data_size(byte_data); i++)
	{
		chars[i] = byte_data[i];
	}
	return_data.data = chars;
	return return_data;
}