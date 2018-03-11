LD = g++
CC = gcc

TARGET = image_smooth

SRCS = image_smooth.cpp

OBJS = $(SRCS:.cpp=.o)

DLIBS := -L/usr/local/lib
DLIBS += -lopencv_core -lopencv_imgcodecs -lopencv_imgproc  -lopencv_highgui


$(TARGET):$(OBJS)
	$(LD) -o $@ $^ $(DLIBS)
    
clean:
	rm -rf $(TARGET) $(OBJS)

%.o:%.cpp
	$(CC) -o $@ -c $<
    