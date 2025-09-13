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
//void * put( void *vargs){
//	pthread_mutex_lock(&mutex);
//	struct user *s = (struct user *)vargs;
//	FILE *fp = fopen("threads.txt", "a");
//	printf("%d   %s\n", s->id, s->name);
//	fprintf(fp, "%d %s\n", s->id, s->name);
//	fclose(fp);
//	pthread_mutex_unlock(&mutex);
//	return NULL;
//}
//
//void * get(void *vargs){
//	struct user *s = (struct user *)vargs;
//	FILE *fp = fopen("threads.txt", "r");
//	
//	char buff[255];
////	while (fgets(buff, 255, fp) != NULL){
////		printf("buff %s\n", buff);
////	}
//
//	
//	fclose(fp);
//	return NULL;
//}
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
//
//void put_into_arr(struct user *u){
//    if(rear == 99)
//        printf("\nQueue is Full!!");
//    else {
//        if(front == -1)
//            front = 0;
//        rear++;
//        arr[rear] = u;
//    }
//	//for (int i = front; i <= rear; i++){
//	//	printf("%d %s \n\n", arr[i]->id, arr[i]->name);
//	//}
//}
//
//struct user * pop(){
//    if(front == -1)
//       return NULL;
//    else{
//		struct user *u = arr[front];
//       
//        front++;
//        if(front > rear)
//            front = rear = -1;
//		return u;
//    }
//	
//}
//
//
//pthread_t thread[4];
//int flag[4] = { 0, 0, 0, 0 };
//void scheduler(struct user *u){
//	put_into_arr(u);
//
//	//while (1){
//	//	if (counter == 4)
//	//		break;
//	//	else{
//	//		
//	//		for (int i = 0; i < 4 - counter; i++){
//	//			if (u->type==1)
//	//				pthread_create(&thread[i], NULL, put, (void*)u);
//
//	//		}
//	//	}
//	//}
//	struct user *uu;
//	for (int i = 0; i < 4; i++){
//		if (flag[i] == 0){
//			flag[i] = 1;
//			uu = pop();
//			if (uu == NULL)
//				break;
//			if (uu->type = 0){
//				flag[i] = pthread_create(&thread[i], NULL, get, (void*)uu);
//
//			}
//			else
//				flag[i]=pthread_create(&thread[i], NULL, put, (void*)uu);
//			pthread_join(thread[i], NULL);
//		}
//	}
//	
//}
//
//int main(){
//	initialize();
//	struct user *u = (struct user*)malloc(sizeof(struct user));
//	int id = 1;
//	char *type = "111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
//	
//	while (1){
//		u->id = id;
//		id++;
//		strcpy(u->name, "MOUni");
//		u->type = type[id] - 48;
//		scheduler(u);
//		if (id == 50)
//			break;
//	}
//
//	_getch();
//	return 0;
//}