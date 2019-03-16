#ifndef STACK_H
#define STACK_H
template <typename E>
class Stack {
private:
    void operator =(const Stack&) {}
    Stack(const Stack& obj) {}
public:
    Stack() {}
    virtual ~Stack() {}
    virtual void push(E element) = 0;
    virtual E pop() = 0;
    virtual E topValue() = 0;
    virtual void clear() = 0;
    virtual bool isEmpty() = 0;
    virtual int getSize() = 0;
};

#endif // STACK_H
