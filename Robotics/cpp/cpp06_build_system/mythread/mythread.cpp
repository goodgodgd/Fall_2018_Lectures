#include "foo.h"

void* pthread_func(void* data)
{
	char* thread_name = (char*)data;
	cout << "thread name: " << thread_name << std::endl;
}

void MyTread::create_thread()
{
	char name[] = "mythread";
	thr_id = pthread_create(&thread, NULL, pthread_func, (void*)p1);
}
