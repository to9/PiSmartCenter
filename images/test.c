static unsigned char heap[10*1024];
 
heap_init((unsigned int)heap, sizeof(heap));


#define OSX_THREAD_NAME_MAX	8
struct osx_thread
{
	unsigned int	*stack_addr;                    //stack address
	unsigned short  stack_size;                     //stack size

	char        	name[OSX_THREAD_NAME_MAX];      //the name of thread
	osx_list_t  	list;                        	//the thread list

	void       		*entry;                         //entry
	void       		*arg;                           //parameter

	unsigned char   state;                          //thread stat
	unsigned char   current_priority;               //current priority
	unsigned char   init_priority;                  //initialized priority

	unsigned long  	init_tick;                      // thread's initialized tick
	unsigned long  	remaining_tick;                 //remaining tick
	osx_timer_t 	timer;
};
typedef struct osx_thread osx_thread_t;

typedef void *thread_t;


thread_t osx_thread_create_1(const char *name, void (*entry)(void *), void *arg, unsigned char priority)
{
	unsigned int key;
	osx_thread_t *thread;

	if(priority >= OSX_THREAD_PRIORITY_MAX)
		return;

	//if(tick > OS_TICK_MAX / 2)
	//	return;

	
    thread = heap_malloc(sizeof(osx_thread_t) + /*stack_size*/0x80);
    if(thread != NULL)
    {
		osx_strncpy(thread->name, name, OSX_THREAD_NAME_MAX);
		list_init(&thread->list);
		thread->entry = (void *)entry;
		thread->arg = arg;
		thread->stack_addr = (unsigned int *)thread;
		thread->stack_size = (unsigned short)0x80;
		thread->state = OSX_THREAD_READY;
		thread->init_priority = priority;
		thread->current_priority = priority;
		thread->init_tick = 100;//###
		thread->remaining_tick = 100;//###
		
		osx_stack_init(thread);

		key = _arch_irq_lock();
		osx_thread_insert(thread);
		_arch_irq_unlock(key);
    }
	
	return (thread_t)thread;
}


