#include "init_page_table.h"
#include <stdint.h>
#include <stdlib.h>
extern void memzero(void* start, size_t length);

page_table_entry_t page_table[NUM_PAGES];

void init_page_table() {
	memzero(page_table, sizeof(page_table));
	for (int i = 0; i < NUM_PAGES; i++)
	{
		uint64_t phys_addr = PHYS_BASE + i * PAGE_SIZE;
		uint64_t virt_addr = VIRT_BASE + i * VIRT_SIZE;
		page_table[i].entry = (phys_addr & ~0xFFF) | FLAGS;

	}
}
