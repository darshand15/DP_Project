// #define template(fn_name, TYPE, x, y )          \
//   TYPE fn_name( TYPE x, TYPE y ) \
//   {                                  \
//     return (x > y) ? x : y;          \
//   }

#include "test1_d.h"
// GENERIC_MAX(int)

// template(typename t1,..., fn_name)
// t1 fn_name()


// template(max, typdef typename t1, t2)
// t1 max(t2 a, t2 b)
// {
    
// }
// Vector(int_v, int)
// Vector(double_v, double)
// LIST(int_q, int)


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
VECTOR(char_v, char)
VECTOR(float_v, float)
VECTOR(double_v, double)
MAP(int_int_m, int, int)
MAP(double_int_m, double, int)

int is_odd(int key)
{
    return ((int)key%2==1);
}

#define print_dash printf("\n--------------------------------------------------------------------------------------------------------------------------------\n\n");
#define print_dashw printf("\n--------------------------------------------------------------------------------------------------------------------------------");
#define print_display printf("Display vector\n");
int main()
{
    
    //checking operations on generic vector container

    print_dash;
    printf("vector of double type\n\n");
    double_v l1;
    init_vector(double, 100, l1);
    printf("push_back : %f\n", 7.34);
    l1.push_back(&l1, 7.34);
    printf("push_back : %f\n", 6.2334);
    l1.push_back(&l1, 6.2334);
    printf("push_back : %f\n", 2.43);
    l1.push_back(&l1, 2.43);
    printf("push_back : %f\n", 9.443);
    l1.push_back(&l1, 9.443);
    printf("push_back : %f\n", 6.423);
    l1.push_back(&l1, 6.423);
    printf("push_back : %f\n", 1.254);
    l1.push_back(&l1, 1.254);
    print_dash;
    print_display;
    l1.disp_vector(&l1);
    print_dash;
    printf("Deleting Key : %f\n", 1.254);
    l1.pop_back(&l1);
    print_display;
    l1.disp_vector(&l1);
    print_dash;
    printf("push_back : %f\n", 5.67);
    l1.push_back(&l1,5.67);
    printf("push_back : %f\n", 6.435);
    l1.push_back(&l1,6.435);
    printf("push_back : %f\n", 7.764);
    l1.push_back(&l1,7.764);

    double_v_iterator it_v_d;
    init_vector_iterator(double, l1, it_v_d);
    double min_v;
    int flag;
    double_v_iterator it_v_d_e = *(l1.end(&l1));
    print_dash;
    printf("Testing Iterators\n\n");
    min(it_v_d, it_v_d_e ,min_v,flag);
    if(flag==1)
    {
        printf("MIN: %lf\n\n",min_v);
    }

    double_v_iterator it2_v_d;
    init_vector_iterator(double, l1, it2_v_d);
    double max_v;
    int flag2;
    max(it2_v_d,it_v_d_e,max_v,flag2);
    if(flag2==1)
    {
        printf("MAX: %lf\n\n",max_v);
    }

    double_v_iterator it3_v_d;
    init_vector_iterator(double, l1, it3_v_d);
    double acc_v = 0;
    accumulate(it3_v_d,it_v_d_e,acc_v);
    printf("ACC: %lf\n\n",acc_v);
    
    double_v_iterator it4_v_d = *(l1.begin(&l1));
    double_v_iterator it5_v_d = *(l1.end(&l1));

    printf("Using Generic Algorithm Find on key %lf\n\n", 6.2334);
    find(it4_v_d, it5_v_d, 6.2334)
    if(it4_v_d.inequality(&it4_v_d, &it5_v_d))
    {
        printf("Found: %f\n\n", it4_v_d.get_value(&it4_v_d));
    }
    else
    {
        printf("Not Found\n\n");
    }
    
    printf("Using Generic Algorithm Find on key %lf\n\n", 6.34123);
    find(it4_v_d, it5_v_d, 6.34123)
    init_vector_iterator(double, l1, it3_v_d);
    if(it4_v_d.inequality(&it4_v_d, &it5_v_d))
    {
        printf("Found: %f\n\n", it4_v_d.get_value(&it4_v_d));
    }
    else
    {
        printf("Not Found\n\n");
    }
    print_dash;
    printf("Using advance to advance iterators for a different range to search for the key %lf in\n\n", 5.67);
    double_v_iterator it6_v_d = *(l1.begin(&l1));
    it6_v_d.advance(&it6_v_d,2);

    double_v_iterator it7_v_d = *(l1.begin(&l1));
    it7_v_d.advance(&it7_v_d,6);

    find(it6_v_d, it7_v_d, 5.67)
    if(it6_v_d.inequality(&it6_v_d, &it7_v_d))
    {
        printf("advance Found: %f\n\n", it6_v_d.get_value(&it6_v_d));
    }
    else
    {
        printf("advance Not Found\n\n");
    }


    print_dash;
    double_v_iterator it;
    init_vector_iterator(double, l1, it6_v_d);
    double_v_iterator it8_v_d = *(l1.end(&l1));
    int count = 0;
    count(it6_v_d, it8_v_d, 6.2334, count);
    printf("Count: %d\n\n", count);
    count = 0;
    init_vector_iterator(double, l1, it6_v_d);
    it8_v_d = *(l1.end(&l1));
    count_if(it6_v_d, it8_v_d, is_odd, count);
    printf("Count If Odd: %d\n", count);

    print_dashw;
    print_dashw;
    print_dashw;
    print_dashw;
    print_dash;

    {
        printf("vector of int type\n\n");
        int_v l1;
        init_vector(int, 100, l1);
        printf("push_back : %d\n", 7);
        l1.push_back(&l1, 7);
        printf("push_back : %d\n", 6);
        l1.push_back(&l1, 6);
        printf("push_back : %d\n", 2);
        l1.push_back(&l1, 2);
        printf("push_back : %d\n", 9);
        l1.push_back(&l1, 9);
        printf("push_back : %d\n", 1);
        l1.push_back(&l1, 1);
        printf("push_back : %d\n", 5);
        l1.push_back(&l1, 5);
        print_dash;
        print_display;
        l1.disp_vector(&l1);
        print_dash;
        printf("Deleting Key : %d\n", 5);
        l1.pop_back(&l1);
        print_display;
        l1.disp_vector(&l1);
        print_dash;
        printf("push_back : %d\n", 5);
        l1.push_back(&l1,5);
        printf("push_back : %d\n", 8);
        l1.push_back(&l1,8);
        printf("push_back : %d\n", 3);
        l1.push_back(&l1,3);

        int_v_iterator it_v_d;
        init_vector_iterator(int, l1, it_v_d);
        int min_v;
        int flag;
        int_v_iterator it_v_d_e = *(l1.end(&l1));
        print_dash;
        printf("Testing Iterators\n\n");
        min(it_v_d, it_v_d_e ,min_v,flag);
        if(flag==1)
        {
            printf("MIN: %d\n\n",min_v);
        }

        int_v_iterator it2_v_d;
        init_vector_iterator(int, l1, it2_v_d);
        int max_v;
        int flag2;
        max(it2_v_d,it_v_d_e,max_v,flag2);
        if(flag2==1)
        {
            printf("MAX: %d\n\n",max_v);
        }

        int_v_iterator it3_v_d;
        init_vector_iterator(int, l1, it3_v_d);
        int acc_v = 0;
        accumulate(it3_v_d,it_v_d_e,acc_v);
        printf("ACC: %d\n\n",acc_v);
        
        int_v_iterator it4_v_d = *(l1.begin(&l1));
        int_v_iterator it5_v_d = *(l1.end(&l1));

        printf("Using Generic Algorithm Find on key %d\n\n", 6);
        find(it4_v_d, it5_v_d, 6)
        if(it4_v_d.inequality(&it4_v_d, &it5_v_d))
        {
            printf("Found: %d\n\n", it4_v_d.get_value(&it4_v_d));
        }
        else
        {
            printf("Not Found\n\n");
        }
        
        printf("Using Generic Algorithm Find on key %d\n\n", 16);
        find(it4_v_d, it5_v_d, 16)
        init_vector_iterator(int, l1, it3_v_d);
        if(it4_v_d.inequality(&it4_v_d, &it5_v_d))
        {
            printf("Found: %d\n\n", it4_v_d.get_value(&it4_v_d));
        }
        else
        {
            printf("Not Found\n\n");
        }
        print_dash;
        printf("Using advance to advance iterators for a different range to search for the key %d in\n\n", 4);
        int_v_iterator it6_v_d = *(l1.begin(&l1));
        it6_v_d.advance(&it6_v_d,2);

        int_v_iterator it7_v_d = *(l1.begin(&l1));
        it7_v_d.advance(&it7_v_d,6);

        find(it6_v_d, it7_v_d, 4)
        if(it6_v_d.inequality(&it6_v_d, &it7_v_d))
        {
            printf("advance Found: %d\n\n", it6_v_d.get_value(&it6_v_d));
        }
        else
        {
            printf("advance Not Found\n\n");
        }


        print_dash;
        int_v_iterator it;
        init_vector_iterator(int, l1, it6_v_d);
        int_v_iterator it8_v_d = *(l1.end(&l1));
        int count = 0;
        count(it6_v_d, it8_v_d, 6, count);
        printf("Count: %d\n\n", count);
        count = 0;
        init_vector_iterator(int, l1, it6_v_d);
        it8_v_d = *(l1.end(&l1));
        count_if(it6_v_d, it8_v_d, is_odd, count);
        printf("Count If Odd: %d\n", count);

        print_dashw;
        print_dashw;
        print_dashw;
        print_dashw;
        print_dash;
    }
    {
        printf("vector of char type\n\n");
        char_v l1;
        init_vector(char, 100, l1);
        printf("push_back : %c\n", 'A');
        l1.push_back(&l1, 'A');
        printf("push_back : %c\n", 'C');
        l1.push_back(&l1, 'C');
        printf("push_back : %c\n", 'V');
        l1.push_back(&l1, 'V');
        printf("push_back : %c\n", 'X');
        l1.push_back(&l1, 'X');
        printf("push_back : %c\n", 'F');
        l1.push_back(&l1, 'F');
        printf("push_back : %c\n", 'G');
        l1.push_back(&l1, 'G');
        print_dash;
        print_display;
        l1.disp_vector(&l1);
        print_dash;
        printf("Deleting Key : %c\n", 'G');
        l1.pop_back(&l1);
        print_display;
        l1.disp_vector(&l1);
        print_dash;
        printf("push_back : %c\n", 'G');
        l1.push_back(&l1,'G');
        printf("push_back : %c\n", 'Q');
        l1.push_back(&l1,'Q');
        printf("push_back : %c\n", 'H');
        l1.push_back(&l1,'H');
        print_dash;
        print_display;
        l1.disp_vector(&l1);
        print_dashw;
        print_dash;
    }

    // float_v l4;
    // init_vector(float, l4);
    // l4.push_back(&l4,12.4323f);
    // l4.push_back(&l4,3.14f);
    // l4.disp_vector(&l4);



}