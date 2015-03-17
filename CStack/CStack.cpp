#include"CStack.h"

CStack::CStack():
    data(new int[10]),
    count(0),
    max(10),
    fail_alloc(OK)
    {
        if(this->data == NULL)
            fail_alloc = ERR_ALLOC;
        else
            memset(this->data, 0, sizeof(int)*10);
    }

CStack::CStack(const int size):
    data(NULL),
    count(0),
    max(0),
    fail_alloc(OK)
    {
        if(size > 0)
        {
            this->data = new int[size];
            if(this->data == NULL)
                fail_alloc = ERR_ALLOC;
            else
            {
                this->max = size;
                memset(data, 0, sizeof(int)*size);
            }
        }
        else
        {
            this->data = new int[10];
            this->fail_alloc = FALSE_SIZE;
            if(this->data == NULL)
                fail_alloc = ERR_ALLOC;
            else
            {
                memset(this->data, 0, sizeof(int)*10);
                this->max = 10;
            }
        }
    }

ERROR_ST CStack::push(const int val)
{
    if(this->fail_alloc == ERR_ALLOC)
        return ERR_ALLOC;
    if(this->count == this->max)
    {
        int i = 0;
        int * mass = new int[max * 2];
        if(mass == NULL)
        {
            this->fail_alloc = ERR_ALLOC;
            delete [] mass;
            return ERR_ALLOC;
        }
        memset(mass, 0, sizeof(int) * this->max * 2);
        for(i = 0; i < this->max; i++)
            mass[i] = this->data[i];
        delete [] this->data;
        this->data = mass;
        this->max *= 2;
    }
    this->data[count] = val;
    this->count ++;

    return OK;
}

ERROR_ST CStack::pop(int * val)
{
    if(this->data == NULL)
        return ERR_ALLOC;
    if(this->count == 0)
        return ERR_EMPTY;

    *val = this->data[this->count - 1];
    this->count --;
    this->data[count] = 0;
    return OK;
}

ERROR_ST CStack::top(int * val)
{
    if(this->data == NULL)
        return ERR_ALLOC;
    if(this->count == 0)
        return ERR_EMPTY;
    *val = this->data[this->count -  1];
    return OK;
}

int CStack::c_size()
{
    return this->count;
}

CStack::~CStack()
{
    delete [] this->data;
    this->data = NULL;
    this->count = -13;
    this->max = -13;
    this->fail_alloc = OK;
}

void CStack::dump() const
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
    std::cout << "data = [" << this->data << "]" << std::endl;
    std::cout << "count = " << this->count << std::endl;
    std::cout << "max = " << this->max << std::endl;

    for(i = 0; i < this->count; i++)
        std::cout << "st[" << i << "] = " << this->data[i] << " *" << std::endl;
    for(i = this->count; (i < this->count + 3)&&(i < this->max); i++)
        std::cout << "st[" << i << "] = " << this->data[i] << std::endl;
    std::cout << std::endl;
}
