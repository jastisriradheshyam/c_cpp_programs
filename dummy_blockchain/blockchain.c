#include <stdio.h>  // printf
#include <stdlib.h> // rand
#include <time.h>   // time
#include <string.h> // strcat

#include "block.h"
#include "linked_list.h"

#define NVOTES 10

// extern is used because it is defined in a
// c file and will be defined in compile parameters
// during compilation
extern hash string_hash(void *string);

typedef enum party_code_t
{
    GOOD_PARTY,
    MEDIOCRE_PARTY,
    EVIL_PARTY,
    MAX_PARTIES
} party_code;
char *party_name[MAX_PARTIES] = {"GOOD PARTY", "MEDIOCRE_PARTY", "EVIL_PARTY"};

/**
 * get random voter
 */
static party_code get_vote()
{
    int r = rand();
    return r % MAX_PARTIES;
}

void main(int argc, char const *argv[])
{
    srand(time(NULL));

    NODE *head;
    DATA genesis_element;
    init(&head);

    // first block with hash 0
    transaction genesis_transactions = {party_name[get_vote()]};
    block_t genesis_block = {0, string_hash(genesis_transactions), genesis_transactions};
    genesis_element.info = genesis_block;
    head = add(head, genesis_element);

    // submit NVOTES random votes
    int i, previous_hash = genesis_element.info.previous_block_hash;
    transaction trans_list = (transaction)malloc(NVOTES * sizeof(char) * 10);
    for (i = 0; i < NVOTES; i++)
    {
        DATA *el = malloc(sizeof(DATA));
        block_t *b = malloc(sizeof(block_t));

        transaction t = {party_name[get_vote()]};
        strcat(trans_list, t);
        b->previous_block_hash = previous_hash;
        b->block_hash = string_hash(trans_list);
        b->transactions = t;
        el->info = *b;
        previous_hash = b->block_hash;
        head = add(head, *el);
    }

    print_list(head);
    return;
}