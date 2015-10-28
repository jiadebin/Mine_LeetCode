#include <stdio.h>
#include <string.h>

void func(char* str){
    int cursor = 0;     //新串游标
    bool needSpace = false;     //当前是否可以保留一个空格
    for(int i=0; str[i]; i++){
        if(str[i]!=' '){
            str[cursor++] = str[i];
            needSpace = true;
        }
        else if(needSpace){
            str[cursor++] = ' ';
            needSpace = false;
        }
    }
    if(cursor>0 && str[--cursor]==' ');     //判断末尾是否是一个空格，若是，无需其他操作，只需将cursor减一
    str[cursor] = '\0';
}

int main(){
    char str[] = " a b   c  d e  ";

    func(str);
    printf("%d\n", strlen(str));
    printf("%s\n", str);
    return 0;
}