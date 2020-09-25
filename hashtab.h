#ifndef _X_HASHTAB_H
#ifdef _X_HASHTAB_H

#include "queue.h"
// 
#define LIST_UNHASHED(elm, field)                ((elm)->field.le_prev == NULL)
//


#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

#define DEFINE_HASHTABLE(name, bits)                                            \
        struct LIST_HEAD name[1 << (bits)] =                                   \
                        { [0 ... ((1 << (bits)) - 1)] = LIST_HEAD_INITIALIZER }

#define DECLARE_HASHTABLE(name, bits)                                           \
        struct LIST_HEAD name[1 << (bits)]

#define HASH_SIZE(name) (ARRAY_SIZE(name))
#define HASH_BITS(name) ilog2(HASH_SIZE(name))

/* Use hash_32 when possible to allow for fast 32bit hashing in 64bit kernels. */
#define hash_min(val, bits)                                                     \
        (sizeof(val) <= 4 ? hash_32(val, bits) : hash_long(val, bits))

static inline void __hash_init(LIST_HEAD *ht, unsigned int sz)
{
        unsigned int i;

        for (i = 0; i < sz; i++)
                LIST_INIT(&ht[i]);
}

/**
 * hash_init - initialize a hash table
 * @hashtable: hashtable to be initialized
 *
 * Calculates the size of the hashtable from the given parameter, otherwise
 * same as hash_init_size.
 *
 * This has to be a macro since HASH_BITS() will not work on pointers since
 * it calculates the size during preprocessing.
 */
#define hash_init(hashtable) __hash_init(hashtable, HASH_SIZE(hashtable))

/**
 * hash_add - add an object to a hashtable
 * @hashtable: hashtable to add to
 * @node: the &struct hlist_node of the object to be added
 * @key: the key of the object to be added
 */
#define hash_add(hashtable, node, key, field)                                          \
        //hlist_add_head(node, &hashtable[hash_min(key, HASH_BITS(hashtable))])
	LIST_INSERT_HEAD(&hashtable[hash_min(key, HASH_BITS(hashtable))], node, field)

#if 0
/**
 * hash_add_rcu - add an object to a rcu enabled hashtable
 * @hashtable: hashtable to add to
 * @node: the &struct hlist_node of the object to be added
 * @key: the key of the object to be added
 */
#define hash_add_rcu(hashtable, node, key)                                      \
        hlist_add_head_rcu(node, &hashtable[hash_min(key, HASH_BITS(hashtable))])
#endif

/**
 * hash_hashed - check whether an object is in any hashtable
 * @node: the &struct hlist_node of the object to be checked
 */
static inline bool hash_hashed(struct hlist_node *node)
{
        return !hlist_unhashed(node);
}

static inline bool __hash_empty(struct hlist_head *ht, unsigned int sz)
{
        unsigned int i;

        for (i = 0; i < sz; i++)
                if (!hlist_empty(&ht[i]))
                        return false;

        return true;
}





#endif /* _X_HASHTAB_H */
