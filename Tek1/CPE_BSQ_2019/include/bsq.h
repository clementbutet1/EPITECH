/*
** EPITECH PROJECT, 2019
** bsq.h
** File description:
** bsq.h
*/

#ifndef my_sokoban_h_
#define my_sokoban_h_

typedef struct sizemap
{
    int max_height;
    int max_lenght;
    char *str;
    char **map;
    int size;
    int bsq;
    int val;
    int col;
    int line;
    int pos_x;
    int pos_y;
    int k;
}sizemap_t;

int error(int fd, char *buffer);

void execute(char const *filename, sizemap_t *size);

int count_column(char *buffer);
int count_line(char *buffer);

int fs_open_file(char const *filename, sizemap_t *size);
int preparealloc(sizemap_t *size);
void allocmap2(sizemap_t *size);
void printmap(sizemap_t *size);


void bsq(sizemap_t *size);
void bsq2(sizemap_t *size);
int bsq3(sizemap_t *size);
void initvalues(sizemap_t *size);


#endif /* my _sokoban_ */

