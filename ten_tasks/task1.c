#include "ten_tasks.h"

int main()
{
    int n = 0;
    printf("Hello! It's solves of ten tasks here. They are:\n\
1. task A\n\
2. task B\n\
3. task C\n\
4. task D\n\
    of variant 1\n\
5. task A\n\
6. task B\n\
    of variant 2\n\
7. task C\n\
8. task D\n\
    of variant 3\n\
9. task A\n\
10. task B\n\
    of variant 4\n\n\
All tasks are from \"test_main(2007)\".\n\n\
Enter the number of task to test:\n");

    scanf("%d", &n);
    switch(n)
    {
    case 1:
        task_1A();
        break;
    case 2:
        task_1B();
        break;
    case 3:
        task_1C();
        break;
    case 4:
        task_1D();
        break;
    case 5:
        task_2A();
        break;
    case 6:
        task_2B();
        break;
    case 7:
        task_3C();
        break;
    case 8:
        task_3D();
        break;
    case 9:
        task_4A();
        break;
    case 10:
        task_4B();
        break;
    }

    return 0;
}
