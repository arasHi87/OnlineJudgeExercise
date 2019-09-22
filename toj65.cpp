#include <ctime>
#include <cstdio>
#include <cstdlib>
int main() {
    srand(clock());
    printf("%d\n", rand()%2);
}