include common.mk

SRCS=main.cpp
OBJS:=${SRCS:.cpp=.o}
DIRS=${shell find classes -type f -name Makefile | sed -e 's@^\(.*\)/Makefile$$@\1@'}
LDFLAGS=-stdlib=libc++ \
    -lfcgi \
    ${shell find classes -type f -name Makefile | sed -e 's@/Makefile$$@@;s/^/-L /'} \
    ${shell find classes -type f -name Makefile -exec grep 'TARGET' {} \; | sed -e 's/TARGET=lib//;s/\.a$$//;s/^/-l/'}

TARGET=index.fcgi

${TARGET}: ${OBJS}
	for i in ${DIRS}; do ( cd $$i; make ); done
	${CXX} -o $@ ${OBJS} ${LDFLAGS}

clean:
	for i in ${DIRS}; do ( cd $$i; make clean ); done
	rm -f a.out *.o ${TARGET}

install:
	cp ${TARGET} ../htdocs
