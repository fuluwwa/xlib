#ifndef _X_TYPES_H
#define _X_TYPES_H

typedef signed   char                   int8_t;      /**<  8bit integer type */
typedef signed   short                  int16_t;     /**< 16bit integer type */
typedef signed   long                   int32_t;     /**< 32bit integer type */
typedef signed long long                int64_t;     /**< 64bit integer type */
typedef unsigned char                   uint8_t;     /**<  8bit unsigned integer type */
typedef unsigned short                  uint16_t;    /**< 16bit unsigned integer type */
typedef unsigned long                   uint32_t;    /**< 32bit unsigned integer type */
typedef unsigned long long              uint64_t;    /**< 64bit unsigned integer type */

typedef int                             bool_t;      /**< boolean type */

/* 32bit CPU */
typedef long                            base_t;      /**< Nbit CPU related date type */
typedef unsigned long                   ubase_t;     /**< Nbit unsigned CPU related data type */
typedef ubase_t                      size_t;      /**< Type for size number */
typedef base_t                       off_t;       /**< Type for offset */

typedef uint8_t		u8;
typedef uint16_t	u16;
typedef uint32_t	u32;
typedef uint64_t	u64;

/* boolean type definitions */
#define RT_TRUE                         1               /**< boolean true  */
#define RT_FALSE                        0               /**< boolean fails */

/**@}*/

/* maximum value of base type */
#define RT_UINT8_MAX                    0xff            /**< Maxium number of UINT8 */
#define RT_UINT16_MAX                   0xffff          /**< Maxium number of UINT16 */
#define RT_UINT32_MAX                   0xffffffff      /**< Maxium number of UINT32 */



#define POISON_POINTER_DELTA 0
/*
 * These are non-NULL pointers that will result in page faults
 * under normal circumstances, used to verify that nobody uses
 * non-initialized list entries.
 */
#define LIST_POISON1  ((void *) 0x00100100 + POISON_POINTER_DELTA)
#define LIST_POISON2  ((void *) 0x00200200 + POISON_POINTER_DELTA)



struct list_head {
        struct list_head *next, *prev;
};

struct hlist_head {
        struct hlist_node *first;
};

struct hlist_node {
        struct hlist_node *next, **pprev;
};

#endif /* _X_TYPES_H */
