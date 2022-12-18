#include<stdio.h>
#include <windows.h>
#include<stdlib.h>
#include <io.h>

int main(int argc, char *argv[])
{

    // printf("%d %s\n", argc, argv[1]);

    if (argc != 2) {
        printf("No input file");
        return 0;
    }

    char str[100], curr_dir[50], curr_filename[60], curr_file[60], comp_file[60], fex[5],htm=0;


    /******* Set __directory__ ********/

    GetCurrentDirectory( 50, curr_dir);
    // gcc D:\\doe\\code\\c\\main\\justify_left.c -o %temp%\\c.exe


    /******* Set __file-extension__ *******/

    int i = strlen(argv[1]), j = 0;
    while (--i) if (argv[1][i] == '.') break;
    while (argv[1][i++]) fex[j++] = argv[1][i];
    fex[j] = 0;

    if (i == 0) {
        printf("No file extension");
        return 0;
    }


    /******* Set __file__ and __filename__ *******/

    int is_full_path = 0;
    for (int i = 0; argv[1][i]; i++) {
        if (argv[1][i] == '/' || argv[1][i] == '\\') {
            is_full_path = 1;
            break;
        }
    }

    if (is_full_path){
        strcpy(curr_file, argv[1]);
    }
    else{
        htm=1;
        strcpy(curr_filename, argv[1]);
        sprintf(curr_file, "%s\\%s", curr_dir, argv[1]);
    }


    if (_access(curr_file, 0) != 0) {
        printf("File does not exist\n");
        return 0;
    }


    /******************* C ************************/

    if (!strcmp(fex, "c")) {

        sprintf(str, "gcc %s -o %%temp%%\\b1.exe", curr_file, argv[1]);

        if (system(str) != 0) return 0;

        system("%temp%\\b1.exe");

        return 0;
    }


    /****************** CPP *********************/

    else if (!strcmp(fex, "cpp")) {

        sprintf(str, "g++ %s -o %%temp%%\\b2.exe", curr_file, argv[1]);

        if (system(str) != 0) return 0;

        system("%temp%\\b2.exe");

        return 0;
    }


    /****************** JAVA **********************/

    else if (!strcmp(fex, "java")) {

        sprintf(str, "java %s", curr_file);

        system(str);

        return 0;
    }


    /****************** PYTHON **********************/

    else if (!strcmp(fex, "py")) {

        sprintf(str, "python %s", curr_file);

        system(str);

        return 0;
    }


    /****************** HTML **********************/

    else if (!strcmp(fex, "html") || !strcmp(fex, "htm")) {

        if(!htm) return 0;

        int port = 8000;

        sprintf(str,"start http://localhost:%d/%s ",port,curr_filename);

        if (system(str) != 0) return 0;

        sprintf(str, "python -m http.server %d -d %s", port, curr_dir);

        system(str);

        return 0;
    }


    return 0;
}
