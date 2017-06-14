#include <sqlite3.h>
#include <stdio.h>
#include "sql.h"

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
	SQL_HANDLE_S *slq_hdl = NULL;
	int ret = 0;
	char *sql_cmd;

	sql_cmd = malloc(SQL_LEN);
	slq_hdl = initSqlHandle();
	if(NULL == slq_hdl)
	{
		printf("initSqlHandle fail!\n");
	}
	ret = sql_create_db(slq_hdl, "zcz.db");

	sprintf(sql_cmd, "CREATE TABLE IF NOT EXISTS favorite" \
			"(id INTEGER  PRIMARY KEY, data TEXT);" );
	sql_create_table(slq_hdl, sql_cmd);

	sprintf(sql_cmd, "INSERT INTO favorite(data) VALUES('xxx1');");
	sql_insert_record(slq_hdl, sql_cmd);

	sprintf(sql_cmd, "INSERT INTO favorite(data) VALUES('xxx2');");
	sql_insert_record(slq_hdl, sql_cmd);

	sprintf(sql_cmd, "INSERT INTO favorite(data) VALUES('xxx3');");
	sql_insert_record(slq_hdl, sql_cmd);
	
	sprintf(sql_cmd, "INSERT INTO favorite(data) VALUES('xxx4');");
	sql_insert_record(slq_hdl, sql_cmd);

	
	sprintf(sql_cmd, "SELECT * FROM favorite;");
	sql_query_record_all(slq_hdl, sql_cmd);
	

	
	
	sql_close_db(slq_hdl);
	
out:
	ret = destroySqlHandle(slq_hdl);
	printf("ret is %d \n", ret);
	return ret;

}


