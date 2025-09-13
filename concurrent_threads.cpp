//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<conio.h>
//#include<pthread.h>
//#include<Windows.h>
//#include<stdlib.h>
//
//struct user{
//	int id;
//	int type;
//	char name[24];
//};
//
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
//pthread_mutex_t queue_mutex = PTHREAD_MUTEX_INITIALIZER;
//
//
//struct user **arr;
//void initialize(){
//	arr = (struct user**)malloc(sizeof(struct user*) * 100);
//	for (int i = 0; i < 100; i++){
//		arr[i] = (struct user*)malloc(sizeof(struct user));
//	}
//}
//int front = -1, rear = -1;
//
//pthread_t thread[4];
//int flag[4] = { 0, 0, 0, 0 };
//
//
//
//void * put(void *vargs){
//	struct user *s = (struct user *)vargs;
//	FILE *fp = fopen("threads.txt", "a");
//	printf("%d   %s\n", s->id, s->name);
//	fprintf(fp, "%d %s\n", s->id, s->name);
//	fclose(fp);
//	return NULL;
//}
////for checking purpose i am printing the first line of file
//void * get(void *vargs){
//	struct user *s = (struct user *)vargs;
//	FILE *fp = fopen("threads.txt", "r");
//
//	char buff[255];
//	char **tokens;
//	int len, val;
//	while (fgets(buff, 255, fp) != NULL){
//		printf("In get %s\n", buff);
//		break;
//	}
//
//
//	fclose(fp);
//	return NULL;
//}
//
//
//void put_into_arr(struct user *u){
//	if (rear == 99)
//		printf("\nQueue is Full!!");
//	else {
//		if (front == -1)
//			front = 0;
//		rear++;
//		arr[rear] = u;
//	}
//}
//int qEmpty(){
//	if (front == -1) //q empty
//		return 0;
//	return 1;
//}
//struct user * pop(){
//	if (front == -1)
//		return NULL;
//	else{
//		struct user *u = arr[front];
//
//		front++;
//		if (front > rear)
//			front = rear = -1;
//		return u;
//	}
//
//}
//
//void* listener_fun(void *vargs){
//	struct user *uu;
//	while (1){
//		for (int i = 0; i < 4; i++){
//			if (flag[i] == 0 && qEmpty()){
//				flag[i] = 1;
//				uu = pop();
//				if (uu->type == 0){
//					pthread_create(&thread[i], NULL, get, (void*)uu);
//
//				}
//				else{
//					pthread_mutex_lock(&mutex);
//					pthread_create(&thread[i], NULL, put, (void*)uu);
//					pthread_mutex_unlock(&mutex);
//				}
//				flag[i] = 0;
//			}
//		}
//		Sleep(10);
//	}
//	return NULL;
//}
//
//void scheduler(struct user *u){
//	pthread_mutex_lock(&queue_mutex);
//	put_into_arr(u);
//	pthread_mutex_unlock(&queue_mutex);
//
//}
//
//void * view_profile(void *p)
//{
//	struct user *u = (struct user*)malloc(sizeof(struct user));
//	int id = 1;
//
//	while (1){
//		u->id = id;
//		id++;
//		strcpy(u->name, "MOUni");
//		u->type = 0;
//		scheduler(u);
//		if (id == 50)
//			break;
//		Sleep(20);
//	}
//	return NULL;
//}
//
//
//
//void * create_profile(void *p)
//{
//	struct user *u = (struct user*)malloc(sizeof(struct user));
//	int id = 1;
//
//	while (1){
//		u->id = id;
//		id++;
//		strcpy(u->name, "MOUni");
//		u->type = 1;
//		scheduler(u);
//		if (id == 50)
//			break;
//		Sleep(15);
//	}
//	return NULL;
//}
//
//int main(){
//	initialize();
//	struct user *u = (struct user*)malloc(sizeof(struct user));
//
//	pthread_t thread[2];
//	pthread_t listener;
//	pthread_create(&thread[0], NULL, create_profile, NULL);
//	pthread_create(&thread[1], NULL, view_profile, NULL);
//	pthread_create(&listener, NULL, listener_fun, NULL);
//
//	pthread_join(thread[0], NULL);
//	pthread_join(thread[1], NULL);
//	pthread_join(listener, NULL);
//	_getch();
//	return 0;
//}