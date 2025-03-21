#include "console.h"

const int VGA_WIDTH = 80;
const int VGA_HEIGHT = 25;
const int VGA_BYTES_PER_CHARACTER = 2;

static int terminal_position = 0;
char* const VGA_BUFFER = (char*) 0xb8000;

void clear_terminal(){
        for (int i = 0; i < VGA_WIDTH * 
		VGA_HEIGHT * VGA_BYTES_PER_CHARACTER; i++) {
		VGA_BUFFER[i] = 0;
	}
	terminal_position = 0;
}

void print_character(char c){
    if(c == '\n'){
        terminal_position = (terminal_position / (VGA_WIDTH * VGA_BYTES_PER_CHARACTER) + 1) * (VGA_WIDTH * VGA_BYTES_PER_CHARACTER);
    }
    else {
        
        VGA_BUFFER[terminal_position] = c;
        VGA_BUFFER[terminal_position + 1] = 0x07;
        terminal_position += VGA_BYTES_PER_CHARACTER;
}

void print_string(char * str) {
	for (int i = 0; str[i] != '\0'; i++){
		print_character(str[i]);
	}
}

void print_line(char* str){
	print_string(str);
	print_character('\n');
}
			
