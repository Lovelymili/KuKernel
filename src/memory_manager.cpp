#include <stdlib.h>
#include <stdint.h>
#include "memory_manager.h"
#include "init_page_table.h"
#include "stdlib/string.h"

void write_to_memory(uint64_t address,uint64_t data)
{
	uint8_t* ptr = (uint8_t*)address;
	*ptr = data;
}
void write_to_memory(uint64_t address, char* data[])
{
	uint64_t* ptr = (uint64_t*)address;
	for (int i = 0; i < string::get_data_size(data); i++)
	{
		*ptr[i] = data[i];
	}
	
}

uint64_t read_memory(uint64_t address)
{
	uint64_t* ptr = (uint64_t*)address;
	return *ptr;
}

void init_memory_table()
{
	char memory_table[MM_END - MM_START] = {0};

	write_to_memory(MM_START, memory_table);
	
}

uint64_t kmalloc(uint64_t size)
{
	for (uint64_t i = MM_START; i < MM_END; i ++)
	{
		uint64_t now_address;
		uint64_t last_address;
		uint64_t free_memory;
		int flag = 0; 
		if (read_memory(i) == 1 && flag==0 && read_memory(i+1) ==0)
		{
			last_address = i;
			flag = 1;
		}
		else if (read_memory(i) == 0 && flag == 1 && read_memory(i + 1) == 1)
		{
			now_address = i;
			flag = 2; 
		}
		else
		{
		}
		free_memory = now_address - last_address;
		if (free_memory >= size)
		{
			for (uint64_t i = last_address, i < now_address; i++)
			{
				write_to_memory(i, 1);
			}
			return HEAP_START + PAGE_SIZE * (last_address - MM_START);
		}


	}
}

void free(uint64_t start_address;uint64_t end_address)
{
	for (uint64_t i = start_address; i < end_address; i++)
	{
		write_to_memory(i, 0);
	}

}