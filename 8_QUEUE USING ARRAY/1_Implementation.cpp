#include <iostream>

using namespace std;
struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};
int isEmpty(struct queue *q)
{
    if (q->front == q->rear)
        return 1;

    else
        return 0;
}
int isFull(struct queue *q)
{
    if (q->rear == q->size - 1)
        return 1;

    else
        return 0;
}
void enqueue(struct queue *q, int value)
{
    if (isFull(q))
    {
        cout << "your queue is full" << endl;
    }
    else
    {
        q->rear = q->rear + 1;
        cout << "the enqueued element is:" << value << endl;
        q->arr[q->rear] = value;
    }
}
void dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        cout << "your queue is empty" << endl;
    }
    else
    {
        q->front++;
        int a = q->arr[q->front];
        cout << "the dequeued element is:" << a << endl;
    }
}

void showqueue(struct queue *q)

{
    if (isEmpty(q))
    {
        cout << "the queue is empty:" << endl;
        return;
    }

    cout << "the updated queue:" << endl;
    for (int i = q->front + 1; i <= q->rear; i++)
    {
        cout << q->arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 10;
    q->front = q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
    enqueue(q, 1);
    enqueue(q, 12);
    enqueue(q, 13);
    enqueue(q, 10);
    enqueue(q, 13);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    showqueue(q);

    return 0;
}