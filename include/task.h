#include <stdint.h>

typedef struct {
	unit32_t* stackPointer;
	void(*taskFunction)(void);
	unit32_t* type;
	unit32_t* proprity;
}Task;

