// check if block structure is defined elsewere by using
// header file convention 

#ifndef BLOCK_H
#define BLOCK_H

typedef int hash;
typedef char *transaction;

typedef struct Block_T {
    hash previous_block_hash;
    hash block_hash;
    transaction transactions;
} block_t;

#endif