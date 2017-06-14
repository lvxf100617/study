#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>
//#include <io.h>



struct lists{
    char filenum[100];
    struct lists *prev;
    struct lists *next;
};

struct lists *root;

typedef struct _finddata_t FILE_SEARCH;
char filename[100][1000];


void loadfile(void);
void savefile (char *);
struct lists* savelist(struct lists *p, char []);
bool searchInfo(char []);
int getline(char [], int );
void makefile(void);
void fixfile(char *);                             // include searchInfo function. then find a file and then fix that.


int main(void)
{
    //DIR *dp;
    //struct dirent *dir;
    struct lists *p;
    char oper;
    char *callid = malloc(sizeof(char) *15);
    char *temp = malloc(sizeof(char) * 100);
    //scanf("%s", callid);
    getline(callid, 15);
    printf("%s come dial. Please take a call.\n", callid);

    loadfile(); // When start program, must be execute....

    /*p = root;
    while (p != NULL){
        printf("%s\n", p -> filenum);
        p = p -> next;
    }*/

    strcpy(temp, callid);
    strcat(temp, ".txt");
    //printf("in main: %s\n", temp);

    if (searchInfo (temp)){
        printf("He/She is our client.\n");
        printf("Move to fix page.\n");
        fixfile(temp);

    }else{
        printf("He/She is not our client.\n");
        printf("Are you add new clients' info?: ");
        scanf("%c", &oper);
        getchar();
        if (oper == 'y' ||oper == 'Y'){
            makefile();
        }
    }

    return 0;
}

void loadfile(void)
{
    char path[100] = "C:\\Users\\baboa\\Desktop\\Study\\CC\\sample";
    long h_file;
    char search_Path[100];
    int i = 0;
    FILE_SEARCH file_search;
    sprintf (search_Path, "%s/*.*", path);
    if ((h_file = _findfirst(search_Path, &file_search)) == -1L){
        printf("File does not exists\n");
    }else{
        do {
            //printf("%s\n", file_search.name);
            strcpy(filename[i], file_search.name);
            strcat(filename[i], "\0");
            root = savelist(root, filename[i]);
            ++i;
        }while (_findnext(h_file, &file_search) == 0);

        _findclose(h_file);
    }

}

struct lists* savelist(struct lists *p, char number[])
{
        struct lists *new_node, *ptr;

        if (p == NULL){
            new_node = (struct lists *) malloc (sizeof(struct lists));
            new_node -> prev = NULL;
            strcpy(new_node -> filenum, number);
            strcat(new_node -> filenum, "\0");
            new_node -> next = NULL;
            p = new_node;
        }else{
            ptr = p;
            new_node = (struct lists *) malloc(sizeof (struct lists));
            strcpy(new_node -> filenum, number);
            strcat(new_node -> filenum, "\0");
            while (ptr -> next != NULL)
                    ptr = ptr -> next;
            ptr -> next = new_node;
            new_node -> prev = ptr;
            new_node -> next = NULL;
        }

        return p;
}

bool searchInfo(char *c)
{
    struct lists *cur;

    for (cur = root; (cur != NULL) && (strcmp(c, cur -> filenum) != 0); cur = cur -> next)
        ;
    if (cur == NULL){
        return 0;
    }else if ((cur != NULL) && strcmp(c, cur -> filenum) == 0){
        return 1;
    }

}

int getline(char a[], int n)
{
    int c, i;

    /*while((c=getchar()) == ' ' || c ==  '\t' || c == '\n')
        ;*/

    for (i = 0; (i < n - 1) && (c = getchar() ) != EOF && c != '\n'; i++)
        a[i]  = c;
    if (c == '\n'){
        //a[i] = c;
        //++i;
    }
    a[i] = '\0';

    return i;
}

void makefile(void)
{
    char cliname[20], callid[20];
    char *w = malloc(sizeof(char) * 100);
    int sizecliname, sizecallid;
    FILE *fp;

    printf("This is space for input client information.\n\n");

    printf("Enter client name: ");
    sizecliname = getline(cliname, 20);

    printf("\nEnter client's phone number: ");
    sizecallid = getline(callid, 20);
    strcpy(w, "C:\\Users\\baboa\\Desktop\\Study\\CC\\sample\\");
    strcat(w, callid);
    strcat(w, ".txt");

    fp = fopen(w, "wb");

    if (fp == NULL){
        printf("\nerror opening file\n");
        exit(-1);
    }

    //fclose (fp);

    fputs(cliname, fp);
    fprintf(fp, "%s\n", callid);

    fclose(fp);
}


void fixfile(char *callid)
{
    FILE *fp;
    char contents[100];
    char *w = malloc(sizeof (char) * 100);
    strcpy(w, "C:\\Users\\baboa\\Desktop\\Study\\CC\\sample\\");
    strcat(w, callid);

    printf("current file: %s\n", w);

    printf("This page is fix client information.\n");

    fp = fopen(w, "ab");

    if (fp == NULL){
        printf("Fail opening file\n");
        exit(-1);
    }

    printf("Enter that fix contents\n");
    while (getline(contents, 100) > 0){
            fprintf(fp, contents);
    }
    printf("done\n");
    fclose(fp);
}
