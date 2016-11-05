NAME		=	zAtari
CXX			=	g++
RM			=	rm	-vf
SRC			=	src/main.cpp							\
				src/M6507/M6507.cpp						\
				src/M6507/step.cpp						\
				src/M6507/registers/Program_Counter.cpp	\
				src/M6507/registers/Register_8BIT.cpp	\
				src/M6507/registers/Status_Register.cpp	\
				src/util/data_manipulation.cpp
	
OBJ			=	$(subst src/,obj/, $(subst .cpp,.o, $(SRC)))
LDFLAGS		=	-lstdc++
FLAGS		=	-O0 -std=c++11 -Wall -g

all: $(NAME)

obj:
	mkdir $@
	
obj/M6507:
	mkdir $@

obj/M6507/registers:
	mkdir $@
	
obj/util:
	mkdir $@

obj/%.o: src/%.cpp src/M6507/M6507.h | obj obj/M6507 obj/M6507/registers obj/util
	$(CXX) -c $< -o $@ $(FLAGS)

zAtari: $(OBJ)
	$(CXX) $^ -o $@ $(LDFLAGS) $(FLAGS)

clean:
	$(RM) $(OBJ) *~
	$(RM) $(NAME)

rebuild: clean zAtari

.PHONY: all clean zAtari
