/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** 103cipher.h
*/


#ifndef insertion_h_
#define insertion_h_

typedef struct detail
{
    float px;
    float py;
    float pz;
    float vx;
    float vy;
    float vz;
    float p;
    float delta;
    float x1;
    float x2;
}detail_t;

void findgeometrie(int ac, char **av);

void displayerror(void);
int finderror(int ac, char **av);
int is_char(char *av, int ac);
void hanldingerror(int ac, char **av);

void cone(detail_t *detail);
void sphere(detail_t *detail);
void cylindre(detail_t *detail);
void intersection_sphere(detail_t *detail);
void intersection_cylindre(detail_t *detail);



int calcul_inter2(float x, float y, float z,detail_t *detail);
int calc_inter(float x, float y, float z, detail_t *detail);
void intersection_cone(detail_t *detail);

#endif /* my_104insertion_ */