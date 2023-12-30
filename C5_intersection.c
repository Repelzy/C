#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

typedef struct {
    ll first;
    ll second;
} Pair;

int compare(const void* a, const void* b) {
    Pair* pairA = (Pair*) a;
    Pair* pairB = (Pair*) b;
    return (pairA->first > pairB->first) - (pairA->first < pairB->first);
}

int main() {

    int n;
    scanf("%d", &n);
    Pair* v = malloc(n * sizeof(Pair)); 
    if (v == NULL) { 
        return 1;
    }
    for(int i = 0; i < n; i++){
        scanf("%d %d", &v[i].first, &v[i].second);
    }
    qsort(v, n, sizeof(Pair), compare);
    ll max_end = v[0].second;
    for(int i = 1; i < n; i++){ 
        if(v[i].first < max_end ) {
            printf("TRUE\n");
            free(v); 
            return 0;
        }
        max_end = (max_end > v[i].second) ? max_end : v[i].second;
    }
    printf("FALSE\n");
    free(v); 
    return 0;
}


// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// using ll = long long;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n;
//     cin >> n;
//     vector<pair<ll, ll>> v(n); 
//     for(int i = 0; i < n; i++){
//         cin >> v[i].first >> v[i].second;
//     }
//     sort(v.begin(), v.end());
//     ll max_end = v[0].second;
//     bool flag = false;
//     for(int i = 1; i < n; i++){ 
//         if(v[i].first < max_end ) {
//             cout << "TRUE";
//             return 0;
//         }
//         max_end = max(max_end, v[i].second);
//     }
//     cout<<"FALSE";
//     return 0;
// }
