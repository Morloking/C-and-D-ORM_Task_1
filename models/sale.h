#pragma once

#include <string>

#include <Wt/Dbo/Dbo.h>

#include "consts.h"

namespace models {
	struct Stock;
	struct Sale {
		double price = consts::default_values::kPrice;
		std::string date_sale = std::string(consts::default_values::kDateSale);
		int count = consts::default_values::kCount;
		Wt::Dbo::ptr <Stock> stock;

		template <class Action>
		void persist(Action& a);
	};
}