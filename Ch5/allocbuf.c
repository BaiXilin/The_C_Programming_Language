#define ALLOCSIZE 10000 /* 可用空间大小 */

static char allocbuf[ALLOCSIZE]; /* 储存空间 */
static char *allocp = allocbuf; /* 下一个空闲空间 */

char *alloc(int n){ /* 返回指向n个字符的指针 */
    if(allocbuf + ALLOCSIZE - allocp >= n){
        allocp += n;
        return allocp - n;
    } else {
        return 0;
    }
}

void afree(char *p){ /* 释放p指向的储存区 */
    if(p >= allcobuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

