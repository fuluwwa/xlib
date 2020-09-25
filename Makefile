CC = gcc   #代表所使用的编译器
#static library use 'ar' command 
AR = ar

SRCS = $(wildcard *.c )    #wildcard把 指定目录 ./ 和 ../lib 下的所有后缀是c的文件全部展开。

OBJS = $(patsubst %.c, %.o,$(SRCS)) 

INCLUDES = -I. 
LIBDIR = -L.
LIBS=

CCFLAGS = -g -Wall -O0 -fPIC #for x86-64 libs compile

# compile lib.so lib.a
LIB-SHARE=libbtree.so
LIB-STATIC=libbtree.a

OUTPUT = main

all:$(OUTPUT) 

%.o : %.c
	$(CC) -c $< $(CCFLAGS)

$(OUTPUT) : $(OBJS)
	$(CC) $^ -o $@ $(INCLUDES) $(LIBDIR)

library: $(LIB-SHARE) $(LIB-STATIC)

$(LIB-SHARE):$(OBJS)
	$(CC) -shared -o $@ $(filter-out main.o, $(OBJS))

$(LIB-STATIC):$(OBJS)
	@$(AR) rcs $@ $(OBJS) $(filter-out main.o, $(OBJS))
	ranlib $@

clean:
	rm -rf $(OUTPUT) *.o    
	rm -rf $(LIB-SHARE) $(LIB-STATIC)

.PHONY:clean all library
