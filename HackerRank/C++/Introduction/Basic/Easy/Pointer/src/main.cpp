#include <cstdio>
#include <stdexcept>

void update(int *a, int *b) {
    // Complete this function
    if (!a || !b) throw std::invalid_argument("Null argumernt(s)");

    int aOrig = *a;
    *a += *b;
    *b = std::abs(aOrig - *b);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", pa, pb);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}


/*
void increment(int *v) {
    (*v)++;
}

int main() {
    int a;
    scanf("%d", &a);
    increment(&a);
    printf("%d\n", a);
    return 0;
}
*/
