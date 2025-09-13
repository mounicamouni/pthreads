//#include<stdio.h>
//#include<stdlib.h>
//#include<pthread.h>
//#include<conio.h>
//
//int index = 0;
//void *oddEven(void *vargs){
//	int x = index++;
//	int *a = ((int*)vargs);
//
//	for (int i = x*100/2 ; i<(x+1)*100/2 ; i++){
//		printf("%d ", a[i]);
//	}
//
//	return NULL;
//}
//int flag = 0;
//pthread_mutex_t mutex;
//void *even(void *vargs){
//	int *a = ((int*)vargs);
//	
//		for (int i = 0; i < 100; i = i + 2){
//			pthread_mutex_unck(&mutex);
//			printf("even  %d \n", a[i]);
//			pthread_mutex_unlock(&mutex);
//	}
//	return NULL;
//}
//
//void *odd(void *vargs){
//	int *a = ((int*)vargs);
//	
//	if (flag == 1){
//		for (int i = 1; i < 100; i = i + 2){
//			printf("odd %d \n", a[i]);
//		}
//		flag = 0;
//	}
//	
//	return NULL;
//}
//
//int main(){
//	pthread_t thread[4];
//	int a[100];
//	for (int i = 0; i < 100; i++){
//		a[i] = i;
//	}
//	for (int i = 0; i < 2;i++)
//		pthread_create(&thread[i], NULL, oddEven, (void*)a);
//	for (int i = 0; i < 2; i++)
//	pthread_join(thread[i], NULL);
//
//
//	printf("\n\n\n");
//	pthread_create(&thread[3], NULL, odd, (void*)a);
//	pthread_create(&thread[4], NULL, even, (void*)a);
//	pthread_join(thread[3], NULL);
//	pthread_join(thread[4], NULL);
//
//	_getch();
//
//}