cmake_minimum_required(VERSION 3.10)
project(GuardGL VERSION 0.1.0 LANGUAGES CXX)

# 1. Padrão C++ (Recomendado 17 para usar as features de movimento e filesystem)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 2. Localizar dependências (Assumindo que estão no sistema)
# Se você usa o vcpkg ou submódulos, essa parte pode mudar levemente
find_package(glfw3 REQUIRED)
# O GLAD geralmente é incluído como arquivo fonte, mas se for lib:
# find_package(glad REQUIRED) 

# 3. Incluir o diretório de headers para que o compilador ache o .hpp
include_directories(include)

# 4. Listar os arquivos fontes
set(SOURCES
    src/ShaderManager.cpp
    # Adicione novos .cpp aqui conforme a lib crescer
)

# 5. Criar a biblioteca (pode ser STATIC ou SHARED)
add_library(${PROJECT_NAME} STATIC ${SOURCES})

# 6. Vincular dependências à sua lib
target_link_libraries(${PROJECT_NAME} glfw)
# Se você tiver o glad.c no projeto, adicione-o em SOURCES e vincule o diretório dele
