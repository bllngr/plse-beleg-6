# default target
default: build

# global variables
INC_PATH =./src
SRC_PATH =./src
OBJ_PATH =./obj
BIN_PATH =./bin

# compiler
CXX =g++
CXX_FLAGS =-Wall -pedantic -g
INCLUDE =\
	-I/usr/include/unittest++ \
	$(NULL)

# linker
LIB =-lunittest++
LIB_PATH =-L/usr/lib/

# removing files
RM =rm -f

# all targets
HEADER =\
	$(INC_PATH)/color.hpp \
	$(INC_PATH)/point3d.hpp \
	$(INC_PATH)/shape.hpp \
	$(INC_PATH)/shape_container.hpp \
	$(INC_PATH)/box.hpp \
	$(INC_PATH)/sphere.hpp \
	$(NULL)

SOURCE =$(HEADER:$(INC_PATH)%.hpp=$(SRC_PATH)%.cpp)

OBJECT =$(SOURCE:$(SRC_PATH)%.cpp=$(OBJ_PATH)%.o)

# aufgabe6.1
A61_SOURCE =\
	$(SRC_PATH)/aufgabe6.1.cpp \
	$(NULL)

A61_OBJECT =$(A61_SOURCE:$(SRC_PATH)%.cpp=$(OBJ_PATH)%.o)

A61_OUTPUT =$(BIN_PATH)/aufgabe6.1

aufgabe6.1: $(OBJECT) $(A61_OBJECT)
	$(CXX) $(OBJECT) $(A61_OBJECT) $(LIB) $(LIB_PATH) -o $(A61_OUTPUT)
	$(A61_OUTPUT)

# aufgabe6.1
A62_SOURCE =\
	$(SRC_PATH)/aufgabe6.2.cpp \
	$(NULL)

A62_OBJECT =$(A62_SOURCE:$(SRC_PATH)%.cpp=$(OBJ_PATH)%.o)

A62_OUTPUT =$(BIN_PATH)/aufgabe6.2

aufgabe6.2: $(OBJECT) $(A62_OBJECT)
	$(CXX) $(OBJECT) $(A62_OBJECT) $(LIB) $(LIB_PATH) -o $(A62_OUTPUT)
	$(A62_OUTPUT)

# test
TEST_SOURCE =\
	$(SRC_PATH)/test/test.cpp \
	$(SRC_PATH)/test/test_point.cpp \
	$(SRC_PATH)/test/test_vector.cpp \
	$(SRC_PATH)/test/test_ray.cpp \
	$(SRC_PATH)/test/test_matrix.cpp \
	$(NULL)

# test
TEST_SOURCE =\
	$(SRC_PATH)/test/test.cpp \
	$(SRC_PATH)/test/test_point.cpp \
	$(SRC_PATH)/test/test_vector.cpp \
	$(SRC_PATH)/test/test_ray.cpp \
	$(SRC_PATH)/test/test_matrix.cpp \
	$(NULL)

TEST_OBJECT =$(TEST_SOURCE:$(SRC_PATH)%.cpp=$(OBJ_PATH)%.o)

TEST_OUTPUT =$(OBJ_PATH)/test/test.out

test: $(OBJECT) $(TEST_OBJECT)
	$(CXX) $(OBJECT) $(TEST_OBJECT) $(LIB) $(LIB_PATH) -o $(TEST_OUTPUT)
	$(TEST_OUTPUT)

# (clean and) build everything
build: test main
cleanbuild: realclean build

# routines for building objects
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp
	$(CXX) $(CXX_FLAGS) $(INCLUDE) -c $< -o $@

# clean routines
.PHONY: clean
clean:
	-$(RM) $(OBJECT) $(TEST_OBJECT) $(MAIN_OBJECT)

.PHONY: realclean
realclean: clean
	-$(RM) $(TEST_OUTPUT) $(MAIN_OUTPUT)
