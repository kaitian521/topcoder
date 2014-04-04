#include <iostream>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
using namespace std;
const int N = 5000000;
char buff[N];
int main()
{
    int ntowrite, nwrite, i;
    char *ptr;
    for (i = 0; i < N; i++) buff[i] = i;
    ntowrite = N;
    nwrite = 0;

    set_fl(STDOUT_FILENO, O_NONBLOCK);

    return 0;
}
