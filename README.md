# Before build
* 1. Check the PostgreSQL path in *CMakeLists.txt* (PG_DIR). I used: *set(PG_DIR "C:/Program Files/PostgreSQL/18")*. If your path is different, change this field before building.
* 2. Check the database configuration in *consts.h*. I used:
* *Host:* localhost
* *Port:* 5432
* *Database:* postgres
* *User:* postgres
* *Password:* zuzha2015A!
If your configuration differs, you need to update the relevant constants in *consts.h*:
* *inline constexpr std::string_view kHost = "your_localhost";*
* *inline constexpr std::string_view kPort = "your_port";*
* *inline constexpr std::string_view kDbName = "your_db_name";*
* *inline constexpr std::string_view kUser = "your_username";*
* *inline constexpr std::string_view kPassword = "your_password";*
* 3. Unpack the *archive_orm.zip* (Wt SDK) into the *orm* folder in the project root.

# Assembly
* *cmake -S . -B build*
* *cmake --build build --config Release*

# Run after build
* *.\build\Release\homework_orm.exe*