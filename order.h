/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   order.h
 * Author: igor
 *
 * Created on 4 de Setembro de 2020, 19:59
 */

#ifndef ORDER_H
#define ORDER_H

#ifdef __cplusplus
extern "C" {
#endif

struct node
{
    int data;
    struct node *next;
};
struct node ** findSmallest(struct node ** head);



#ifdef __cplusplus
}
#endif

#endif /* ORDER_H */

