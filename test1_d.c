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

int main()
{
    // double_v x.pushback(68)
    // int_l l1;
    // init_list(&l1);
    // insert_at_beg(&l1, 3);
    // disp_list(&l1);

    double_l l1;
    init_list(double, l1);
    // insert_at_beg_double(&l1, 7.34);
    // insert_at_end_double(&l1, 6.2334);
    // insert_at_beg_double(&l1, 1.254);
    // disp_list_double(&l1);
    // delete_key_double(&l1, 7.34);
    // disp_list_double(&l1);
    insert_at_end(l1,5.67);
    insert_at_end(l1,6.435);
    insert_at_end(l1,7.764);
    disp_list_double(&l1);

    int_l l2;
    init_list(int, l2);
    insert_at_end(l2,5);
    insert_at_end(l2,3);
    insert_at_end(l2,7);
    disp_list_int(&l2);
    // insert_at_beg_int(&l2, 5);
    // insert_at_end_int(&l2, 3);
    // insert_at_beg_int(&l2, 7);
    // disp_list_int(&l2);
    // delete_key_int(&l2, 8);
    // disp_list_int(&l2);

    char_l l3;
    init_list(char, l3);

    float_l l4;
    init_list(float, l4);

}