#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>

char** tokenize(char *str, int *len)
{
	int j = 0, k = 0;
	char **x = (char**)malloc(sizeof(char) * 20);
	for (int i = 0; i < 20; i++){
		x[i] = (char*)malloc(sizeof(char) * 20);
	}
	for (int i = 0; str[i] != '\0'; i++){
		if (str[i] == ' ' || str[i] == '=' || str[i] == ',' || str[i] == '\n'){
			while (str[i] == ' ' || str[i] == '=' || str[i] == ',' || str[i] == '\n'){
				i++;
			}
			i--;
		}
		else{
			k = 0;
			while (str[i] != ' ' && str[i] != '\0' && str[i] != ',' && str[i] != '='&&str[i] != '\n'){
				x[j][k] = str[i];
				k = k + 1;
				i++;
			}
			x[j][k] = '\0';
			j = j + 1;
			i--;
		}
	}

	*len = j;
	//	for (int i = 0; i < *len; i++)
	//		printf("%s\n", x[i]);
	return x;
}
int to_num(char *s){
	int val = 0;
	for (int i = 0; s[i] != '\0'; i++){
		val = val * 10 + (s[i] - 48);
	}
	return val;
}