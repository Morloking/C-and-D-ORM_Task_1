#pragma once

#include <string>

#include <Wt/Dbo/Dbo.h>

#include "consts.h"

namespace models {
	struct Publisher;
	struct Stock;
	struct Book {
		std::string title = std::string(consts::default_values::kTitle);
		Wt::Dbo::ptr<Publisher> publisher;
		Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;

		template  <class Action>
		void persist(Action& a);
	};
}