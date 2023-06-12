#include "generics.h"

// LIST(double_l, double)
// LIST(int_l, int)
// LIST(char_l, char)
// LIST(float_l, float)


STACK(int_s, int)
STACK(char_s, char)
STACK(float_s, float)
STACK(double_s, double)


QUEUE(int_q, int)
QUEUE(char_q, char)
QUEUE(float_q, float)
QUEUE(double_q, double)

VECTOR(int_v, int)
MAP(int_int_m, int, int)
MAP(double_int_m, double, int)

int is_odd(int key)
{
    return ((int)key%2==1);
}

#define print_dash printf("\n--------------------------------------------------------------------------------------------------------------------------------\n\n");
#define print_dashw printf("\n--------------------------------------------------------------------------------------------------------------------------------");
#define print_display printf("Display queue\n");
int main()
{
    
    //checking operations on generic queue container

    print_dash;
    printf("queue of double type\n\n");
    double_q l1;
    init_queue(double, l1);

    printf("enqueue : %f\n", 7.34);
    l1.enqueue(&l1, 7.34);
    printf("enqueue : %f\n", 6.2334);
    l1.enqueue(&l1, 6.2334);
    printf("enqueue : %f\n", 2.43);
    l1.enqueue(&l1, 2.43);
    printf("enqueue : %f\n", 9.443);
    l1.enqueue(&l1, 9.443);
    printf("enqueue : %f\n", 6.423);
    l1.enqueue(&l1, 6.423);
    printf("enqueue : %f\n", 1.254);
    l1.enqueue(&l1, 1.254);
    print_dash;
    print_display;
    l1.disp_queue(&l1);
    print_dash;
    printf("Dequeue\n");
    l1.dequeue(&l1);
    print_display;
    l1.disp_queue(&l1);
    print_dash;
    printf("enqueue : %f\n", 5.67);
    l1.enqueue(&l1,5.67);
    printf("enqueue : %f\n", 6.435);
    l1.enqueue(&l1,6.435);
    printf("enqueue : %f\n", 7.764);
    l1.enqueue(&l1,7.764);

    print_dash;
    print_display;
    l1.disp_queue(&l1);
    print_dash;

    double_q_iterator it_q_d;
    init_queue_iterator(double, l1, it_q_d);
    double min_q;
    int flag;
    double_q_iterator it_q_d_e = *(l1.end(&l1));
    print_dash;
    printf("Testing Iterators\n\n");
    min(it_q_d, it_q_d_e ,min_q,flag);
    if(flag==1)
    {
        printf("MIN: %lf\n\n",min_q);
    }

    double_q_iterator it2_q_d;
    init_queue_iterator(double, l1, it2_q_d);
    double max_q;
    int flag2;
    max(it2_q_d,it_q_d_e,max_q,flag2);
    if(flag2==1)
    {
        printf("MAX: %lf\n\n",max_q);
    }

    double_q_iterator it3_q_d;
    init_queue_iterator(double, l1, it3_q_d);
    double acc_q = 0;
    accumulate(it3_q_d,it_q_d_e,acc_q);
    printf("ACC: %lf\n\n",acc_q);
    
    double_q_iterator it4_q_d = *(l1.begin(&l1));
    double_q_iterator it5_q_d = *(l1.end(&l1));

    printf("Using Generic Algorithm Find on key %lf\n\n", 6.2334);
    find(it4_q_d, it5_q_d, 6.2334)
    if(it4_q_d.inequality(&it4_q_d, &it5_q_d))
    {
        printf("Found: %f\n\n", it4_q_d.get_value(&it4_q_d));
    }
    else
    {
        printf("Not Found\n\n");
    }
    
    printf("Using Generic Algorithm Find on key %lf\n\n", 6.34123);
    find(it4_q_d, it5_q_d, 6.34123)
    init_queue_iterator(double, l1, it3_q_d);
    if(it4_q_d.inequality(&it4_q_d, &it5_q_d))
    {
        printf("Found: %f\n\n", it4_q_d.get_value(&it4_q_d));
    }
    else
    {
        printf("Not Found\n\n");
    }
    print_dash;
    printf("Using advance to advance iterators for a different range to search for the key %lf in the queue\n\n", 5.67);
    double_q_iterator it6_q_d = *(l1.begin(&l1));
    it6_q_d.advance(&it6_q_d,2);

    double_q_iterator it7_q_d = *(l1.begin(&l1));
    it7_q_d.advance(&it7_q_d,6);

    find(it6_q_d, it7_q_d, 5.67)
    if(it6_q_d.inequality(&it6_q_d, &it7_q_d))
    {
        printf("advance Found: %f\n\n", it6_q_d.get_value(&it6_q_d));
    }
    else
    {
        printf("advance Not Found\n\n");
    }


    print_dash;
    double_q_iterator it;
    init_queue_iterator(double, l1, it6_q_d);
    double_q_iterator it8_q_d = *(l1.end(&l1));
    int count = 0;
    count(it6_q_d, it8_q_d, 6.2334, count);
    printf("Count: %d\n\n", count);
    count = 0;
    init_queue_iterator(double, l1, it6_q_d);
    it8_q_d = *(l1.end(&l1));
    count_if(it6_q_d, it8_q_d, is_odd, count);
    printf("Count If Odd: %d\n", count);

    print_dashw;
    print_dashw;
    print_dashw;
    print_dashw;
    print_dash;

    {
        printf("queue of int type\n\n");
        int_q l1;
        init_queue(int, l1);

        printf("enqueue : %d\n", 7);
        l1.enqueue(&l1, 7);
        printf("enqueue : %d\n", 6);
        l1.enqueue(&l1, 6);
        printf("enqueue : %d\n", 2);
        l1.enqueue(&l1, 2);
        printf("enqueue : %d\n", 9);
        l1.enqueue(&l1, 9);
        printf("enqueue : %d\n", 1);
        l1.enqueue(&l1, 1);
        printf("enqueue : %d\n", 5);
        l1.enqueue(&l1, 5);
        print_dash;
        print_display;
        l1.disp_queue(&l1);
        print_dash;
        printf("Dequeue\n");
        l1.dequeue(&l1);
        print_display;
        l1.disp_queue(&l1);
        print_dash;
        printf("enqueue : %d\n", 5);
        l1.enqueue(&l1,5);
        printf("enqueue : %d\n", 8);
        l1.enqueue(&l1,8);
        printf("enqueue : %d\n", 3);
        l1.enqueue(&l1,3);

        int_q_iterator it_q_d;
        init_queue_iterator(int, l1, it_q_d);
        int min_q;
        int flag;
        int_q_iterator it_q_d_e = *(l1.end(&l1));
        print_dash;
        printf("Testing Iterators\n\n");
        min(it_q_d, it_q_d_e ,min_q,flag);
        if(flag==1)
        {
            printf("MIN: %d\n\n",min_q);
        }

        int_q_iterator it2_q_d;
        init_queue_iterator(int, l1, it2_q_d);
        int max_q;
        int flag2;
        max(it2_q_d,it_q_d_e,max_q,flag2);
        if(flag2==1)
        {
            printf("MAX: %d\n\n",max_q);
        }

        int_q_iterator it3_q_d;
        init_queue_iterator(int, l1, it3_q_d);
        int acc_q = 0;
        accumulate(it3_q_d,it_q_d_e,acc_q);
        printf("ACC: %d\n\n",acc_q);
        
        int_q_iterator it4_q_d = *(l1.begin(&l1));
        int_q_iterator it5_q_d = *(l1.end(&l1));

        printf("Using Generic Algorithm Find on key %d\n\n", 6);
        find(it4_q_d, it5_q_d, 6)
        if(it4_q_d.inequality(&it4_q_d, &it5_q_d))
        {
            printf("Found: %d\n\n", it4_q_d.get_value(&it4_q_d));
        }
        else
        {
            printf("Not Found\n\n");
        }
        
        printf("Using Generic Algorithm Find on key %d\n\n", 16);
        find(it4_q_d, it5_q_d, 16)
        init_queue_iterator(int, l1, it3_q_d);
        if(it4_q_d.inequality(&it4_q_d, &it5_q_d))
        {
            printf("Found: %d\n\n", it4_q_d.get_value(&it4_q_d));
        }
        else
        {
            printf("Not Found\n\n");
        }
        print_dash;
        printf("Using advance to advance iterators for a different range to search for the key %d in the queue\n\n", 4);
        int_q_iterator it6_q_d = *(l1.begin(&l1));
        it6_q_d.advance(&it6_q_d,2);

        int_q_iterator it7_q_d = *(l1.begin(&l1));
        it7_q_d.advance(&it7_q_d,6);

        find(it6_q_d, it7_q_d, 4)
        if(it6_q_d.inequality(&it6_q_d, &it7_q_d))
        {
            printf("advance Found: %d\n\n", it6_q_d.get_value(&it6_q_d));
        }
        else
        {
            printf("advance Not Found\n\n");
        }


        print_dash;
        int_q_iterator it;
        init_queue_iterator(int, l1, it6_q_d);
        int_q_iterator it8_q_d = *(l1.end(&l1));
        int count = 0;
        count(it6_q_d, it8_q_d, 6, count);
        printf("Using Generic Algorithm Count on key %d\n\n", 6);
        printf("Count: %d\n\n", count);
        count = 0;
        init_queue_iterator(int, l1, it6_q_d);
        it8_q_d = *(l1.end(&l1));
        count_if(it6_q_d, it8_q_d, is_odd, count);
        printf("Count If Odd: %d\n", count);

        print_dashw;
        print_dashw;
        print_dashw;
        print_dashw;
        print_dash;
    }
    {
        printf("queue of char type\n\n");
        char_q l1;
        init_queue(char, l1);

        printf("enqueue : %c\n", 'A');
        l1.enqueue(&l1, 'A');
        printf("enqueue : %c\n", 'C');
        l1.enqueue(&l1, 'C');
        printf("enqueue : %c\n", 'V');
        l1.enqueue(&l1, 'V');
        printf("enqueue : %c\n", 'X');
        l1.enqueue(&l1, 'X');
        printf("enqueue : %c\n", 'F');
        l1.enqueue(&l1, 'F');
        printf("enqueue : %c\n", 'G');
        l1.enqueue(&l1, 'G');
        print_dash;
        print_display;
        l1.disp_queue(&l1);
        print_dash;
        printf("Dequeue\n");
        l1.dequeue(&l1);
        print_display;
        l1.disp_queue(&l1);
        print_dash;
        printf("enqueue : %c\n", 'G');
        l1.enqueue(&l1,'G');
        printf("enqueue : %c\n", 'Q');
        l1.enqueue(&l1,'Q');
        printf("enqueue : %c\n", 'H');
        l1.enqueue(&l1,'H');
        print_dash;
        print_display;
        l1.disp_queue(&l1);
        print_dashw;
        print_dash;
    }

    // float_q l4;
    // init_queue(float, l4);
    // l4.enqueue(&l4,12.4323f);
    // l4.enqueue(&l4,3.14f);
    // l4.disp_queue(&l4);



}