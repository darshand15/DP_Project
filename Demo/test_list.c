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
// LIST(int_l, int)


LIST(double_l, double)
LIST(int_l, int)
LIST(char_l, char)
LIST(float_l, float)


STACK(int_s, int)
// STACK(char_s, char)
// STACK(float_s, float)
// STACK(double_s, double)


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
#define print_display printf("Display List\n");
int main()
{
    
    //checking operations on generic list container

    print_dash;
    printf("List of double type\n\n");
    double_l l1;
    init_list(double, l1);

    printf("Insert at Beginning : %f\n", 7.34);
    l1.insert_at_beg(&l1, 7.34);
    printf("Insert at end : %f\n", 6.2334);
    l1.insert_at_end(&l1, 6.2334);
    printf("Insert at end : %f\n", 2.43);
    l1.insert_at_end(&l1, 2.43);
    printf("Insert at end : %f\n", 9.443);
    l1.insert_at_end(&l1, 9.443);
    printf("Insert at end : %f\n", 6.423);
    l1.insert_at_end(&l1, 6.423);
    printf("Insert at Beginning : %f\n", 1.254);
    l1.insert_at_beg(&l1, 1.254);
    print_dash;
    print_display;
    l1.disp_list(&l1);
    print_dash;
    printf("Deleting Key : %f\n", 7.34);
    l1.delete_key(&l1, 7.34);
    print_display;
    l1.disp_list(&l1);
    print_dash;
    printf("Insert at end : %f\n", 5.67);
    l1.insert_at_end(&l1,5.67);
    printf("Insert at end : %f\n", 6.435);
    l1.insert_at_end(&l1,6.435);
    printf("Insert at end : %f\n", 7.764);
    l1.insert_at_end(&l1,7.764);

    double_l_iterator it_l_d;
    init_list_iterator(double, l1, it_l_d);
    double min_l;
    int flag;
    double_l_iterator it_l_d_e = *(l1.end(&l1));
    print_dash;
    printf("Testing Iterators\n\n");
    min(it_l_d, it_l_d_e ,min_l,flag);
    if(flag==1)
    {
        printf("MIN: %lf\n\n",min_l);
    }

    double_l_iterator it2_l_d;
    init_list_iterator(double, l1, it2_l_d);
    double max_l;
    int flag2;
    max(it2_l_d,it_l_d_e,max_l,flag2);
    if(flag2==1)
    {
        printf("MAX: %lf\n\n",max_l);
    }

    double_l_iterator it3_l_d;
    init_list_iterator(double, l1, it3_l_d);
    double acc_l = 0;
    accumulate(it3_l_d,it_l_d_e,acc_l);
    printf("ACC: %lf\n\n",acc_l);
    
    double_l_iterator it4_l_d = *(l1.begin(&l1));
    double_l_iterator it5_l_d = *(l1.end(&l1));

    printf("Using Generic Algorithm Find on key %lf\n\n", 6.2334);
    find(it4_l_d, it5_l_d, 6.2334)
    if(it4_l_d.inequality(&it4_l_d, &it5_l_d))
    {
        printf("Found: %f\n\n", it4_l_d.get_value(&it4_l_d));
    }
    else
    {
        printf("Not Found\n\n");
    }
    
    printf("Using Generic Algorithm Find on key %lf\n\n", 6.34123);
    find(it4_l_d, it5_l_d, 6.34123)
    init_list_iterator(double, l1, it3_l_d);
    if(it4_l_d.inequality(&it4_l_d, &it5_l_d))
    {
        printf("Found: %f\n\n", it4_l_d.get_value(&it4_l_d));
    }
    else
    {
        printf("Not Found\n\n");
    }
    print_dash;
    printf("Using advance to advance iterators for a different range to search for the key %lf in\n\n", 5.67);
    double_l_iterator it6_l_d = *(l1.begin(&l1));
    it6_l_d.advance(&it6_l_d,2);

    double_l_iterator it7_l_d = *(l1.begin(&l1));
    it7_l_d.advance(&it7_l_d,6);

    find(it6_l_d, it7_l_d, 5.67)
    if(it6_l_d.inequality(&it6_l_d, &it7_l_d))
    {
        printf("advance Found: %f\n\n", it6_l_d.get_value(&it6_l_d));
    }
    else
    {
        printf("advance Not Found\n\n");
    }


    print_dash;
    double_l_iterator it;
    init_list_iterator(double, l1, it6_l_d);
    double_l_iterator it8_l_d = *(l1.end(&l1));
    int count = 0;
    count(it6_l_d, it8_l_d, 6.2334, count);
    printf("Count: %d\n\n", count);
    count = 0;
    init_list_iterator(double, l1, it6_l_d);
    it8_l_d = *(l1.end(&l1));
    count_if(it6_l_d, it8_l_d, is_odd, count);
    printf("Count If Odd: %d\n", count);

    print_dashw;
    print_dashw;
    print_dashw;
    print_dashw;
    print_dash;

    {
        printf("List of int type\n\n");
        int_l l1;
        init_list(int, l1);

        printf("Insert at Beginning : %d\n", 7);
        l1.insert_at_beg(&l1, 7);
        printf("Insert at end : %d\n", 6);
        l1.insert_at_end(&l1, 6);
        printf("Insert at end : %d\n", 2);
        l1.insert_at_end(&l1, 2);
        printf("Insert at end : %d\n", 9);
        l1.insert_at_end(&l1, 9);
        printf("Insert at end : %d\n", 1);
        l1.insert_at_end(&l1, 1);
        printf("Insert at Beginning : %d\n", 5);
        l1.insert_at_beg(&l1, 5);
        print_dash;
        print_display;
        l1.disp_list(&l1);
        print_dash;
        printf("Deleting Key : %d\n", 7);
        l1.delete_key(&l1, 7);
        print_display;
        l1.disp_list(&l1);
        print_dash;
        printf("Insert at end : %d\n", 5);
        l1.insert_at_end(&l1,5);
        printf("Insert at end : %d\n", 8);
        l1.insert_at_end(&l1,8);
        printf("Insert at end : %d\n", 3);
        l1.insert_at_end(&l1,3);

        int_l_iterator it_l_d;
        init_list_iterator(int, l1, it_l_d);
        int min_l;
        int flag;
        int_l_iterator it_l_d_e = *(l1.end(&l1));
        print_dash;
        printf("Testing Iterators\n\n");
        min(it_l_d, it_l_d_e ,min_l,flag);
        if(flag==1)
        {
            printf("MIN: %d\n\n",min_l);
        }

        int_l_iterator it2_l_d;
        init_list_iterator(int, l1, it2_l_d);
        int max_l;
        int flag2;
        max(it2_l_d,it_l_d_e,max_l,flag2);
        if(flag2==1)
        {
            printf("MAX: %d\n\n",max_l);
        }

        int_l_iterator it3_l_d;
        init_list_iterator(int, l1, it3_l_d);
        int acc_l = 0;
        accumulate(it3_l_d,it_l_d_e,acc_l);
        printf("ACC: %d\n\n",acc_l);
        
        int_l_iterator it4_l_d = *(l1.begin(&l1));
        int_l_iterator it5_l_d = *(l1.end(&l1));

        printf("Using Generic Algorithm Find on key %d\n\n", 6);
        find(it4_l_d, it5_l_d, 6)
        if(it4_l_d.inequality(&it4_l_d, &it5_l_d))
        {
            printf("Found: %d\n\n", it4_l_d.get_value(&it4_l_d));
        }
        else
        {
            printf("Not Found\n\n");
        }
        
        printf("Using Generic Algorithm Find on key %d\n\n", 16);
        find(it4_l_d, it5_l_d, 16)
        init_list_iterator(int, l1, it3_l_d);
        if(it4_l_d.inequality(&it4_l_d, &it5_l_d))
        {
            printf("Found: %d\n\n", it4_l_d.get_value(&it4_l_d));
        }
        else
        {
            printf("Not Found\n\n");
        }
        print_dash;
        printf("Using advance to advance iterators for a different range to search for the key %d in\n\n", 4);
        int_l_iterator it6_l_d = *(l1.begin(&l1));
        it6_l_d.advance(&it6_l_d,2);

        int_l_iterator it7_l_d = *(l1.begin(&l1));
        it7_l_d.advance(&it7_l_d,6);

        find(it6_l_d, it7_l_d, 4)
        if(it6_l_d.inequality(&it6_l_d, &it7_l_d))
        {
            printf("advance Found: %d\n\n", it6_l_d.get_value(&it6_l_d));
        }
        else
        {
            printf("advance Not Found\n\n");
        }


        print_dash;
        int_l_iterator it;
        init_list_iterator(int, l1, it6_l_d);
        int_l_iterator it8_l_d = *(l1.end(&l1));
        int count = 0;
        count(it6_l_d, it8_l_d, 6, count);
        printf("Using Generic Algorithm Count on key %d\n\n", 6);
        printf("Count: %d\n\n", count);
        count = 0;
        init_list_iterator(int, l1, it6_l_d);
        it8_l_d = *(l1.end(&l1));
        count_if(it6_l_d, it8_l_d, is_odd, count);
        printf("Count If Odd: %d\n", count);

        print_dashw;
        print_dashw;
        print_dashw;
        print_dashw;
        print_dash;
    }
    {
        printf("List of char type\n\n");
        char_l l1;
        init_list(char, l1);

        printf("Insert at Beginning : %c\n", 'A');
        l1.insert_at_beg(&l1, 'A');
        printf("Insert at end : %c\n", 'C');
        l1.insert_at_end(&l1, 'C');
        printf("Insert at end : %c\n", 'V');
        l1.insert_at_end(&l1, 'V');
        printf("Insert at end : %c\n", 'X');
        l1.insert_at_end(&l1, 'X');
        printf("Insert at end : %c\n", 'F');
        l1.insert_at_end(&l1, 'F');
        printf("Insert at Beginning : %c\n", 'G');
        l1.insert_at_beg(&l1, 'G');
        print_dash;
        print_display;
        l1.disp_list(&l1);
        print_dash;
        printf("Deleting Key : %c\n", 'A');
        l1.delete_key(&l1, 'A');
        print_display;
        l1.disp_list(&l1);
        print_dash;
        printf("Insert at end : %c\n", 'G');
        l1.insert_at_end(&l1,'G');
        printf("Insert at end : %c\n", 'Q');
        l1.insert_at_end(&l1,'Q');
        printf("Insert at end : %c\n", 'H');
        l1.insert_at_end(&l1,'H');
        print_dash;
        print_display;
        l1.disp_list(&l1);
        print_dashw;
        print_dash;
    }

    // float_l l4;
    // init_list(float, l4);
    // l4.insert_at_end(&l4,12.4323f);
    // l4.insert_at_beg(&l4,3.14f);
    // l4.disp_list(&l4);



}