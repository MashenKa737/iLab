#ifndef DEFINE_CSTACK_H
#define DEFINE_CSTACK_H

#include<iostream>
#include<string.h>
#include<string>

enum ERROR_ST{OK, ERR_ALLOC, ERR_EMPTY, FALSE_SIZE};

template <typename Data_T>
class CStack
{
public:
    CStack();
    CStack(const int size);
    ~CStack();
    ERROR_ST push(const Data_T val);
    ERROR_ST pop(Data_T & val);
    ERROR_ST top(Data_T & val);
    int c_size();
    void dump() const;
private:
    Data_T *data;
    int count;
    int max;
    ERROR_ST fail_alloc;
};

template <typename Data_T>
CStack<Data_T>::CStack():
    data(new Data_T[1]),
    count(0),
    max(10),
    fail_alloc(OK)
    {
        if(this->data == NULL)
            fail_alloc = ERR_ALLOC;
        else
            memset(this->data, 0, sizeof(Data_T)*10);
    }

template <typename Data_T>
CStack<Data_T>::CStack(const int size):
    data(NULL),
    count(0),
    max(0),
    fail_alloc(OK)
    {
        if(size > 0)
        {
            this->data = new Data_T[size];
            if(this->data == NULL)
                fail_alloc = ERR_ALLOC;
            else
            {
                this->max = size;
                memset(data, 0, sizeof(Data_T)*size);
            }
        }
        else
        {
            this->data = new Data_T[10];
            this->fail_alloc = FALSE_SIZE;
            if(this->data == NULL)
                fail_alloc = ERR_ALLOC;
            else
            {
                memset(this->data, 0, sizeof(Data_T)*10);
                this->max = 10;
            }
        }
    }

template <typename Data_T>
ERROR_ST CStack<Data_T>::push(const Data_T val)
{
    if(this->fail_alloc == ERR_ALLOC)
        return ERR_ALLOC;
    if(this->count == this->max)
    {
        Data_T * mass = new Data_T[max * 2];
        if(mass == NULL)
        {
            this->fail_alloc = ERR_ALLOC;
            delete [] mass;
            return ERR_ALLOC;
        }
        memset(mass, 0, sizeof(Data_T) * this->max * 2);
        for(int i = 0; i < this->max; i++)
            mass[i] = this->data[i];
        delete [] this->data;
        this->data = mass;
        this->max *= 2;
    }
    this->data[count] = val;
    this->count ++;

    return OK;
}

template <typename Data_T>
ERROR_ST CStack<Data_T>::pop(Data_T & val)
{
    if(this->data == NULL)
        return ERR_ALLOC;
    if(this->count == 0)
        return ERR_EMPTY;

    val = this->data[this->count - 1];
    this->count --;
    return OK;
}

template <typename Data_T>
ERROR_ST CStack<Data_T>::top(Data_T & val)
{
    if(this->data == NULL)
        return ERR_ALLOC;
    if(this->count == 0)
        return ERR_EMPTY;
    val = this->data[this->count -  1];
    return OK;
}

template <typename Data_T>
int CStack<Data_T>::c_size()
{
    return this->count;
}

template <typename Data_T>
CStack<Data_T>::~CStack()
{
    //std::cout << "deleting...\n";
    delete [] this->data;
    this->data = NULL;
    this->fail_alloc = OK;
}

template <typename Data_T>
void CStack<Data_T>::dump() const
{
    int i = 0;
    switch(this->fail_alloc)
    {
    case OK:
        break;
    case ERR_ALLOC:
        std::cout << "Error allocated memory" << std::endl;
        break;
    case FALSE_SIZE:
        std::cout << "Memory is allocated by standard size" << std::endl;
        break;
    default:
        break;
    }
    std::cout << "data = [" << (void*) this->data << "]" << std::endl;
    std::cout << "count = " << this->count << std::endl;
    std::cout << "max = " << this->max << std::endl;

    for(i = 0; i < this->count; i++)
        std::cout << "st[" << i << "] = " << this->data[i] << " *" << std::endl;
    for(i = this->count; (i < this->count + 3)&&(i < this->max); i++)
        std::cout << "st[" << i << "] = " << this->data[i] << std::endl;
    std::cout << std::endl;
}

#endif // DEFINE_CSTACK
