void clear_terminal(){
        char* const VGA_BUFFER = (char*) 0xb8000;
        for (int i=0; i < 80 * 25 * 2; i+=2){
		VGA_BUFFER[i] = ' ';
		VGA_BUFFER[i + 1] = 0x07;
	}
}

void main() {

	clear_terminal();
	char* const VGA_BUFFER = (char*) 0xb8000;
	char* str = "Hello World";

	for (int i=0; str[i] != '\0'; i++) {
		VGA_BUFFER[i*2] = str[i];
	}

	return;
}

