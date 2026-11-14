# Before Building

### 1. Check the PostgreSQL path in `CMakeLists.txt` (`PG_DIR`)
I used the following path:
```cmake
set(PG_DIR "C:/Program Files/PostgreSQL/18")
```
If your path is different, update this variable before building.

### 2. Check the database configuration in `consts.h`
I used the following settings:
* **Host:** `localhost`
* **Port:** `5432`
* **Database:** `postgres`
* **User:** `postgres`
* **Password:** `zuzha2015A!`

If your configuration differs, update the relevant constants in `consts.h`:
```cpp
inline constexpr std::string_view kHost = "your_host";
inline constexpr std::string_view kPort = "your_port";
inline constexpr std::string_view kDbName = "your_db_name";
inline constexpr std::string_view kUser = "your_username";
inline constexpr std::string_view kPassword = "your_password";
```

### 3. Extract `archive_orm.zip` (Wt SDK) into the `orm` folder in the project root.

---

# Build

Run the following commands in your terminal:
```bash
cmake -S . -B build
cmake --build build --config Release
```

---

# Run

After building, run the executable:
```bash
.\build\Release\homework_orm.exe
```
