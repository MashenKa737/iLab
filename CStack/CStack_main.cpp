#include"CStack.h"

int main()
{
    CStack st(1);
    int i = 0;
    int a = 0;
    st.dump();
    st.pop(&a);
    std::cout << " a = " << i << std::endl;
    st.dump();
    for(i = 1; i <= 4; i++)
        st.push(i);
    st.dump();
    st.pop(&a);
    std::cout << "a = " << a << std::endl;
    st.top(&a);
    std::cout << "top = " << a << "\nsize = " << st.c_size() << std::endl;
    st.push(777);
    st.dump();
    for(i = 1; i < 9; i++)
    {
        st.pop(&a);
        st.top(&a);
        std::cout << "top = " << a << "\nsize = " << st.c_size() << std::endl;
    }
    st.dump();

    return 0;
}
