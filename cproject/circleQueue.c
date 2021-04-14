#include <stdio.h>

#define MAX_INDEX 10

int queue[MAX_INDEX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (front == -1 && rear == -1) {
        front = 0;
    }
    else if (rear == MAX_INDEX - 1) {
        rear = -1;
    }
    queue[++rear] = x;
    return;
}

int dequeue() {
    int retval = queue[front];
    if (front == rear) {
        front = rear = -1; /* initialize */
        return retval;
    }
    else if (front == rear) {
        front = rear = -1; /* initialize */
        return retval;
    }
    ++front;
    return retval;
}

int queue_full() {
    return ((front == 0 && rear == MAX_INDEX - 1) || front == rear + 1);
}

int queue_empty() {
    return(front == -1);
}

int main() {
    int choose = 1;
    while (choose) {
        scanf("%d", &choose);
        switch (choose) {
        case 1:
        {
            if (queue_full()) {
                printf("overflow\n");
                break;
            }
            else {
                int x;
                scanf("%d", &x);
                enqueue(x);
                break;
            }
        }
        case 2:
        {
            if (queue_empty()) {
                printf("underflow\n");
                break;
            }
            else {
                int retval = dequeue();
                printf("%d is dequeued\n", retval);
                break;
            }
        }
        case 0:
            break;
        }
    }
    return 0;
}