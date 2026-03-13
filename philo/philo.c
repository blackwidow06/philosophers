#include <stdio.h>
#include <pthread.h>

void *hello(void *arg)
{
	printf("bonjour je suis 1\n");
	return NULL;
}

void *hello2(void *arg)
{
	printf("bonjour je suis 2\n");
	return NULL;
}

void *hello3(void *arg)
{
	printf("bonjour je suis 3\n");
	return NULL;
}
int main()
{
	pthread_t thread;
	pthread_t thread2;
	pthread_t thread3;

	pthread_create(&thread, NULL, hello, NULL);
	pthread_create(&thread2, NULL, hello2, NULL);
	pthread_create(&thread3, NULL, hello3, NULL);
	pthread_join(thread, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);

	printf("Hello from main\n");
}