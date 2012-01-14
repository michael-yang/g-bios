#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

static pthread_mutex_t mutex_a;
static pthread_mutex_t mutex_b;
static pthread_mutex_t mutex_c;

void *a(void *argv)
{
	while (1) {
		pthread_mutex_lock(&mutex_a);
		printf("%s     %d\n", __func__, __LINE__);
		pthread_mutex_unlock(&mutex_a);
		sleep(1);
	}
}

void *b(void *argv)
{
	while (1) {
		pthread_mutex_lock(&mutex_b);
		printf("%s     %d\n", __func__, __LINE__);
		pthread_mutex_unlock(&mutex_b);
		sleep(1);
	}
}

void *c(void *argv)
{
	while (1) {
		pthread_mutex_lock(&mutex_c);
		printf("%s     %d\n", __func__, __LINE__);
		pthread_mutex_unlock(&mutex_c);
		sleep(1);
	}
}

int main(int argc, const char *argv[])
{
	pthread_t p_a;
	pthread_t p_b;
	pthread_t p_c;

	pthread_create(&p_a, NULL, a, NULL);
	pthread_create(&p_b, NULL, b, NULL);
	pthread_create(&p_c, NULL, c, NULL);

	pthread_join(p_a, NULL);
	pthread_join(p_b, NULL);
	pthread_join(p_c, NULL);

	return 0;
}
