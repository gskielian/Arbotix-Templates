CC=gcc
CFLAGS=-Wall

TARGET=mx12w-c-controller

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	rm -f $(TARGET)
