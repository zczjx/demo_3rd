LD = g++
CC = gcc

TARGET = img_proc

SRCS = img_proc.cpp

OBJS = $(SRCS:.cpp=.o)

DLIBS := -L/usr/local/lib
DLIBS += -lopencv_core -lopencv_imgcodecs -lopencv_imgproc  -lopencv_highgui
CFLAGS = -Wall  -g -fPIC  -rdynamic


$(TARGET):$(OBJS)
	$(LD) -o $@ $^ $(DLIBS)
    
clean:
	rm -rf $(TARGET) $(OBJS)

%.o:%.cpp
	$(CC) $(CFLAGS) -o $@ -c $<
    
