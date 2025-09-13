#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <time.h>
#include<pthread.h>

int** mat_mul(int **arr1,int **arr2,int n){
	int **sum = (int **)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++){
		sum[i] = (int *)malloc(sizeof(int)*n);
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			sum[i][j] = 0;
			for (int k = 0; k < n; k++){
				sum[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}
	/*for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			printf("%d ", sum[i][j]);
		}
		printf("\n");
	}
*/
	printf("hrlllo");
	return sum;
}

int **arr1;
int **arr2;
int n,part=0;
int **sum;
int no_threads;
pthread_mutex_t mutex;
void * mat_mul_threads(void *vargs){
	int *a = ((int*)vargs);
	
	int x = *a;
	*a = *a + 1;
	printf("%d \n", *a);
	//pthread_mutex_unlock(&mutex);
	for (int i = x*(n / no_threads); i < (x + 1)*(n / no_threads); i++){
		for (int j = 0; j < n; j++){
			sum[i][j] = 0;
			for (int k = 0; k < n; k++){
				sum[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}
	
	printf("hrlllo");
	return NULL;
}

int main(){
	printf("enter n:\n");
	scanf("%d", &n);
	printf("enter no_threads\n");
	scanf("%d", &no_threads);
	arr1 = (int **)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++){
		arr1[i] = (int *)malloc(sizeof(int)*n);
	}
	arr2 = (int **)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++){
		arr2[i] = (int *)malloc(sizeof(int)*n);
	}
	sum = (int **)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++){
		sum[i] = (int *)malloc(sizeof(int)*n);
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j< n; j++){
			arr1[i][j] = i;
			arr2[i][j] = i;
		}
	}
	
	clock_t t;
	t = clock();
	pthread_t thread[10];
	for (int i = 0; i < no_threads; i++)
			pthread_create(&thread[i], NULL, mat_mul_threads, (void*)&part);
	for (int i = 0; i < no_threads; i++)
			pthread_join(thread[i], NULL);


	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC;
	printf("fun() took %f seconds to execute \n", time_taken);



	clock_t t1;
	t1 = clock();
	
	mat_mul(arr1,arr2,n);

	t1 = clock() - t1;
	double time_taken1 = ((double)t1) / CLOCKS_PER_SEC;
	printf("\n\n\ngeneralfun() took %f seconds to execute \n", time_taken1);

	_getch();

}