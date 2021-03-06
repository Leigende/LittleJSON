/*
** littlejson.h for littlejson
** 
** Made by Alexis Rouillard
** Login   <alexis.rouillard@epitech.eu>
** 
** Started on  Sun May  7 22:17:50 2017 Alexis Rouillard
** Last update Sun May 14 12:20:52 2017 Alexis Rouillard
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define JUMP(p) while (((char)(*p) == 32 || (char)(*p) == '\n' || \
			 (char)(*p) == '\t')) ++p

typedef enum	e_enum_val
  {
    JSON_STRING,
    JSON_NUMBER,
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL,
    NONE
  }		t_enum_val;

typedef struct	s_j_val
{
  t_enum_val	type;
  char		*key;
  char		*val;
}		t_j_val;

int     skip_val(char **tmp);
int     skip_string(char **tmp);
int     skip_object(char **tmp);
int     skip_array(char **tmp);
int     skip_number(char **tmp);
int     j_parse(const char *str, t_j_val *s);
int     j_get_obj(t_j_val json, const char *key, t_j_val *s);
int     j_get_array(t_j_val json, int idx, t_j_val *s);
char	*j_get_string(t_j_val json);
int     j_get_number(t_j_val json, int  *val);
char    *j_get_key(t_j_val json);
