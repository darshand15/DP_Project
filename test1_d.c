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
STACK(char_s, char)
STACK(float_s, float)
STACK(double_s, double)


QUEUE(int_q, int)
QUEUE(char_q, char)
QUEUE(float_q, float)
QUEUE(double_q, double)



int main()
{
    
    //checking operations on generic list container

    // double_l l1;
    // init_list(double, l1);
    // l1.insert_at_beg(&l1, 7.34);
    // l1.insert_at_end(&l1, 6.2334);
    // l1.insert_at_beg(&l1, 1.254);
    // l1.disp_list(&l1);
    // l1.delete_key(&l1, 7.34);
    // l1.disp_list(&l1);
    // l1.insert_at_end(&l1,5.67);
    // l1.insert_at_end(&l1,6.435);
    // l1.insert_at_end(&l1,7.764);
    // disp_list_double(&l1);

    // int_l l2;
    // init_list(int, l2);
    // l2.insert_at_end(&l2,5);
    // l2.insert_at_end(&l2,3);
    // l2.insert_at_end(&l2,7);
    // disp_list_int(&l2);
    // l2.insert_at_beg(&l2, 5);
    // l2.insert_at_end(&l2, 3);
    // l2.insert_at_beg(&l2, 7);
    // l2.disp_list(&l2);
    // l2.delete_key(&l2, 8);
    // l2.disp_list(&l2);

    // char_l l3;
    // init_list(char, l3);
    // l3.insert_at_beg(&l3,'A');
    // l3.insert_at_beg(&l3,'B');
    // l3.disp_list(&l3);

    // float_l l4;
    // init_list(float, l4);
    // l4.insert_at_end(&l4,12.4323f);
    // l4.insert_at_beg(&l4,3.14f);
    // l4.disp_list(&l4);


    //checking operations on generic stack container
    
    // int_s s1;
    // init_stack(int, s1);
    // s1.push(&s1,4);
    // s1.push(&s1,1);
    // s1.push(&s1,9);
    // s1.disp_stack(&s1);
    // s1.pop(&s1);
    // s1.disp_stack(&s1);
    // printf("PEEK - %d\n\n",s1.peek_stack(&s1));

    // char_s s2;
    // init_stack(char, s2);
    // s2.push(&s2,'A');
    // s2.push(&s2,'L');
    // s2.disp_stack(&s2);
    // s2.pop(&s2);
    // s2.pop(&s2);
    // s2.pop(&s2);
    // s2.disp_stack(&s2);
    // printf("PEEK - %c\n\n",s2.peek_stack(&s2));

    // float_s s3;
    // init_stack(float, s3);
    // s3.pop(&s3);
    // s3.push(&s3, 3.14f);
    // s3.disp_stack(&s3);
    // printf("PEEK - %f\n\n",s3.peek_stack(&s3));

    // double_s s4;
    // init_stack(double, s4);
    // s4.push(&s4,12.43234);
    // s4.push(&s4,1141.3435);
    // s4.disp_stack(&s4);
    // s4.pop(&s4);
    // s4.disp_stack(&s4);
    // printf("PEEK - %lf\n\n",s4.peek_stack(&s4));


    //checking operations on generic queue container

    int_q q1;
    init_queue(int, q1);
    q1.enqueue(&q1,3);
    q1.enqueue(&q1,7);
    q1.enqueue(&q1,2);
    q1.disp_queue(&q1);
    q1.dequeue(&q1);
    q1.dequeue(&q1);
    q1.disp_queue(&q1);
    printf("PEEK - %d\n\n",q1.peek_queue(&q1));

    char_q q2;
    init_queue(char, q2);
    q2.enqueue(&q2,'Q');
    q2.disp_queue(&q2);
    q2.dequeue(&q2);
    q2.disp_queue(&q2);
    printf("PEEK - %c\n\n",q2.peek_queue(&q2));

    float_q q3;
    init_queue(float, q3);
    q3.dequeue(&q3);
    q3.disp_queue(&q3);
    q3.enqueue(&q3, 4524.34f);
    q3.enqueue(&q3, 12.43234f);
    q3.disp_queue(&q3);
    printf("PEEK - %f\n\n",q3.peek_queue(&q3));

    double_q q4;
    init_queue(double, q4);
    q4.enqueue(&q4,12.43);
    q4.enqueue(&q4,234.536);
    q4.disp_queue(&q4);
    printf("PEEK - %lf\n\n",q4.peek_queue(&q4));



}