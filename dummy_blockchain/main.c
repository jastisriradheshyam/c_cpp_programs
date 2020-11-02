typedef int hash;
typedef char *transaction;

typedef struct Block_T
{
    hash previous_block_hash;
    hash block_hash;
    transaction transactions;
} block_t;

typedef struct
{
    block_t info;
} DATA;

typedef struct node
{
    DATA data;
    struct node *next;
} NODE;

int string_hash(void *string)
{
    // djb2 string hash function
    int result = 5381;
    unsigned char *p;
    p = (unsigned char *)string;

    while (*p != '\0')
    {
        result = (result << 5) + result + *p;
        ++p;
    }
    return result;
}

NODE *add(NODE *node, DATA data);
void print_list(NODE *head);
NODE *reverse(NODE *node);
void get_list_transactions(NODE *head, unsigned char *list_trans);