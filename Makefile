# This is the name of your final .nex file without the .nex extension
EXEC_OUTPUT=build/multicalc

# List all your source files here
SOURCES = multicalc.c \
		  modules/system_helper.c \
		  modules/misc_helper.c \
		  modules/math_helper.c \
		  modules/adt_stack.c \
		  modules/operations_helper.c \
		  modules/stack_helper.c \
		  modules/adt_queue.c \
		  modules/history_helper.c

# Maybe you'll need to edit this
CRT=1

# You don't need to edit below here, have a nice day.

MKDIR = mkdir -p
CC=docker run  --platform linux/amd64 -v .:/src/ -it z88dk/z88dk zcc
AS=docker run  --platform linux/amd64 -v .:/src/ -it z88dk/z88dk zcc
# TARGET=+zxn -subtype=nex -lndos
TARGET=+zx -lndos -lm -DAMALLOC
# TARGET=+cpm -lndos
VERBOSITY=-vn
OUT_DIR=build bin
PRAGMA_FILE=zpragma.inc

OBJECTS=$(SOURCES:.*=.o)
OBJS=$(patsubst %, src/%, $(OBJECTS))

C_OPT_FLAGS=-SO3 --max-allocs-per-node200000 --opt-code-size

CFLAGS=$(TARGET) $(VERBOSITY) -c $(C_OPT_FLAGS) -compiler sdcc -clib=ansi -pragma-define:ansicolumns=42 -pragma-redirect:CRT_FONT=_font_8x8_zx_clairsys 
#-pragma-include:$(PRAGMA_FILE)
LDFLAGS=$(TARGET) $(VERBOSITY) --list -m -s -clib=ansi -pragma-define:ansicolumns=42 -pragma-redirect:CRT_FONT=_font_8x8_clairsys 
#-pragma-include:$(PRAGMA_FILE)
ASFLAGS=$(TARGET) $(VERBOSITY) -c --list -m -s 

# EXEC=$(EXEC_OUTPUT).nex
EXEC=$(EXEC_OUTPUT).tap
# EXEC=$(EXEC_OUTPUT).com

%.o: %.c $(PRAGMA_FILE)
	$(CC) $(CFLAGS) -o $@ $<

%.o: %.asm
	$(AS) $(ASFLAGS) -o $@ $<

all : dirs $(EXEC)

$(EXEC) : $(OBJS)
	$(CC) $(LDFLAGS) -startup=$(CRT) $(OBJS) -o $(EXEC_OUTPUT) -create-app

.PHONY: clean dirs install

install: all
	mv $(EXEC) bin

clean:
	rm -rf $(OUT_DIR) /tmp/tmpXX*
	rm -f src/*.lis src/*.sym src/*.o \
		src/modules/*.lis src/modules/*.sym src/modules/*.o

dirs: $(OUT_DIR)

$(OUT_DIR):
	$(MKDIR) $(OUT_DIR)
