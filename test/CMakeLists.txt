add_executable(MPPTNeuralNetworkTest MPPTNeuralNetworkTest.c)

add_subdirectory(unity)
add_subdirectory(neuralnet)
add_subdirectory(helper)
add_subdirectory(pvpanel)
add_subdirectory(pvpanelnn)

target_link_libraries (MPPTNeuralNetworkTest unity neuralnetTest helperTest pvpanelTest pvpanelnnTest)