#ifndef FOO_H
#define FOO_H

#include <iostream>
#include <pthread.h>

class MyThread
{
public:
	MyThread() {}
	pthread_t thread;
	int thr_id;
	void create_thread();
}

#endif // FOO_H
