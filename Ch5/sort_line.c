#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 2 //进行排序的最大文本行数

char *lineptr[MAXLINE]; //指向文本行的指针数组

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort_(char *lineptr[], int left, int right);

int main(){
    int nlines;

    if((nlines = readlines(lineptr, MAXLINE)) >= 0){
        //printf("nlines = %d\n", nlines);
        qsort_(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        writelines(lineptr, nlines);
        return 1;
    }
    return 0;
}

#define MAXLEN 100 //每个输入文本行的最大长度
int getline_(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = getline_(line, MAXLEN)) > 0){
        if(nlines >= maxlines || (p = malloc(len)) == NULL){
            //printf("-1 returned.\n");
            return -1;
        } else {
            line[len] = '\0'; //删除换行符
            strcpy(p, line);
            //printf("p: %s\n", p);
            //printf("%d\n", nlines);
            lineptr[nlines++] = p;
        }
    }
    //printf("nlines: %d\n", nlines);
    return nlines;
}

void writelines(char *lineptr[], int nlines){
    int i;

    for(i = 0; i < nlines; i++){
        printf("%s\n", lineptr[i]);
    }
}

int getline_(char *s, int lim){
    int c, i;

    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++){
        s[i] = c;
    }
    if(c == '\n'){
        s[i] = c;
        c++;
    }
    s[i] = '\0';
    return i;
}

void qsort_(char *v[], int left, int right){
    int i, last;
    void swap(char *v[], int i, int j);

    if(left >= right) //当数组元素小于两个时，返回
        return;

    swap(v, left, (left+right)/2);
    last = left;
    for(i = left + 1; i <= right; i++){
        if(strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }
    swap(v, left, last);
    qsort_(v, left, last);
    qsort_(v, last + 1, right);
}

void swap(char *v[], int i, int j){
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}