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
Vector(int_v, int)
Vector(double_v, double)
// LIST(int_l, int)
LIST(double_l, double)

int main()
{
    // double_v x.pushback(68)
    // int_l l1;
    // init_list(&l1);
    // insert_at_beg(&l1, 3);
    // disp_list(&l1);

    double_l l2;
    init_list(&l2);
    insert_at_beg(&l2, 7.34);
    disp_list(&l2);



}