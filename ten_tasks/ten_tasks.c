#include<stdlib.h>
#include<stdio.h>
#include<math.h>

const int ARR_SIZE = 100001;
const int TABLE_SIZE = 49;
const int SQUARE_SIZE = 100;
const int SIZE_STR = 100000;

void task_1A ();
void resheto (int fl[]);
void task_1B ();
void task_1C ();
void task_1D ();
void task_2A ();
void task_2B ();
int task_3C ();
void task_3D ();
void task_4A ();
int nod(int a, int b);
void task_4B ();

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

void resheto (int fl[])
{
    int i = 0, j = 0;
    for (i = 2; i < ARR_SIZE; i++)
    {
        if (fl[i] == 1)
        {
            for(j = (i+i); j < ARR_SIZE; j+=i)
                fl[j] = 0;
        }
    }
}

void task_1A()
{
    int fl[ARR_SIZE], num[10000];
    int i = 0, N = 0;

    scanf("%d", &N);

    for(i = 0; i < N; i++)
        scanf("%d", &num[i]);
    fl[0] = 0;
    fl[1] = 0;
    for (i = 2; i < ARR_SIZE; i++)
        fl[i] = 1;
    resheto(fl);

    for(i = 0; i < N; i++)
    {
        if (fl[num[i]] == 1)
            printf("%d ", num[i]);
    }
}

void task_1B()
{
    int k = 0;
    int i = 0;

    scanf("%d", &k);
    for (i = 2; i<= sqrt(k); i++)
    {
        if ((k%(i*i)) == 0)
        {
            printf("YES");
            break;
        }
    }
    if (i > sqrt(k))
        printf("NO");
}

void task_1C()
{
    int k = 0;

    scanf("%d", &k);
    while (k > 4)
    {
        if (k%4 == 2)
            break;
        else if (k%4 == 3)
        {
            k = (k+1)/4;
        }
        else
            k = k/4;
    }
    if (k%4 != 2)
        printf("YES");
    else
        printf("NO");
}

void task_1D()
{
    int k = 0;
    int good_word[TABLE_SIZE][TABLE_SIZE];
    int i = 0, j = 0;

    for (i = 0; i < TABLE_SIZE; i++)
    {
        good_word[i][0] = 1;
        for (j = 1; j < TABLE_SIZE; j++)
            good_word[i][j] = 0;
    }
    scanf("%d", &k);
    good_word[1][1] = 1;

    for (i = 2; i < k+1; i++)
        for (j = 1; j < TABLE_SIZE; j++)
            good_word[i][j] = good_word[i-1][j] + good_word[i-2][j-1];
    for (i = 0; i < k +1; i++)
    {
        for (j = 0; good_word[i][j] != 0; j++)
            printf("%d ", good_word[i][j]);
        printf("\n");
    }
}

void task_2A ()
{
    int *trans;
    int n = 0;
    int i = 0, j = 0;

    scanf("%d", &n);
    trans = (int *)calloc(n*n, sizeof(*trans));
    for (i = 0; i < n*n; i++)
        scanf("%d", &trans[i]);
    for (i = 0; i < n; i ++)
    {
        for (j = i; j < n*n; j += n)
            printf("%d ", trans[j]);
        printf ("\n");
    }
    free(trans);
}

void task_2B ()
{
  int i = 0;
    int a = 0, b = 0;
    int N = 0;

    scanf("%d", &N);
    for (i = sqrt(N); i > 0; i--)
    {
        if (N%(i*i) == 0)
        {
            b = i;
            break;
        }
    }
    a = N/(b*b);
    printf ("%d %d", a, b);
}

int task_3C ()
{
    int a = 0, b = 0, c = 0, d = 0;
    int sn = 0, i = 0;
    int n = 0;
    int *sqr;

    scanf("%d", &n);
    sn = sqrt(n) + 1;

    sqr = (int *)calloc(sn, sizeof(*sqr));
    for (i = 0; i < sn; i++)
        sqr[i] = i*i;

    for (a = 0; a < sn; a++)
        for (b = a; b < sn; b++)
            for (c = b; c < sn; c++)
            {
                d = sqrt(n-(sqr[a] + sqr[b] + sqr[c]));
                if ((sqr[a] + sqr[b] + sqr[c] + sqr[d]) == n)
                {
                    printf("%d %d %d %d", sqr[a], sqr[b], sqr[c], sqr[d]);
                    free(sqr);
                    return 0;
                }
            }
}

void task_3D ()
{
    int n = 0;
    char color[SQUARE_SIZE][SQUARE_SIZE];
    int square[SQUARE_SIZE][SQUARE_SIZE];
    int i = 0, j = 0, min_s = 0;
    int max_square = 0, max_i = 0, max_j = 0;

    for (i = 0; i < SQUARE_SIZE; i++)
        for (j = 0; j < SQUARE_SIZE; j++)
    {
        color[i][j] = ' ';
        square[i][j] = 0;
    }

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("\n");
        for (j = 0; j < n; j++)
            scanf("%c", &color[i][j]);
    }

    switch (color[0][0])
    {
    case '#':
        square[0][0] = 0;
        break;
    case '.':
        square[0][0] = 1;
        break;
    }
    for (i = 1; i < n; i++)
    {
        switch (color[0][i])
        {
        case '#':
            square[0][i] = 0;
            break;
        case '.':
            square[0][i] = 1;
            break;
        }
        switch (color[i][0])
        {
        case '#':
            square[i][0] = 0;
            break;
        case '.':
            square[i][0] = 1;
            break;
        }
    }

    for (i = 1; i < n; i++)
        for (j = 1; j < n; j++)
    {
        switch (color[i][j])
        {
        case '#':
            square[i][j] = 0;
            break;
        case '.':
            if (square[i][j-1] < square[i-1][j])
                min_s = square[i][j-1];
            else
                min_s = square[i-1][j];

            if (square[i-1][j-1] < min_s)
                square[i][j] = min_s;
            else
                square[i][j] = min_s + 1;
            break;
        }
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
    {
        if (square[i][j] > max_square)
        {
            max_square = square[i][j];
            max_i = i;
            max_j = j;
        }
    }

    printf("%d\n%d %d", max_square, max_j, max_i);
}

int nod(int a, int b)
{
    int c = 0;

    while (b != 0)
    {
        a = a%b;
        c = a;
        a = b;
        b = c;
    }
    return a;
}

void task_4A()
{
    int a = 0, b = 0, c = 0;
    int nok = 0;

    scanf("%d %d %d", &a, &b, &c);
    nok = a/nod(a,b)*b;
    nok = nok/nod(nok,c)*c;

    printf("%d", nok);
}

void task_4B()
{
    int c = 0, i = 0, j = 0;
    char str[SIZE_STR];

    while((c = getchar()) != EOF)
    {
        if((c == '\t') || (c == ' '))
        {
            if (j == 0)
            {
                str[i] = ' ';
                j++;
                i++;
            }
        }
        else
        {
            if((c >= '0') && (c <= '9'))
            {
                str[i] = '#';
                i++;
            }
            if((c >= 'A') && (c <= 'Z'))
            {
                str[i] = c + 'a' - 'A';
                i++;
            }
            if(((c >= 'a') && (c <= 'z')) || (c == '\n'))
            {
                str[i] = c;
                i++;
            }
            j = 0;
        }
    }

    for (j = 0; j < i; j++)
        printf("%c", str[j]);
}
