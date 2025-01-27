#ifndef INIT_PAGE_TABLE_H
#define INIT_PAGE_TABLE_H

#include <stdint.h>
#include <stdlib.h>
typedef struct {
    uint64_t entry; 
} page_table_entry_t;


#define NUM_PAGES 1024      
#define PAGE_SIZE 4096 
#define VIRT_SIZE 0x1000
#define PHYS_BASE 0x10000000 
#define VIRT_BASE 0x20000000 
#define FLAGS 0x3           

extern page_table_entry_t page_table[NUM_PAGES]; 

void init_page_table(void);

#endif 
