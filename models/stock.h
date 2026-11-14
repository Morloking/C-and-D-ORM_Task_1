#pragma once

#include <string>

#include <Wt/Dbo/Dbo.h>

#include "consts.h"

namespace models {
	struct Book;
	struct Shop;
	struct Sale;
	struct Stock {
		/* The "sales" back-reference was removed due to a bug in Wt::Dbo. 
		I encountered this issue when combining several "belongsTo" relationships with a "hasMany" relationship.
        Since the foreign key is already defined on the "sales" side, the relationship continues to function correctly. */

		int count = consts::default_values::kCount;
		Wt::Dbo::ptr <Book> book;
		Wt::Dbo::ptr <Shop> shop;

		template <class Action>
		void persist(Action& a);
	};
}