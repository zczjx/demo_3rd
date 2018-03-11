LD = g++
CC = gcc

TARGET = camera_avi

SRCS = camera_avi.cpp

OBJS = $(SRCS:.cpp=.o)

DLIBS := -L/usr/local/lib
DLIBS += -lopencv_core -lopencv_imgcodecs -lopencv_imgproc  -lopencv_highgui -lopencv_videoio


$(TARGET):$(OBJS)
	$(LD) -o $@ $^ $(DLIBS)
    
clean:
	rm -rf $(TARGET) $(OBJS)

%.o:%.cpp
	$(CC) -o $@ -c $<
    
