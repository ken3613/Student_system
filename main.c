#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "struct.h"
#include "declare.h"
int main(int argc, char *argv[]) {
	system("mode con cols=120 lines=40");
	login();
	menu(MainMenu);
	return 0;
}
