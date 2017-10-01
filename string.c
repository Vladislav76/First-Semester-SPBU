#include <stdio.h>
int strlen(char* s) {
	int length = 0;
	while (s[length] != '\0') {
		length++;
	}
	return length;
}
void strcpy(char* dst, char* src) {
	int i = 0;
	while (src[i] != '\0') {
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}
void strcat(char* dst, char* src) {
	int i = 0; int j = 0;
	while (dst[i] != '\0') {
		i++;
	}
	while (src[j] != '\0') {
		dst[i] = src[j];
		i++; 
		j++;
	}
	dst[i] = '\0';
}
int strcmp(char* s1, char* s2) {
	int i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0') {
		i++;
	}
	if (s1[i] == s2[i]) {
		return 0;
	} 
	else if (s1[i] < s2[i]) {
		return -1;
	} 
	else {
		return 1;
	}
}
int main() {
	return 0;
}