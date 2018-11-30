SRC_DIR = .
SRC_FILES = ${SRC_DIR}/test_smartPtr.cpp ${SRC_DIR}/test_string.cpp ${SRC_DIR}/test_rope.cpp ${SRC_DIR}/test_map.cpp ${SRC_DIR}/test_unorderedMap.cpp ${SRC_DIR}/test_trie.cpp ${SRC_DIR}/test_bitset.cpp ${SRC_DIR}/test_queue.cpp ${SRC_DIR}/test_array.cpp ${SRC_DIR}/test_tuple.cpp ${SRC_DIR}/test_function.cpp ${SRC_DIR}/test_stack.cpp ${SRC_DIR}/test_message_queue.cpp ${SRC_DIR}/test_signals.cpp ${SRC_DIR}/test_algorithm.cpp ${SRC_DIR}/test_parameter_pack.cpp ${SRC_DIR}/test_iterable.cpp ${SRC_DIR}/test_view.cpp
OBJ_DIR =${BIN_DIR}
OBJ_FILES = ${OBJ_DIR}/test_smartPtr.o ${OBJ_DIR}/test_string.o ${OBJ_DIR}/test_rope.o ${OBJ_DIR}/test_map.o ${OBJ_DIR}/test_unorderedMap.o ${OBJ_DIR}/test_trie.o ${OBJ_DIR}/test_bitset.o ${OBJ_DIR}/test_queue.o ${OBJ_DIR}/test_array.o ${OBJ_DIR}/test_tuple.o ${OBJ_DIR}/test_function.o ${OBJ_DIR}/test_stack.o ${OBJ_DIR}/test_message_queue.o ${OBJ_DIR}/test_signals.o ${OBJ_DIR}/test_algorithm.o ${OBJ_DIR}/test_parameter_pack.o ${OBJ_DIR}/test_iterable.o ${OBJ_DIR}/test_view.o
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