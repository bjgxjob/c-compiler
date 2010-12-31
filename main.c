#include "main.h"

int main(int argc, char *argv[])
{
	char *ofile;
	size_t o_name_len;
	switch(argc){
		case 1:
			printf("c: no input files");
			break;
		case 2:
			if(strcmp(argv[1], "--help") == 0){
				usage();
			}
			else if(strcmp(argv[1], "--version") == 0){
				version();
			}
			else {
				ofile = (char*)malloc(sizeof(char)*6);
				strcpy(ofile, "a.out");  /* No output name specified, we default to unix a.out */
				printf("%s", ofile);
				free(ofile);
			}
			break;
		case 3:
			
			break;
		default:
			/* These next few lines handle the -o flag */
			o_name_len = strlen((char*)scan_for_o(argc, argv));
			if(o_name_len > 0){ 
				ofile = (char*)malloc(sizeof(char)*o_name_len);
				strcpy(ofile, (char*)scan_for_o(argc, argv));
			}
			free(ofile);
			break;
		
	}
	/* Free all allocated variables here */
	
	return EXIT_SUCCESS;
}
