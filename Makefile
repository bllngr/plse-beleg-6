# default target
default: all

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

# aufgabe6.2
A62_SOURCE =\
	$(SRC_PATH)/aufgabe6.2.cpp \
	$(NULL)

A62_OBJECT =$(A62_SOURCE:$(SRC_PATH)%.cpp=$(OBJ_PATH)%.o)

A62_OUTPUT =$(BIN_PATH)/aufgabe6.2

aufgabe6.2: $(OBJECT) $(A62_OBJECT)
	$(CXX) $(OBJECT) $(A62_OBJECT) $(LIB) $(LIB_PATH) -o $(A62_OUTPUT)

# aufgabe6.4
A64_SOURCE =\
	$(SRC_PATH)/aufgabe6.4.cpp \
	$(NULL)

A64_OBJECT =$(A64_SOURCE:$(SRC_PATH)%.cpp=$(OBJ_PATH)%.o)

A64_OUTPUT =$(BIN_PATH)/aufgabe6.4

aufgabe6.4: $(OBJECT) $(A64_OBJECT)
	$(CXX) $(OBJECT) $(A64_OBJECT) $(LIB) $(LIB_PATH) -o $(A64_OUTPUT)

# aufgabe6.5
A65_SOURCE =\
	$(SRC_PATH)/aufgabe6.5.cpp \
	$(NULL)

A65_OBJECT =$(A65_SOURCE:$(SRC_PATH)%.cpp=$(OBJ_PATH)%.o)

A65_OUTPUT =$(BIN_PATH)/aufgabe6.5

aufgabe6.5: $(OBJECT) $(A65_OBJECT)
	$(CXX) $(OBJECT) $(A65_OBJECT) $(LIB) $(LIB_PATH) -o $(A65_OUTPUT)

# aufgabe6.6
A66_SOURCE =\
	$(SRC_PATH)/aufgabe6.6.cpp \
	$(NULL)

A66_OBJECT =$(A66_SOURCE:$(SRC_PATH)%.cpp=$(OBJ_PATH)%.o)

A66_OUTPUT =$(BIN_PATH)/aufgabe6.6

aufgabe6.6: $(OBJECT) $(A66_OBJECT)
	$(CXX) $(OBJECT) $(A66_OBJECT) $(LIB) $(LIB_PATH) -o $(A66_OUTPUT)

# aufgabe6.7
A67_SOURCE =\
	$(SRC_PATH)/aufgabe6.7.cpp \
	$(NULL)

A67_OBJECT =$(A67_SOURCE:$(SRC_PATH)%.cpp=$(OBJ_PATH)%.o)

A67_OUTPUT =$(BIN_PATH)/aufgabe6.7

aufgabe6.7: $(OBJECT) $(A67_OBJECT)
	$(CXX) $(OBJECT) $(A67_OBJECT) $(LIB) $(LIB_PATH) -o $(A67_OUTPUT)

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
all: aufgabe6.1 aufgabe6.2 aufgabe6.4 aufgabe6.5 aufgabe6.6 aufgabe6.7
cleanbuild: realclean all

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
