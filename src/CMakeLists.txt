add_executable(MPPTNeuralNetwork MPPTNeuralNetwork.c)

add_subdirectory(helper)
add_subdirectory(pvpanel)
add_subdirectory(neuralnet)

target_link_libraries (MPPTNeuralNetwork helper pvpanel neuralnet)