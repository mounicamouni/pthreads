//#include"stdafx.h"
//#define HAVE_STRUCT_TIMESPEC
//#include <pthread.h>
//
//int status[4];
//pthread_mutex_t queue_mutex;
//pthread_mutex_t mutex;
//pthread_t server_threads[4];
//struct queue
//{
//	char request[150];
//	int index;
//	queue *next;
//}*latest = NULL, *next_req = NULL;
//void initialize_server()
//{
//	for (int i = 0; i < 4; i++)
//		status[i] = 1;
//	pthread_mutex_init(&mutex, NULL);
//}
//void * service_request(void *i)
//{
//	queue *req = (queue*)i;
//	if (strstr(req->request, "PUT"))
//	{
//		pthread_mutex_lock(&mutex);
//		request(req->request);
//		pthread_mutex_unlock(&mutex);
//	}
//	else
//		request(req->request);
//	status[req->index] = 1;
//	free(i);
//	return NULL;
//}
//void * listener(void *p)
//{
//	while (1)
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			if (status[i] && latest)
//			{
//				status[i] = 0;
//				latest->index = i;
//				pthread_create(&server_threads[i], NULL, service_request, latest);
//				latest = latest->next;
//			}
//			_sleep(2000);
//		}
//	}
//	return NULL;
//}
//void add_to_queue(char *request)
//{
//	pthread_mutex_lock(&queue_mutex);
//	if (latest == NULL)
//	{
//		latest = (queue *)malloc(sizeof(queue));
//		strcpy(latest->request, request);
//		latest->next = NULL;
//		next_req = latest;
//	}
//	else
//	{
//		if (next_req->next)
//		{
//			next_req->next = (queue *)malloc(sizeof(queue));
//			strcpy(next_req->next->request, request);
//			next_req->next->next = NULL;
//			next_req = next_req->next;
//		}
//	}
//	pthread_mutex_unlock(&queue_mutex);
//}
//void * create_profile(void *p)
//{
//	char name[][20] = {};
//}
//void main()
//{
//	initializeDB();
//	initialize_server();
//	pthread_t thread[2];
//	pthread_t listener;
//	pthread_create(&thread[0], NULL, create_profile, (void*)NULL);
//	pthread_create(&thread[1], NULL, view_profile, (void*)NULL);
//	pthread_create(&listener, NULL, listener_func, NULL);
//	pthread_join(thread[0], NULL);
//	pthread_join(thread[1], NULL);
//	pthread_join(listener, NULL);
//
//}
