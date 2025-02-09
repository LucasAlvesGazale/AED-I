#include <stdio.h>
#include <string.h>

int findPosition(char *infix, char c, int start, int end) {
    for (int i = start; i <= end; i++) {
        if (infix[i] == c) {
            return i;
        }
    }
    return -1;
}

void buildPostfix(char *prefix, char *infix, int start, int end, int *preIndex, char *postfix, int *postIndex) {
    if (start > end) {
        return;
    }

    char current = prefix[*preIndex];
    (*preIndex)++;

    int position = findPosition(infix, current, start, end);

    buildPostfix(prefix, infix, start, position - 1, preIndex, postfix, postIndex);
    buildPostfix(prefix, infix, position + 1, end, preIndex, postfix, postIndex);

    postfix[*postIndex] = current;
    (*postIndex)++;
}

int main() {
    int C;
    scanf("%d", &C);

    while (C--) {
        int N;
        char prefix[53], infix[53];
        scanf("%d %s %s", &N, prefix, infix);

        char postfix[53] = {0};
        int preIndex = 0, postIndex = 0;

        buildPostfix(prefix, infix, 0, N - 1, &preIndex, postfix, &postIndex);

        postfix[postIndex] = '\0';
        printf("%s\n", postfix);
    }

    return 0;
}
