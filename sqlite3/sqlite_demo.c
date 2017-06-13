#include <sqlite3.h>
#include <stdio.h>

int db_callback(void *arg,int nr_field ,char **result, char **field)
{
	int i = 0;

	// printf("in db_callback\n");
	for(i = 0; i < nr_field; i++)
	{
		printf("%s : %s \n", field[i], result[i]);
	}	

	printf("db_callback: %s \n", (char *)arg);
	return 0;
}

int main(int argc, char *argv[])
{
	struct sqlite3 *db;
	int ret = 0;
	char *err_msg;
	char *sql_cmd = "CREATE TABLE IF NOT EXISTS MUSIC_TABLE(" \
		"id INTEGER  PRIMARY KEY," \
		"data TEXT);" ;
	int arg = 4231;

	ret = sqlite3_open("clarence.db", &db);
	if(SQLITE_OK != ret)
	{
		return -1;
	}
	ret = sqlite3_exec(db, sql_cmd, db_callback, "create table", &err_msg);
	if(SQLITE_OK != ret)
	{
		printf("sqlite3_exec: line: %d, err:%s \n", __LINE__, err_msg);
		
	}
	sql_cmd = "INSERT INTO MUSIC_TABLE(data)" \
			  "VALUES('xxx1');";
			 
	ret = sqlite3_exec(db, sql_cmd, db_callback, "insert data", &err_msg);
	if(SQLITE_OK != ret)
	{
		printf("sqlite3_exec: line: %d, err:%s \n", __LINE__, err_msg);
		
	}

	sql_cmd = "INSERT INTO MUSIC_TABLE(data)" \
			  "VALUES('xxx2');" ;
	ret = sqlite3_exec(db, sql_cmd, db_callback, "insert data", &err_msg);
	if(SQLITE_OK != ret)
	{
		printf("sqlite3_exec: line: %d, err:%s \n", __LINE__, err_msg);
		
	}

	sql_cmd = "INSERT INTO MUSIC_TABLE(data)" \
			  "VALUES('xxx3');" ;
	ret = sqlite3_exec(db, sql_cmd, db_callback, "insert data", &err_msg);
	if(SQLITE_OK != ret)
	{
		printf("sqlite3_exec: line: %d, err:%s \n", __LINE__, err_msg);
		
	}
	
	
	sql_cmd = "SELECT * FROM MUSIC_TABLE;";
	ret = sqlite3_exec(db, sql_cmd, db_callback, "select data", &err_msg);
	if(SQLITE_OK != ret)
	{
		printf("sqlite3_exec: line: %d, err:%s \n", __LINE__, err_msg);
		
	}
	
	sqlite3_close(db);

	
	return 0;

}


