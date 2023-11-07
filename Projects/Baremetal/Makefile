CC = arm-none-eabi-gcc
INC_DIR = -I ../../Core/Inc -I ../../Driver/Inc
MACH = -mcpu=cortex-m4
FILENAME = main
LINKER = stm32.ld

# List of source files (assuming all .c files in the current directory)
SRC_FILES = $(wildcard *.c) 

# Object files corresponding to source files
OBJ_FILES = $(SRC_FILES:.c=.o)

build: ${FILENAME}.elf
	arm-none-eabi-objcopy -O binary ${FILENAME}.elf ${FILENAME}.bin

${FILENAME}.elf: ${OBJ_FILES}
	${CC} ${MACH} -mthumb -T ${LINKER} -Xlinker -Map=${FILENAME}.map -o $@ ${OBJ_FILES} -nostdlib 

%.o: %.c
	${CC} ${MACH} -c $< -o $@ ${INC_DIR} -mthumb



flash:${FILENAME}.bin
	st-flash write ${FILENAME}.bin 0x08000000

clean:
	rm -f ${OBJ_FILES} ${FILENAME}.elf ${FILENAME}.bin ${FILENAME}.map ${FILENAME}.map.save
