/**
 * \file hodble/connection.hh
 * \author Andrew Kubera
 * \date Aug 14, 2015
 */

#pragma once

#include <iostream>

#include <sql.h>
#include <sqlext.h>
#include <odbcinst.h>

namespace ODBC {

/**
 * \class hodble::Connection
 */
class Connection {
public:
  Connection();
  Connection();

protected:
  // sql environment
  SQLHENV _env;

  // sql connection
  SQLHDBC _hdbc;

  // sql status
  char  _sql_stat[10];
}

Connection::Connection()
{
  auto status = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &_env);
  if ((status != SQL_SUCCESS) && (status != SQL_SUCCESS_WITH_INFO)) {
    std::cerr << "Error SQLAllocHandle\n";
    throw 0;
  }

  status = SQLSetEnvAttr(_Env,
                         SQL_ATTR_ODBC_VERSION,
                         (void*)SQL_OV_ODBC3,
                         0);
  if ((status != SQL_SUCCESS) && (status != SQL_SUCCESS_WITH_INFO)) {
    std::cerr << "Error SQLAllocHandle\n";
    throw 0;
  }

}

Connection::Connection(const std::string& host,
                       const std::string& database,
                       cppdb::port_t port,
                       const std::string& username,
                       const std::string& password)
{
  auto status = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &_env);
  if ((status != SQL_SUCCESS) && (status != SQL_SUCCESS_WITH_INFO)) {
    std::cerr << "Error SQLAllocHandle\n";
    throw 0;
  }


  auto status = SQLConnect(_hdbc,
                           (SQLCHAR *)host.c_str(),
                           (SQLSMALLINT)host.size(),
                           (SQLCHAR *)username.c_str(),
                           (SQLSMALLINT)username.size(),
                           (SQLCHAR *)password.c_str(),
                           (SQLSMALLINT)password.size());

  std::cout << "SQLConnect " << status << "\n";
  if (SQL_STAT_SUCCESS(status)) {
      return 0;
  }

}

} /* namespace ODBC */
