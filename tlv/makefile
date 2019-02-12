
TARGET:=test_tlv

CC = gcc

SRC := tlv.c \
		test_tlv.c\

INC := -I./ \
		-I../common \
		-I../utils

OBJ = tlv.o \
      test_tlv.o

$(OBJ):$(SRC)
	cc -c $^ $(INC)
$(TARGET):$(OBJ)
	 gcc -o $@ $^

clean:
	rm -rf $(OBJ) $(TARGET)