/*
** EPITECH PROJECT, 2019
** sokoban.h
** File description:
** sokoban.h
*/

#ifndef my_sokoban_h_
#define my_sokoban_h_

typedef struct sizemap
{
    int max_height;
    int max_lenght;
    char *str;
    char **map;
    char **savmap;
    int savposp_x;
    int savposp_y;
    int savposx_x;
    int savposx_y;
    int ox;
    int key;
}sizemap_t;

typedef struct lose
{
    int x;
    int y;
    int cpt;
    int nbx;
    int nbo;
    int cptl;
    int lx;
    int ly;
}lose_t;

int finderror2(char *buffer);
int finderror(char *buffer, lose_t *lose);
void checkerror(int ac, char **av);
int handleerror(int fd, char *buffer);
void displayerror(void);
void error(int fd, char *buffer);

int count_column(char *buffer, int i);
int count_line(char *buffer);

void allocnewmap(sizemap_t *size);
void allocmap(sizemap_t *size);
void open_read_file(char const *filename, sizemap_t *size, lose_t *lose);

void savepos(sizemap_t *size, int i, int j, int k);
char **mov(sizemap_t *size, lose_t *lose, int ac, char **av);

void moveup(sizemap_t *size, lose_t *lose);
void movedown(sizemap_t *size, lose_t *lose);
void moveleft(sizemap_t *size, lose_t *lose);
void moveright(sizemap_t *size, lose_t *lose);

void moveright2(sizemap_t *size, lose_t *lose);
void moveleft2(sizemap_t *size, lose_t *lose);
void moveup2(sizemap_t *size, lose_t *lose);
void movedown2(sizemap_t *size, lose_t *lose);

void newmap(sizemap_t *size);
void newmap2(sizemap_t *size, int i, int j);
void allocnewmap(sizemap_t *size);

void my_sokoban(char **av, int ac, sizemap_t *size, lose_t *lose);
void main(int ac, char **av);
void printmap(sizemap_t *size);

void checkwin(sizemap_t *size, lose_t *lose);
int checkwin1(sizemap_t *size, lose_t *lose);
int checkwin2(sizemap_t *size, lose_t *lose);

void checklose(sizemap_t *size, lose_t *lose);
int checklose1(sizemap_t *size, lose_t *lose);
int checklose2(sizemap_t *size, lose_t *lose);
int checklose3(sizemap_t *size, lose_t *lose);
void initlosevalues(sizemap_t *size, lose_t *lose);

#endif /* my _sokoban_ */

