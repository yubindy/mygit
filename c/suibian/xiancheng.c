#include<stdio.h>
#include<pthread.h>

int ticket_num=10000000;

void *sell_ticket(void *arg) {
    while(ticket_num>0) {
	ticket_num--;
    }
}

int main() {
    pthread_t t1,t2,t3;
    pthread_create(&t1, NULL, &sell_ticket, NULL);
    pthread_create(&t2, NULL, &sell_ticket, NULL);
    pthread_create(&t3, NULL, &sell_ticket, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    printf("ticket_num=%d\n", ticket_num);
    return 0;
}
