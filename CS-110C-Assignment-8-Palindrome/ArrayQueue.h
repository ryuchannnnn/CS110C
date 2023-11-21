#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H



class ArrayQueue
{
  private:
    static const int maxSize = 50;
    char queue[maxSize];
    int front;
    int back;
    int count;
  public:
    ArrayQueue()
    {
      front = 0;
      back = maxSize - 1;
      count = 0;
    }
    bool isEmpty();
	  bool enqueue(char item);
	  bool dequeue();
	  char peekFront();
};
#endif