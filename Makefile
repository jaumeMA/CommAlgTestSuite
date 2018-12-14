include ./compiler.mk

LOCAL_DIR = ${PWD}
FRAMEWORK_DIR=${LOCAL_DIR}/../editorFramework
# in order to prevent from static initialization fiasco, this order is important
MODULES:=YTL System Utils Math
#System Utils Math

LIBRARY_MODULES:=$(foreach MODULE,${MODULES},$(FRAMEWORK_DIR)/$(MODULE)/lib$(MODULE)${LIBRARY_SUFFIX}.so)

export BIN_DIR=${LOCAL_DIR}/Bin/${Mode}

LIBRARY_PATH=${LD_LIBRARY_PATH} /usr/include/unittest++
LIBRARY_PATH:=$(foreach MODULE,${MODULES},:$(FRAMEWORK_DIR)/$(MODULE))
export LD_LIBRARY_PATH=${LIBRARY_PATH}

LIB_DIR = /usr/local/lib:/usr/lib:/usr/lib/i386-linux-gnu
LIB = ${LIBRARY_MODULES} -lUnitTest++ -lpthread
SRC_DIR = ${LOCAL_DIR}/.
INC_DIR = ${LOCAL_DIR}/.
OBJ_DIR = ${BIN_DIR}
INCLUDE_DIR = -I./ -I/usr/include/freetype2 -I/usr/include/unittest++ -I${FRAMEWORK_DIR}

INCLUDE_DIR:=${INCLUDE_DIR} $(foreach MODULE,${MODULES}, -I${FRAMEWORK_DIR}/${MODULE})

export INCLUDE_DIR

SRC_FILES = ${SRC_DIR}/main.cpp

OBJ_FILES = ${OBJ_DIR}/main.o

BIN = ./editorFrameworkTest${LIBRARY_SUFFIX}

#targets for full compilation chain
CREATE_DIR:
	mkdir -p ${BIN_DIR}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp
	${CXX} ${INCLUDE_DIR} -g -fpic -c ${CC_FLAGS} $< -o $@

${BIN}: ${OBJ_FILES}
	$(eval OBJECTS = $(shell ls ${BIN_DIR}/*.o))
	${LINKER} -L${LIB_DIR} -o $@ $(OBJECTS) ${LD_FLAGS} ${LIB}

$(MODULES): force
	cd $@ && $(MAKE) build

build: clean_bin CREATE_DIR $(MODULES) ${BIN}
#	mv ${BIN} ${BIN_DIR} 

rebuild: clean_all build
#	mv ${BIN} ${BIN_DIR} 

clean_bin:
	rm -f ${BIN_DIR}/${BIN}

clean_obj:
	rm -rf ${BIN_DIR}/*

clean_all: clean_bin clean_obj

.PHONY: force
force:;
