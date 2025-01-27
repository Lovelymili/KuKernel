#include <stdlib.h>
#include <stdint.h>

#define HEAP_START 0x22000000;
#define HEAP_END 0xF0000000;
#define MM_START 0x24000000;
#define MM_END 0x28000000;

typedef struct {
	uint32_t begin_address;
	uint32_t end_address;
	uint32_t size;
}memoryblock;

void write_to_memory(uint64_t address, uint64_t data);
void write_to_memory(uint64_t address, char* data[]);
uint64_t read_memory(uint64_t address);
void init_memory_table();
uint64_t kmalloc(uint64_t size);




