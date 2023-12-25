#include <iostream>

using namespace std;
struct Cqueue
{
    int size;
    int front;
    int rear;
    int *arr;
};
int isEmpty(struct Cqueue *q)
{
    if (q->front == q->rear)
        return 1;
    else
        return 0;
}
int isFull(struct Cqueue *q)
{
    if ((q->rear + 1) % q->size == q->front)
        return 1;
    else
        return 0;
}
void enqueue(struct Cqueue *q, int value)
{
    if (isFull(q))
        cout << "Queue is full" << endl;
    else
    {
        cout << "Enqueued element is:" << value << endl;
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = value;
    }
}
void dequeue(struct Cqueue *q)
{
    if (isEmpty(q))
        cout << "Queue is empty" << endl;
    else
    {
        q->front = (q->front + 1) % q->size;
        int dele = q->arr[q->front];
        cout << "Dequeued element is:" << dele << endl;
    }
}
int main()
{
    struct Cqueue *q = (struct Cqueue *)malloc(sizeof(struct Cqueue));
    q->size = 10;
    q->front = 0;
    q->rear = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));
    // int a=isFull(q);
    // int b=isEmpty(q);
    // cout<<a<<endl;
    // cout<<b<<endl;
    enqueue(q, 1);
    enqueue(q, 1);
    enqueue(q, 1);
    enqueue(q, 1);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    

    return 0;
}