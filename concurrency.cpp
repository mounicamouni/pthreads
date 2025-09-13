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
//void put(struct user *s){
//	FILE *fp = fopen("threads.txt", "a");
//	fprintf(fp, "%d %s\n", s->id, s->name);
//	fclose(fp);
//}
//
//void get(){
//	FILE *fp = fopen("threads.txt", "r");
//	fseek(fp, -55, SEEK_END);
//	char buff[255];
//	fgets(buff, 255, fp);
//
//	printf("buff %s\n", buff);
//	fclose(fp);
//	
//}
//
//void* create(void *vargs){
//	int id = 1;
//	while (1){
//		struct user *s = (struct user*)malloc(sizeof(struct user));
//		s->id =id ;
//		strcpy(s->name, "caw");
//		s->type = 1;
//		put(s);
//		id ++ ;
//		Sleep(15);
//	}
//
//}
//
//void *view(void *vargs){
//
//	while (1){
//
//
//		Sleep(20);
//	}
//}
//
//int main(){
//	/*struct user *s = (struct user*)malloc(sizeof(struct user));
//	s->id = 1;
//	strcpy(s->name, "caw");
//	put(s);
//	s->id =2;
//	strcpy(s->name, "csvs");
//	put(s);
//	get();*/
//
//
//	pthread_t thread1,thread2;
//	pthread_create(&thread1, NULL, create, (void*)NULL);
//	pthread_create(&thread2, NULL, view, (void*)NULL);
//
//	pthread_join(thread1, NULL);
//	pthread_join(thread2, NULL);
//
//	_getch();
//
//}