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

LIBRARY_PATHS = -L ./lib

INCLUDE_PATHS = -I ./include

#LINKER_FLAGS specifies the libraries we're linking against 
LINKER_FLAGS = -static-libgcc -static-libstdc++

WINAPI = -lmingw32 -lkernel32 -lm -ldxguid -ldxerr8 -luser32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lgdi32 -lcomdlg32 -lwinspool 
WINAPI+= -lcomctl32 -luuid -lrpcrt4 -ladvapi32 -lwsock32 -lshlwapi -lversion
 
#OBJ_NAME specifies the name of our exectuable 
OBJ_NAME = ForgedAlliance.exe 

WX = -lwxexpat -lwxregexu -lwxscintilla -lwxbase31u_net -lwxbase31u_xml
WX+= -lwxmsw31u_adv -lwxmsw31u_aui -lwxmsw31u_gl -lwxmsw31u_html -lwxmsw31u_media -lwxmsw31u_propgrid
WX+= -lwxmsw31u_qa -lwxmsw31u_ribbon -lwxmsw31u_richtext -lwxmsw31u_stc -lwxmsw31u_webview -lwxmsw31u_xrc
WX+= -lwxmsw31u_core -lwxbase31u -luxtheme -loleacc -lodbc32 -lwxjpeg -lwxpng -lwxtiff -lwxzlib

FUNC_CALL_PARAMS_FLAGS = -mpush-args -mno-accumulate-outgoing-args -mno-stack-arg-probe

#This is the target that compiles our executable 
all : 
	$(CC) -O0 $(OBJS) $(HEADS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(WX) $(FUNC_CALL_PARAMS_FLAGS) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(WINAPI) -o $(OBJ_NAME)