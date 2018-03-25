LD = g++
CC = gcc

TARGET = face_detect

SRCS = face_detect.cpp

OBJS = $(SRCS:.cpp=.o)

DLIBS := -L/usr/local/lib
DLIBS += -lopencv_core -lopencv_imgcodecs -lopencv_imgproc  -lopencv_highgui -lopencv_objdetect
CFLAGS = -Wall  -g -fPIC  -rdynamic


$(TARGET):$(OBJS)
	$(LD) -o $@ $^ $(DLIBS)
    
clean:
	rm -rf $(TARGET) $(OBJS)

%.o:%.cpp
	$(CC) $(CFLAGS) -o $@ -c $<
    
