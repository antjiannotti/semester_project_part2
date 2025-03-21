#ifndef MYOS_INCLUDE_CONSOLE_H
#define MYOS_INCLUDE_CONSOLE_H

extern const int VGA_WIDTH;
extern const int VGA_HEIGHT;
extern const int VGA_BYTES_PER_CHARACTER;

void clear_terminal();
void print_character(char c);
void print_string(char* str);
void print_line(char* str);

#endif
