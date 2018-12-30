LIB_DIR = /usr/local/lib:/usr/lib:/usr/lib/i386-linux-gnu
SRC_DIR = .
SRC_FILES = ${SRC_DIR}/test_numbers.cpp ${SRC_DIR}/test_vectorSpace.cpp ${SRC_DIR}/test_affine.cpp ${SRC_DIR}/test_polynomial.cpp ${SRC_DIR}/test_math.cpp
OBJ_DIR =${BIN_DIR}
OBJ_FILES = ${OBJ_DIR}/test_numbers.o ${OBJ_DIR}/test_vectorSpace.o ${OBJ_DIR}/test_affine.o ${OBJ_DIR}/test_polynomial.o ${OBJ_DIR}/test_math.o
LOCAL_INCLUDE_DIR=${INCLUDE_DIR}

#targets for full compilation chain
${OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp
	${CXX} ${LOCAL_INCLUDE_DIR} -fpic -c ${CC_FLAGS} ${PREDEFINED_MACRO} $< -o $@

BIN: ${OBJ_FILES}

clean_obj:
	rm -rf ${OBJ_SUBDIRS}

clean_all: clean_obj

build: BIN

rebuild: clean_all build