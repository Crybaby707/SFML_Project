cmake_minimum_required(VERSION 3.10)
project(DemoGame)

# Додати виконуваний файл вашого проекту
add_executable(MyExecutable main.cpp Player.cpp GameController.cpp)


# Підключити SFML бібліотеки
find_package(SFML 2.6 COMPONENTS graphics system window REQUIRED)

# Додати шляхи підключення та бібліотеки для вашого проекту
target_include_directories(MyExecutable PRIVATE ${SFML_INCLUDE_DIR})
target_link_libraries(MyExecutable PRIVATE sfml-graphics sfml-window sfml-system)
