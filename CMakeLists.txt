# Указываем минимальную требуемую версию CMake. Это важная метаинформация.
cmake_minimum_required(VERSION 3.10)

# Устанавливаем имя проекта и версию. Это основные метаданные.
project(LR1_KALITA_4432Kz VERSION 1.0.0 LANGUAGES CXX)

# Устанавливаем стандарт языка C++. Важная метаинформация для компилятора.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Сообщаем CMake, что мы хотим создать исполняемый файл из исходного кода.
# "main" - это имя будущей программы, "src/main.cpp" - путь к коду.
add_executable(main src/main.cpp)

# Опционально: Указываем свойства для исполняемого файла.
# Это тоже метаданные, которые будут вшиты в бинарник.
set_target_properties(main PROPERTIES
    VERSION ${PROJECT_VERSION}
    # Замените на ваши данные:
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
)