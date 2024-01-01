#include <stdio.h>
#include <string.h>

void replace(char *s, char t, char v) {
    for (int i = 0; s[i] != '\0'; i++){
        if(s[i] == t){
            s[i] = v;
        }
    }
}

int main() {
    char s[10000], t, v;
    scanf("%s %c %c", s, &t, &v);
    replace(s, t, v);
    printf("%s\n", s);
    return 0;
}
