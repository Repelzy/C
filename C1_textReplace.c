#include <stdio.h>
#include <string.h>
#define MAX 1000

void replaceSub(char *p1, char *p2, char *s){
    char *ch = strstr(s,p1);
    int p1L = strlen(p1);
    int p2L = strlen(p2);
    int sL = strlen(s);
    char t[MAX];
    if(ch != NULL){
        strncpy(t, s, ch-s);
        t[ch-s] = '\0';
        strcat(t, p2);
        strcat(t, ch + p1L);
    }
    else return;
    int nSize = (sL - p1L) + p2L;
    if (nSize < MAX){
        strcpy(s, t);
        replaceSub(p1,p2,s);
    }
}

int main(){
    char p1[MAX], p2[MAX], t[MAX];
    fgets(p1, MAX, stdin);
    fgets(p2, MAX, stdin);
    fgets(t, MAX, stdin);
    p1[strlen(p1)- 1] = '\0';
    p2[strlen(p2)- 1] = '\0';
    replaceSub(p1, p2, t);
    printf("%s", t);
}