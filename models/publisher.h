#pragma once

#include <string>

#include <Wt/Dbo/Dbo.h>

#include "consts.h"

namespace models {
	struct Book;
	struct Publisher {
		std::string name = std::string(consts::default_values::kName);
		Wt::Dbo::collection <Wt::Dbo::ptr<Book>> books;
		
		template <class Action>
		void persist(Action& a);
	};
}