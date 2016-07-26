add_executable(MPPTNeuralNetworkTest MPPTNeuralNetworkTest.c)

add_subdirectory(unity)

target_link_libraries (MPPTNeuralNetworkTest unity perceptron helper)