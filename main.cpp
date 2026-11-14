#include <exception>
#include <iostream>
#include <memory>
#include <string>

#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>

#include "consts.h"
#include "general_models.h"

int main() {
	std::string conn_str;
	conn_str += consts::db_config::kHostKey;
	conn_str += consts::db_config::kHost;

	conn_str += consts::db_config::kPortKey;
	conn_str += consts::db_config::kPort;

	conn_str += consts::db_config::kDbNameKey;
	conn_str += consts::db_config::kDbName;

	conn_str += consts::db_config::kUserKey;
	conn_str += consts::db_config::kUser;

	conn_str += consts::db_config::kPasswordKey;
	conn_str += consts::db_config::kPassword;

	try {
		auto backend_postgres = std::make_unique<Wt::Dbo::backend::Postgres>(conn_str);

		Wt::Dbo::Session session;
		session.setConnection(std::move(backend_postgres));

		session.mapClass<models::Publisher>(
			consts::db_tables::kPublisherTable.data());
		session.mapClass<models::Book>(
			consts::db_tables::kBookTable.data());
		session.mapClass<models::Shop>(
			consts::db_tables::kShopTable.data());
		session.mapClass<models::Stock>(
			consts::db_tables::kStockTable.data());
		session.mapClass<models::Sale>(
			consts::db_tables::kSaleTable.data());

		Wt::Dbo::Transaction transaction(session);
		session.createTables();
		transaction.commit();

		std::cout << consts::messages::kTablesCreated;
	}
	catch (const Wt::Dbo::Exception& e) {
		std::cerr << consts::errors::kDboErrorMsg << e.what()
			<< consts::errors::kCodeMsg << e.code() << "\n";
		return 1;
	}
	catch (const std::exception& e) {
		std::cerr << consts::errors::kStandardErrorMsg << e.what() << "\n";
		return 2;
	}
	catch (...) {
		std::cerr << consts::errors::kUnknownErrorMsg << "\n";
		return 3;
	}
	return 0;
}