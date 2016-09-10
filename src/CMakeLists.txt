add_executable(MPPTNeuralNetwork MPPTNeuralNetwork.c)

add_subdirectory(helper)
add_subdirectory(neuralnet)
add_subdirectory(simulation)

target_link_libraries (MPPTNeuralNetwork helper neuralnet simulation)

# resources folder
file(COPY ../res DESTINATION ../)