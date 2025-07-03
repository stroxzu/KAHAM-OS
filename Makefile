# KAHAM Makefile

all: build/boot.bin build/kernel.bin

build/boot.bin: src/boot.asm
	nasm -f bin src/boot.asm -o build/boot.bin

build/kernel.bin: src/kernel.c linker.ld
	x86_64-elf-gcc -ffreestanding -m32 -c src/kernel.c -o build/kernel.o
	x86_64-elf-ld -T linker.ld -o build/kernel.elf build/kernel.o
	objcopy -O binary build/kernel.elf build/kernel.bin

os-image: all
	cat build/boot.bin build/kernel.bin > build/os-image.bin

run: os-image
	qemu-system-x86_64 -drive format=raw,file=build/os-image.bin

clean:
	rm -f build/*
