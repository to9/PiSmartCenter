#include "heap.h"
#include "list.h"

#ifndef NULL
#define NULL ((void *)0)
#endif

#define MEM_ALIGN_BYTE      (4)
#define MEM_ALIGN_MASK      (MEM_ALIGN_BYTE - 1)
#define MEM_ALIGN_PAD(m)    (((m) + MEM_ALIGN_MASK) & (~MEM_ALIGN_MASK))
#define MEM_ALIGN_CUT(m)    ((m) & (~MEM_ALIGN_MASK))

/*struct heap_mutex
{
    struct tcb_node *head;
    struct tcb_node *tail;
    bool lock;
};*/

struct heap_t
{
    struct heap_t *prev;
    struct heap_t *next;
    unsigned int used;
};

static unsigned int       	m_heap_size;
static struct heap_t  		*m_heap_head;
static struct heap_t  		*m_heap_free;
//static struct heap_mutex *m_heap_mutex;


void heap_init(unsigned int addr, unsigned int size)
{
    unsigned int start;
    unsigned int end;
    start = MEM_ALIGN_PAD(addr);
    end = MEM_ALIGN_CUT(addr + size);
    m_heap_size = end - start;
    m_heap_head = (struct heap_t *)start;
    m_heap_head->used = sizeof(struct heap_t)/* + sizeof(struct heap_mutex)*/;
    m_heap_head->prev = NULL;
    m_heap_head->next = (struct heap_t *)(end - sizeof(struct heap_t));
    m_heap_head->next->used = sizeof(struct heap_t);
    m_heap_head->next->prev = m_heap_head;
    m_heap_head->next->next = NULL;
    m_heap_free = m_heap_head;
//    m_heap_mutex = (struct heap_mutex *)(m_heap_head + 1);
//    m_heap_mutex->head = NULL;
//    m_heap_mutex->tail = NULL;
//    m_heap_mutex->lock = false;	
}

static struct heap_t *find_next_free(struct heap_t *node)
{
    unsigned int free;
    for(; node->next != NULL; node = node->next)
    {
        free = ((unsigned int)node->next) - ((unsigned int)node) - node->used;
        if(free > sizeof(struct heap_t))
        {
            break;
        }
    }
    return node;
}

void *heap_malloc(unsigned int size)
{
    unsigned int free;
    unsigned int need;
    struct heap_t *temp;
    struct heap_t *node;
    need = size + sizeof(struct heap_t);
    need = MEM_ALIGN_PAD(need);
    //heap_lock();
    for(node = m_heap_free; node->next != NULL; node = node->next)
    {
        free = ((unsigned int)node->next) - ((unsigned int)node) - node->used;
        if(free >= need)
        {
            temp = (struct heap_t *)((unsigned int)node + node->used);
            temp->prev = node;
            temp->next = node->next;
            temp->used = need;
            node->next->prev = temp;
            node->next = temp;
            if(node == m_heap_free)
            {
                m_heap_free = find_next_free(m_heap_free);
            }
            //heap_unlock();
            return (void *)(temp + 1);
        }
    }
    //heap_unlock();
    return NULL;	
}

void heap_free(void *buff)
{
    struct heap_t *node;
    node = (struct heap_t *)buff - 1;
    //heap_lock();
    node->prev->next = node->next;
    node->next->prev = node->prev;
    if(node->prev < m_heap_free)
    {
        m_heap_free = node->prev;
    }
    //heap_unlock();	
}


