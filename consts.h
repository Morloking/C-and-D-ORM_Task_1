#pragma once
#include <string_view>

namespace consts {
	namespace default_values {
		inline constexpr int kId = 0;
		inline constexpr std::string_view kName = "empty";
		inline constexpr std::string_view kTitle = "empty";
		inline constexpr int kCount = 0;
		inline constexpr double kPrice = 0.0;
		inline constexpr std::string_view kDateSale = "empty-empty-empty";
	}
	namespace db_columns {
		// Common
		inline constexpr std::string_view kIdCol = "id";
		inline constexpr std::string_view kNameCol = "name";
		// Book
		inline constexpr std::string_view kTitleCol = "title";
		inline constexpr std::string_view kIdPublisherCol = "id_publisher";
		// Stock
		inline constexpr std::string_view kIdBookCol = "id_book";
		inline constexpr std::string_view kIdShopCol = "id_shop";
		inline constexpr std::string_view kCountCol = "count";
		// Sale
		inline constexpr std::string_view kPriceCol = "price";
		inline constexpr std::string_view kDateSaleCol = "date_sale";
		inline constexpr std::string_view kIdStockCol = "id_stock";
	}
	namespace db_tables {
		inline constexpr std::string_view kPublisherTable = "publisher";
		inline constexpr std::string_view kBookTable = "book";
		inline constexpr std::string_view kShopTable = "shop";
		inline constexpr std::string_view kStockTable = "stock";
		inline constexpr std::string_view kSaleTable = "sale";
	}
	namespace db_config {
		inline constexpr std::string_view kHostKey = "host=";
		inline constexpr std::string_view kPortKey = " port=";
		inline constexpr std::string_view kDbNameKey = " dbname=";
		inline constexpr std::string_view kUserKey = " user=";
		inline constexpr std::string_view kPasswordKey = " password=";

		inline constexpr std::string_view kHost = "localhost";
		inline constexpr std::string_view kPort = "5432";
		inline constexpr std::string_view kDbName = "postgres";
		inline constexpr std::string_view kUser = "postgres";
		inline constexpr std::string_view kPassword = "zuzha2015A!";
	}
	namespace errors {
		inline constexpr std::string_view kDboErrorMsg = "Dbo error: ";
		inline constexpr std::string_view kCodeMsg = " . Code: ";
		inline constexpr std::string_view kStandardErrorMsg = "Standard error: ";
		inline constexpr std::string_view kUnknownErrorMsg = "Unknown error occurred";
	}
	namespace messages {
		inline constexpr std::string_view kTablesCreated = "Tables created successfully.\n";
		inline constexpr std::string_view kPressEnter = "\nPress Enter to exit...";
	}
}