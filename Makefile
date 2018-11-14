ifeq ($(OS),Windows_NT)
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname -s 2>/dev/null || echo not')
endif

#OBJS specifies which files to compile as part of the project 
OBJS = ./*cpp ./src/*cpp
#HEADS = ./*.h

#CC specifies which compiler we're using 
CC = g++

# -w suppresses all warnings 
# -Wl,-subsystem,windows gets rid of the console window 
COMPILER_FLAGS = -w 

#LINKER_FLAGS specifies the libraries we're linking against 
LINKER_FLAGS = -static-libgcc -static-libstdc++ -lmingw32 -lkernel32 -lm -ldxguid -ldxerr8 -luser32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32
 
#OBJ_NAME specifies the name of our exectuable 
OBJ_NAME = ForgedAlliance.exe 

FUNC_CALL_PARAMS_FLAGS = -mpush-args -mno-accumulate-outgoing-args -mno-stack-arg-probe

#This is the target that compiles our executable 
all : 
	$(CC) -O0 $(OBJS) $(HEADS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(FUNC_CALL_PARAMS_FLAGS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)