#pragma once

#include <mysql.h>
#include <vector>

#include "Datarow.h"

using namespace std;

#define DB_HOST "127.0.0.1"	// 서버 아이피
#define DB_USER "root"	// DB 접속계정
#define DB_PASS "1234"	// DB 계정암호
#define DB_NAME "bookdb"	// DB 이름

class CMysqlController
{
public:
	CMysqlController();
	~CMysqlController();
	bool SelectQuery(char* sql, vector<Datarow*>& row);
	bool InsertQuery(char* sql);
};

