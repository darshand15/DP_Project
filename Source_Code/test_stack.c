#include "generics.h"

// LIST(double_s, double)
// LIST(int_s, int)
// LIST(char_s, char)
// LIST(float_s, float)


STACK(int_s, int)
STACK(char_s, char)
STACK(float_s, float)
STACK(double_s, double)


QUEUE(int_q, int)
// QUEUE(char_q, char)
// QUEUE(float_q, float)
// QUEUE(double_q, double)

VECTOR(int_v, int)
MAP(int_int_m, int, int)
MAP(double_int_m, double, int)

int is_odd(int key)
{
    return ((int)key%2==1);
}

#define print_dash printf("\n--------------------------------------------------------------------------------------------------------------------------------\n\n");
#define print_dashw printf("\n--------------------------------------------------------------------------------------------------------------------------------");
#define print_display printf("Display Stack\n");
int main()
{
    
    //checking operations on generic Stack container

    print_dash;
    printf("Stack of double type\n\n");
    double_s l1;
    init_stack(double, l1);

    printf("Push : %f\n", 7.34);
    l1.push(&l1, 7.34);
    printf("Push : %f\n", 6.2334);
    l1.push(&l1, 6.2334);
    printf("Push : %f\n", 2.43);
    l1.push(&l1, 2.43);
    printf("Push : %f\n", 9.443);
    l1.push(&l1, 9.443);
    printf("Push : %f\n", 6.423);
    l1.push(&l1, 6.423);
    printf("Push : %f\n", 1.254);
    l1.push(&l1, 1.254);
    print_dash;
    print_display;
    l1.disp_stack(&l1);
    print_dash;
    printf("Pop\n");
    l1.pop(&l1);
    print_display;
    l1.disp_stack(&l1);
    print_dash;
    printf("Push : %f\n", 5.67);
    l1.push(&l1,5.67);
    printf("Push : %f\n", 6.435);
    l1.push(&l1,6.435);
    printf("Push : %f\n", 7.764);
    l1.push(&l1,7.764);

    print_dash;
    print_display;
    l1.disp_stack(&l1);
    print_dash;

    double_s_iterator it_s_d;
    init_stack_iterator(double, l1, it_s_d);
    double min_s;
    int flag;
    double_s_iterator it_s_d_e = *(l1.end(&l1));
    print_dash;
    printf("Testing Iterators\n\n");
    min(it_s_d, it_s_d_e ,min_s,flag);
    if(flag==1)
    {
        printf("MIN: %lf\n\n",min_s);
    }

    double_s_iterator it2_s_d;
    init_stack_iterator(double, l1, it2_s_d);
    double max_s;
    int flag2;
    max(it2_s_d,it_s_d_e,max_s,flag2);
    if(flag2==1)
    {
        printf("MAX: %lf\n\n",max_s);
    }

    double_s_iterator it3_s_d;
    init_stack_iterator(double, l1, it3_s_d);
    double acc_s = 0;
    accumulate(it3_s_d,it_s_d_e,acc_s);
    printf("ACC: %lf\n\n",acc_s);
    
    double_s_iterator it4_s_d = *(l1.begin(&l1));
    double_s_iterator it5_s_d = *(l1.end(&l1));

    printf("Using Generic Algorithm Find on key %lf\n\n", 6.2334);
    find(it4_s_d, it5_s_d, 6.2334)
    if(it4_s_d.inequality(&it4_s_d, &it5_s_d))
    {
        printf("Found: %f\n\n", it4_s_d.get_value(&it4_s_d));
    }
    else
    {
        printf("Not Found\n\n");
    }
    
    printf("Using Generic Algorithm Find on key %lf\n\n", 6.34123);
    find(it4_s_d, it5_s_d, 6.34123)
    init_stack_iterator(double, l1, it3_s_d);
    if(it4_s_d.inequality(&it4_s_d, &it5_s_d))
    {
        printf("Found: %f\n\n", it4_s_d.get_value(&it4_s_d));
    }
    else
    {
        printf("Not Found\n\n");
    }
    print_dash;
    printf("Using advance to advance iterators for a different range to search for the key %lf in the stack\n\n", 5.67);
    double_s_iterator it6_s_d = *(l1.begin(&l1));
    it6_s_d.advance(&it6_s_d,2);

    double_s_iterator it7_s_d = *(l1.begin(&l1));
    it7_s_d.advance(&it7_s_d,6);

    find(it6_s_d, it7_s_d, 5.67)
    if(it6_s_d.inequality(&it6_s_d, &it7_s_d))
    {
        printf("advance Found: %f\n\n", it6_s_d.get_value(&it6_s_d));
    }
    else
    {
        printf("advance Not Found\n\n");
    }


    print_dash;
    double_s_iterator it;
    init_stack_iterator(double, l1, it6_s_d);
    double_s_iterator it8_s_d = *(l1.end(&l1));
    int count = 0;
    count(it6_s_d, it8_s_d, 6.2334, count);
    printf("Using Generic Algorithm Count on key %f\n\n", 6.2334);
    printf("Count: %d\n\n", count);
    count = 0;
    init_stack_iterator(double, l1, it6_s_d);
    it8_s_d = *(l1.end(&l1));
    count_if(it6_s_d, it8_s_d, is_odd, count);
    printf("Count If Odd: %d\n", count);

    print_dashw;
    print_dashw;
    print_dashw;
    print_dashw;
    print_dash;

    {
        printf("Stack of int type\n\n");
        int_s l1;
        init_stack(int, l1);

        printf("Push : %d\n", 7);
        l1.push(&l1, 7);
        printf("Push : %d\n", 6);
        l1.push(&l1, 6);
        printf("Push : %d\n", 2);
        l1.push(&l1, 2);
        printf("Push : %d\n", 9);
        l1.push(&l1, 9);
        printf("Push : %d\n", 1);
        l1.push(&l1, 1);
        printf("Push : %d\n", 5);
        l1.push(&l1, 5);
        print_dash;
        print_display;
        l1.disp_stack(&l1);
        print_dash;
        printf("Pop\n");
        l1.pop(&l1);
        print_display;
        l1.disp_stack(&l1);
        print_dash;
        printf("Push : %d\n", 5);
        l1.push(&l1,5);
        printf("Push : %d\n", 8);
        l1.push(&l1,8);
        printf("Push : %d\n", 3);
        l1.push(&l1,3);

        print_dash;
        print_display;
        l1.disp_stack(&l1);
        print_dash;

        int_s_iterator it_s_d;
        init_stack_iterator(int, l1, it_s_d);
        int min_s;
        int flag;
        int_s_iterator it_s_d_e = *(l1.end(&l1));
        print_dash;
        printf("Testing Iterators\n\n");
        min(it_s_d, it_s_d_e ,min_s,flag);
        if(flag==1)
        {
            printf("MIN: %d\n\n",min_s);
        }

        int_s_iterator it2_s_d;
        init_stack_iterator(int, l1, it2_s_d);
        int max_s;
        int flag2;
        max(it2_s_d,it_s_d_e,max_s,flag2);
        if(flag2==1)
        {
            printf("MAX: %d\n\n",max_s);
        }

        int_s_iterator it3_s_d;
        init_stack_iterator(int, l1, it3_s_d);
        int acc_s = 0;
        accumulate(it3_s_d,it_s_d_e,acc_s);
        printf("ACC: %d\n\n",acc_s);
        
        int_s_iterator it4_s_d = *(l1.begin(&l1));
        int_s_iterator it5_s_d = *(l1.end(&l1));

        printf("Using Generic Algorithm Find on key %d\n\n", 6);
        find(it4_s_d, it5_s_d, 6)
        if(it4_s_d.inequality(&it4_s_d, &it5_s_d))
        {
            printf("Found: %d\n\n", it4_s_d.get_value(&it4_s_d));
        }
        else
        {
            printf("Not Found\n\n");
        }
        
        printf("Using Generic Algorithm Find on key %d\n\n", 16);
        find(it4_s_d, it5_s_d, 16)
        init_stack_iterator(int, l1, it3_s_d);
        if(it4_s_d.inequality(&it4_s_d, &it5_s_d))
        {
            printf("Found: %d\n\n", it4_s_d.get_value(&it4_s_d));
        }
        else
        {
            printf("Not Found\n\n");
        }
        print_dash;
        printf("Using advance to advance iterators for a different range to search for the key %d in the stack\n\n", 4);
        int_s_iterator it6_s_d = *(l1.begin(&l1));
        it6_s_d.advance(&it6_s_d,2);

        int_s_iterator it7_s_d = *(l1.begin(&l1));
        it7_s_d.advance(&it7_s_d,6);

        find(it6_s_d, it7_s_d, 4)
        if(it6_s_d.inequality(&it6_s_d, &it7_s_d))
        {
            printf("advance Found: %d\n\n", it6_s_d.get_value(&it6_s_d));
        }
        else
        {
            printf("advance Not Found\n\n");
        }


        print_dash;
        int_s_iterator it;
        init_stack_iterator(int, l1, it6_s_d);
        int_s_iterator it8_s_d = *(l1.end(&l1));
        int count = 0;
        count(it6_s_d, it8_s_d, 6, count);
        printf("Count: %d\n\n", count);
        count = 0;
        init_stack_iterator(int, l1, it6_s_d);
        it8_s_d = *(l1.end(&l1));
        count_if(it6_s_d, it8_s_d, is_odd, count);
        printf("Count If Odd: %d\n", count);

        print_dashw;
        print_dashw;
        print_dashw;
        print_dashw;
        print_dash;
    }
    {
        printf("Stack of char type\n\n");
        char_s l1;
        init_stack(char, l1);

        printf("Push : %c\n", 'A');
        l1.push(&l1, 'A');
        printf("Push : %c\n", 'C');
        l1.push(&l1, 'C');
        printf("Push : %c\n", 'V');
        l1.push(&l1, 'V');
        printf("Push : %c\n", 'X');
        l1.push(&l1, 'X');
        printf("Push : %c\n", 'F');
        l1.push(&l1, 'F');
        printf("Push : %c\n", 'G');
        l1.push(&l1, 'G');
        print_dash;
        print_display;
        l1.disp_stack(&l1);
        print_dash;
        printf("Pop\n");
        l1.pop(&l1);
        print_display;
        l1.disp_stack(&l1);
        print_dash;
        printf("Push : %c\n", 'G');
        l1.push(&l1,'G');
        printf("Push : %c\n", 'Q');
        l1.push(&l1,'Q');
        printf("Push : %c\n", 'H');
        l1.push(&l1,'H');
        print_dash;
        print_display;
        l1.disp_stack(&l1);
        print_dashw;
        print_dash;
    }

    // float_s l4;
    // init_stack(float, l4);
    // l4.push(&l4,12.4323f);
    // l4.push(&l4,3.14f);
    // l4.disp_stack(&l4);



}