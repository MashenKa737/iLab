#include<iostream>
#include<string.h>
#include<string>

enum ERROR_ST{OK, ERR_ALLOC, ERR_EMPTY, FALSE_SIZE};

class CStack
{
public:
    CStack();
    CStack(const int size);
    ~CStack();
    ERROR_ST push(const int val);
    ERROR_ST pop(int * val);
    ERROR_ST top(int * val);
    int c_size();
    void dump() const;
private:
    int *data;
    int count;
    int max;
    ERROR_ST fail_alloc;
};
