#pragma once

#include <string>

#include <Wt/Dbo/Dbo.h>

#include "consts.h"

namespace models {
	struct Stock;
	struct Shop {
		std::string name = std::string(consts::default_values::kName);
		Wt::Dbo::collection <Wt::Dbo::ptr<Stock>> stocks;

		template <class Action>
		void persist(Action& a);
	};
}