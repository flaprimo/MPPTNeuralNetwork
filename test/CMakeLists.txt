add_executable(MPPTNeuralNetworkTest MPPTNeuralNetworkTest.c)

add_subdirectory(unity)
add_subdirectory(helper)
add_subdirectory(neuralnet)
add_subdirectory(pvpanel)

target_link_libraries (MPPTNeuralNetworkTest unity helperTest neuralnetTest pvpanelTest)