#include <my_global.h>
#include <mysql.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


char * get_name( char * returnval, char * msg1){
    printf("%s\n", msg1);
    scanf("%100s", returnval);
}

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}

int main(int argc, char **argv)
{      
  MYSQL *con = mysql_init(NULL);
  char* firstname= (char *) malloc(sizeof(char)*101);
  char* lastname= (char *) malloc(sizeof(char)*101);


  printf("%s\n", "Print actor's first name: ");
  scanf("%100s", firstname);

  printf("%s\n", "Print actor's last name: ");
  scanf("%100s", lastname);

  //printf("%s\n", firstname);
  //printf("%s\n", lastname );
  
  
  if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }  
  

  if (mysql_real_connect(con, "localhost", "root", "1Wildhorse", 
          "imdb", 0, NULL, 0) == NULL) 
  {
      finish_with_error(con);
  }    

 
char * query1= (char *) malloc(sizeof(char)*1001);

 strcpy(query1, "SELECT movie FROM imdb WHERE firstname = '");
 strcat(query1, firstname);
 strcat(query1, "' AND lastname= '");
 strcat(query1, lastname);
 strcat(query1, "' LIMIT 10");

printf("%s\n", query1);

  if (mysql_query(con, query1)) {
      finish_with_error(con);
  }

  /*if (mysql_query(con, "SELECT * FROM imdb LIMIT 50")) {
      finish_with_error(con);
  }*/
  
  MYSQL_RES *result = mysql_store_result(con);
  
  if (result == NULL) 
  {
      finish_with_error(con);
  }

  int num_fields = mysql_num_fields(result);

  MYSQL_ROW row;
  
  while ((row = mysql_fetch_row(result))) 
  { 
      for(int i = 0; i < num_fields; i++) 
      { 
          printf("%s ", row[i] ? row[i] : "NULL"); 
      } 
          printf("\n"); 
  }
  
  mysql_free_result(result);
  mysql_close(con);
  
  exit(0);
  

}