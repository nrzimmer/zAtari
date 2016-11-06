NAME		=	zAtari
CXX			=	g++
RM			=	rm	-f
SRC			=	src/main.cpp							\
				src/M6507/M6507.cpp						\
				src/M6507/opcodes.cpp					\
				src/M6507/step.cpp						\
				src/M6507/registers/Program_Counter.cpp	\
				src/M6507/registers/Register_8BIT.cpp	\
				src/M6507/registers/Status_Register.cpp	\
				src/util/data_manipulation.cpp
	
OBJ			=	$(subst src/,obj/, $(subst .cpp,.o, $(SRC)))
LDFLAGS		=	-lstdc++ -g
FLAGS		=	-O0 -std=c++11 -Wall -Wextra -g

zAtari: $(OBJ)
	@echo -e "\t[LD]\t$^\n\t\t$@"
	@$(CXX) $^ -o $@ $(LDFLAGS)

obj:
	@mkdir -p $@
	
obj/M6507:
	@mkdir -p $@

obj/M6507/registers:
	@mkdir -p $@
	
obj/util:
	@mkdir -p $@

obj/%.o: src/%.cpp src/M6507/M6507.h | obj obj/M6507 obj/M6507/registers obj/util
	@echo -e "\t[CC]\t$<\n\t\t$@"
	@$(CXX) -c $< -o $@ $(FLAGS)

clean:
	@echo -e "\nRemoving OBJ and temp files"
	@$(RM) $(OBJ) *~
	@echo -e "Removing executable\n"
	@$(RM) $(NAME)

re: clean all

.PHONY: clean re
