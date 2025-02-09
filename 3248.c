#include <stdio.h>

#define MAX 100005

long long fenwick[MAX];

long long sum(long long idx) {
    long long result = 0;
    while (idx > 0) {
        result += fenwick[idx];
        idx -= idx & -idx;  
    }
    return result;
}

void add(long long idx, long long value) {
    while (idx < MAX) {
        fenwick[idx] += value;
        idx += idx & -idx; 
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n+1];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    long long count = 0;
    long long leftCount[MAX] = {0};
    long long rightCount[MAX] = {0};
    
    for (int j = 1; j <= n; j++) {
        if (arr[j] < MAX) {
            leftCount[j] = sum(MAX - 1) - sum(arr[j]);
        }
        
        add(arr[j], 1);
    }
    
    for (int i = 0; i < MAX; i++) {
        fenwick[i] = 0;
    }
    
    for (int j = n; j >= 1; j--) {
        if (arr[j] > 1) {
            rightCount[j] = sum(arr[j] - 1);
        }
        
        add(arr[j], 1);
    }
    
    for (int j = 1; j <= n; j++) {
        count += leftCount[j] * rightCount[j];
    }

    printf("%lld\n", count);
    
    return 0;
}
