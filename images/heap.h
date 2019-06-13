#ifndef _HEAP_H
#define _HEAP_H

void heap_init(unsigned int addr, unsigned int size);
void *heap_malloc(unsigned int size);
void heap_free(void *buff);


#endif //_HEAP_H

