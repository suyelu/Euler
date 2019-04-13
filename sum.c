/*************************************************************************
	> File Name: sum.c
	> Author: 
	> Mail: 
	> Created Time: Sat 02 Mar 2019 09:43:44 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int end, now, start, sum;
void *add() {
    while (now <= end) {
        sum += now;
        now++;
    }
}


int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("./a.out num num_of_pthread!\n");
        return 1;
    }
    int num_of_pthread = 0;
    num_of_pthread = atoi(argv[2]);
    end = atoi(argv[1]);
    pthread_t tid[num_of_pthread];
    now =0;
    sum = 0;
    for (int i = 0; i < num_of_pthread; ++i) {
        pthread_create(&tid[i], NULL, add, NULL);
    }
    
    for (int i = 0; i < num_of_pthread; ++i) {
        pthread_join(tid[i], NULL);
    }

    printf("sum = %d\n", sum);

    return 0;
}

