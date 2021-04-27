/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** 103cipher.h
*/

typedef struct res
{
    float x;
    float c;
}res_t;

typedef struct mess
{
    float x;
}mess_t;

typedef struct key
{
    double x;
}key_c;

typedef struct base
{
    int matrix_type;
    int lenght;
    key_c *key;
    mess_t *mess;
    res_t *res;
}base_t;

void finderror(int ac, char **av);

float det3_by_3(base_t *base);
void decrypted_key3_by_3(char *key, base_t *base);
void decryptedkey23_by_3(char *key, base_t *base);
void print_decrypted(base_t *base);
void decrypted_message(char *mess, base_t *base);
void decrypted3_by_3(base_t *base);
void decrypted2_by_2(base_t *base);
void print_decrypted(base_t *base);
void print_decrypted_matrix(base_t *base);
void decrypted(base_t *base);
void decrypted_key(char *key, base_t *base);
void decryptedkey2_by_2(char *key, base_t *base);
void decryptedkey22_by_2(base_t *base);
void encrypted_key(char *key, base_t *base);
void encrypted_mess(char *mess, base_t *base);
void print_encrypted(base_t *base);
void print_encrypted_matrix(base_t *base);
void encrypted(base_t *base);
void encrypted_1_by_1(base_t *base);
void encrypted_2_by_2(base_t *base);
void encrypted_3_by_3(base_t *base);
void encrypted_4_by_4(base_t *base);
