#pragma once

#include <string>

#include <Wt/Dbo/Dbo.h>

#include "book.h"
#include "consts.h"
#include "publisher.h"
#include "sale.h"
#include "shop.h"
#include "stock.h"

namespace models {
    /* Adds the ">" prefix so Wt::Dbo uses the exact column name in the database
       instead of automatically appending "_id" (example: "id_book" instead of "id_book_id")*/
    inline std::string ExactColumn(std::string_view col) { 
        return ">" + std::string(col);
    }

    template <class Action>
    void Publisher::persist(Action& a) {
        Wt::Dbo::field(
            a, name, 
            std::string(consts::db_columns::kNameCol));
        Wt::Dbo::hasMany(
            a, books, Wt::Dbo::ManyToOne,
            std::string(consts::db_columns::kIdPublisherCol));
    }

    template <class Action>
    void Book::persist(Action& a) {
        Wt::Dbo::field(
            a, title, 
            std::string(consts::db_columns::kTitleCol));
        Wt::Dbo::belongsTo(
            a, publisher,
            ExactColumn(consts::db_columns::kIdPublisherCol));
        Wt::Dbo::hasMany(
            a, stocks, Wt::Dbo::ManyToOne,
            std::string(consts::db_columns::kIdBookCol));
    }

    template <class Action>
    void Shop::persist(Action& a) {
        Wt::Dbo::field(
            a, name, 
            std::string(consts::db_columns::kNameCol));
        Wt::Dbo::hasMany(
            a, stocks, Wt::Dbo::ManyToOne,
            std::string(consts::db_columns::kIdShopCol));
    }

    template <class Action>
    void Stock::persist(Action& a) {
        Wt::Dbo::field(
            a, count, 
            std::string(consts::db_columns::kCountCol));
        Wt::Dbo::belongsTo(
            a, book, 
            ExactColumn(consts::db_columns::kIdBookCol));
        Wt::Dbo::belongsTo(
            a, shop, 
            ExactColumn(consts::db_columns::kIdShopCol));
    }

    template <class Action>
    void Sale::persist(Action& a) {
        Wt::Dbo::field(
            a, price, 
            std::string(consts::db_columns::kPriceCol));
        Wt::Dbo::field(
            a, date_sale, 
            std::string(consts::db_columns::kDateSaleCol));
        Wt::Dbo::field(
            a, count, 
            std::string(consts::db_columns::kCountCol));
        Wt::Dbo::belongsTo(
            a, stock, 
            ExactColumn(consts::db_columns::kIdStockCol));
    }

} 
