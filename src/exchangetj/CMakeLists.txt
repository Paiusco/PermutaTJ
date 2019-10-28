add_library(exchangetj STATIC ./src/exchangetj.cpp)

set_target_properties(exchangetj PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS NO)

#na~o funcionou, talvez por na~o ter sido incluido
#manualmente com add_subdirectory na raiz mas n~ao fiquei insistindo
#target_include_directories(exchangetj PUBLIC "../external_libs/cereal/cereal-v1.3.0/include")

#funcionou
target_include_directories(exchangetj PUBLIC "./include")
