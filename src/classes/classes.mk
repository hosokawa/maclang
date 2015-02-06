SRCS=${wildcard *.cpp}
OBJS:=${SRCS:.cpp=.o}

${TARGET}: ${OBJS}
	${AR} ${ARFLAGS} $@ ${OBJS}

clean:
	rm -f a.out *.o ${TARGET}
