CC = gcc

RAYLIB_PATH = C:/Users/JINX/OneDrive/Desktop/project/raylib-5.5_win64_mingw-w64

INCLUDES = -I$(RAYLIB_PATH)/include -I.
LIBS = -L$(RAYLIB_PATH)/lib -lraylib -lopengl32 -lgdi32 -lwinmm -ldsound -luser32

SRCS = *.c
TARGET = main.exe

all:
	$(CC) $(SRCS) $(INCLUDES) $(LIBS) -o $(TARGET)


run: $(TARGET)
	.\$(TARGET)
clean:
	del /Q *.exe
