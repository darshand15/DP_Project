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
VECTOR(char_v, char)
VECTOR(float_v, float)
VECTOR(double_v, double)
MAP(int_int_m, int, int)
MAP(double_int_m, double, int)
MAP(int_double_m, int, double)

int is_odd(int key)
{
    return ((int)key%2==1);
}

#define print_dash printf("\n--------------------------------------------------------------------------------------------------------------------------------\n\n");
#define print_dashw printf("\n--------------------------------------------------------------------------------------------------------------------------------");
#define print_display printf("Display map\n");
int main()
{
    
    //checking operations on generic map container

    print_dash;
    printf("map of int to int type\n\n");
    int_int_m l1;
    init_map(int, int, 100, l1);
    printf("insert_map : %d : %d\n", 7, 14);
    l1.insert_map(&l1, 7, 14);
    printf("insert_map : %d : %d\n", 6, 12);
    l1.insert_map(&l1, 6, 12);
    printf("insert_map : %d : %d\n", 2, 4);
    l1.insert_map(&l1, 2, 4);
    printf("insert_map : %d : %d\n", 9, 18);
    l1.insert_map(&l1, 9, 18);
    printf("insert_map : %d : %d\n", 8, 16);
    l1.insert_map(&l1, 8, 16);
    printf("insert_map : %d : %d\n", 4, 8);
    l1.insert_map(&l1, 4, 8);
    print_dash;
    print_display;
    l1.disp_map(&l1);
    print_dash;
    printf("Deleting Key : %d\n", 1);
    l1.delete_map(&l1, 1);
    print_display;
    l1.disp_map(&l1);
    print_dash;
    printf("insert_map : %d : %d\n", 5, 10);
    l1.insert_map(&l1, 5, 10);
    printf("insert_map : %d : %d\n", 12, 24);
    l1.insert_map(&l1, 12, 24);
    printf("insert_map : %d : %d\n", 18, 36);
    l1.insert_map(&l1, 18, 36);

    int_int_m_iterator it_m_d;
    init_map_iterator(int, int, l1, it_m_d);
    int min_m;
    int flag;
    int_int_m_iterator it_m_d_e = *(l1.end(&l1));
    print_dash;
    printf("Testing Iterators\n\n");
    min(it_m_d, it_m_d_e ,min_m,flag);
    if(flag==1)
    {
        printf("MIN: %d\n\n",min_m);
    }

    int_int_m_iterator it2_m_d;
    init_map_iterator(int, int, l1, it2_m_d);
    int max_m;
    int flag2;
    max(it2_m_d,it_m_d_e,max_m,flag2);
    if(flag2==1)
    {
        printf("MAX: %d\n\n",max_m);
    }

    int_int_m_iterator it3_m_d;
    init_map_iterator(int, int, l1, it3_m_d);
    int acc_m = 0;
    accumulate(it3_m_d,it_m_d_e,acc_m);
    printf("ACC: %d\n\n",acc_m);
    
    int_int_m_iterator it4_m_d = *(l1.begin(&l1));
    int_int_m_iterator it5_m_d = *(l1.end(&l1));

    printf("Using Generic Algorithm Find on key %lf\n\n", 6);
    find(it4_m_d, it5_m_d, 6)
    if(it4_m_d.inequality(&it4_m_d, &it5_m_d))
    {
        printf("Found: %d\n\n", it4_m_d.get_value(&it4_m_d));
    }
    else
    {
        printf("Not Found\n\n");
    }
    
    printf("Using Generic Algorithm Find on key %d\n\n", 19);
    find(it4_m_d, it5_m_d, 19)
    init_map_iterator(int, int, l1, it3_m_d);
    if(it4_m_d.inequality(&it4_m_d, &it5_m_d))
    {
        printf("Found: %f\n\n", it4_m_d.get_value(&it4_m_d));
    }
    else
    {
        printf("Not Found\n\n");
    }
    print_dash;
    printf("Using advance to advance iterators for a different range to search for the key %d in\n\n", 5);
    int_int_m_iterator it6_m_d = *(l1.begin(&l1));
    it6_m_d.advance(&it6_m_d,2);

    int_int_m_iterator it7_m_d = *(l1.begin(&l1));
    it7_m_d.advance(&it7_m_d,6);

    find(it6_m_d, it7_m_d, 5.67)
    if(it6_m_d.inequality(&it6_m_d, &it7_m_d))
    {
        printf("advance Found: %d\n\n", it6_m_d.get_value(&it6_m_d));
    }
    else
    {
        printf("advance Not Found\n\n");
    }


    print_dash;
    int_int_m_iterator it;
    init_map_iterator(int, int, l1, it6_m_d);
    int_int_m_iterator it8_m_d = *(l1.end(&l1));
    int count = 0;
    count(it6_m_d, it8_m_d, 6, count);
    printf("Using Generic Algorithm Count on key %d\n\n", 6);
    printf("Count: %d\n\n", count);
    count = 0;
    init_map_iterator(int, int, l1, it6_m_d);
    it8_m_d = *(l1.end(&l1));
    count_if(it6_m_d, it8_m_d, is_odd, count);
    printf("Count If Odd: %d\n", count);

    print_dashw;
    print_dashw;
    print_dashw;
    print_dashw;
    print_dash;

    {
        printf("map of int type\n\n");
        int_double_m l1;
        init_map(int, double, 100, l1);

        printf("insert_map : %d : %f\n", 7, 49.0);
        l1.insert_map(&l1, 7, 49.0);
        printf("insert_map : %d : %f\n", 6, 36.0);
        l1.insert_map(&l1, 6, 36.0);
        printf("insert_map : %d : %f\n", 2, 4.0);
        l1.insert_map(&l1, 2, 4.0);
        printf("insert_map : %d : %f\n", 9, 81.0);
        l1.insert_map(&l1, 9, 81.0);
        printf("insert_map : %d : %f\n", 1, 1.0);
        l1.insert_map(&l1, 1, 1.0);
        printf("insert_map : %d : %f\n", 5, 25.0);
        l1.insert_map(&l1, 5, 25.0);
        print_dash;
        print_display;
        l1.disp_map(&l1);
        print_dash;
        printf("Deleting Key : %d\n", 5);
        l1.delete_map(&l1, 5);
        print_display;
        l1.disp_map(&l1);
        print_dash;
        printf("insert_map : %d : %f\n", 12, 144.0);
        l1.insert_map(&l1,12, 144.0);
        printf("insert_map : %d : %f\n", 8, 64.0);
        l1.insert_map(&l1,8, 64.0);
        printf("insert_map : %d : %f\n", 3, 9.0);
        l1.insert_map(&l1,3, 9.0);

        int_double_m_iterator it_m_d;
        init_map_iterator(int, double, l1, it_m_d);
        int min_m;
        int flag;
        int_double_m_iterator it_m_d_e = *(l1.end(&l1));
        print_dash;
        printf("Testing Iterators\n\n");
        min(it_m_d, it_m_d_e , min_m, flag);
        if(flag==1)
        {
            printf("MIN: %d\n\n", min_m);
        }

        int_double_m_iterator it2_m_d;
        init_map_iterator(int, double, l1, it2_m_d);
        int max_m;
        int flag2;
        max(it2_m_d,it_m_d_e,max_m,flag2);
        if(flag2==1)
        {
            printf("MAX: %d\n\n",max_m);
        }

        int_double_m_iterator it3_m_d;
        init_map_iterator(int, double, l1, it3_m_d);
        int acc_m = 0;
        accumulate(it3_m_d,it_m_d_e,acc_m);
        printf("ACC: %d\n\n",acc_m);
        
        int_double_m_iterator it4_m_d = *(l1.begin(&l1));
        int_double_m_iterator it5_m_d = *(l1.end(&l1));

        printf("Using Generic Algorithm Find on key %d\n\n", 6);
        find(it4_m_d, it5_m_d, 6)
        if(it4_m_d.inequality(&it4_m_d, &it5_m_d))
        {
            printf("Found: %d\n\n", it4_m_d.get_value(&it4_m_d));
        }
        else
        {
            printf("Not Found\n\n");
        }
        
        printf("Using Generic Algorithm Find on key %d\n\n", 16);
        find(it4_m_d, it5_m_d, 16)
        init_map_iterator(int, double, l1, it3_m_d);
        if(it4_m_d.inequality(&it4_m_d, &it5_m_d))
        {
            printf("Found: %f\n\n", it4_m_d.get_value(&it4_m_d));
        }
        else
        {
            printf("Not Found\n\n");
        }
        print_dash;
        printf("Using advance to advance iterators for a different range to search for the key %d in\n\n", 9);
        int_double_m_iterator it6_m_d = *(l1.begin(&l1));
        it6_m_d.advance(&it6_m_d,2);

        int_double_m_iterator it7_m_d = *(l1.begin(&l1));
        it7_m_d.advance(&it7_m_d,6);

        find(it6_m_d, it7_m_d, 9)
        if(it6_m_d.inequality(&it6_m_d, &it7_m_d))
        {
            printf("advance Found: %d\n\n", it6_m_d.get_value(&it6_m_d));
        }
        else
        {
            printf("advance Not Found\n\n");
        }


        print_dash;
        int_double_m_iterator it;
        init_map_iterator(int, double, l1, it6_m_d);
        int_double_m_iterator it8_m_d = *(l1.end(&l1));
        int count = 0;
        count(it6_m_d, it8_m_d, 6, count);
        printf("Using Generic Algorithm Count on key %d\n\n", 6);
        printf("Count: %d\n\n", count);
        count = 0;
        init_map_iterator(int, double, l1, it6_m_d);
        it8_m_d = *(l1.end(&l1));
        count_if(it6_m_d, it8_m_d, is_odd, count);
        printf("Count If Odd: %d\n", count);

        print_dashw;
        print_dash;
    }
    // {
    //     printf("map of char type\n\n");
    //     char_m l1;
    //     init_map(char, l1);

    //     l1.make_new_dynamic_table(&l1, 100);
    //     printf("insert_map : %c\n", 'A');
    //     l1.insert_map(&l1, 'A');
    //     printf("insert_map : %c\n", 'C');
    //     l1.insert_map(&l1, 'C');
    //     printf("insert_map : %c\n", 'V');
    //     l1.insert_map(&l1, 'V');
    //     printf("insert_map : %c\n", 'X');
    //     l1.insert_map(&l1, 'X');
    //     printf("insert_map : %c\n", 'F');
    //     l1.insert_map(&l1, 'F');
    //     printf("insert_map : %c\n", 'G');
    //     l1.insert_map(&l1, 'G');
    //     print_dash;
    //     print_display;
    //     l1.disp_map(&l1);
    //     print_dash;
    //     printf("Deleting Key : %c\n", 'G');
    //     l1.pop_back(&l1);
    //     print_display;
    //     l1.disp_map(&l1);
    //     print_dash;
    //     printf("insert_map : %c\n", 'G');
    //     l1.insert_map(&l1,'G');
    //     printf("insert_map : %c\n", 'Q');
    //     l1.insert_map(&l1,'Q');
    //     printf("insert_map : %c\n", 'H');
    //     l1.insert_map(&l1,'H');
    //     print_dash;
    //     print_display;
    //     l1.disp_map(&l1);
    //     print_dashw;
    //     print_dash;
    // }

    // float_m l4;
    // init_map(float, l4);
    // l4.insert_map(&l4,12.4323f);
    // l4.insert_map(&l4,3.14f);
    // l4.disp_map(&l4);



}