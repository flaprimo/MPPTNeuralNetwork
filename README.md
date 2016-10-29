# MPPTNeuralNetwork
Bachelor's degree thesis at Università degli Studi Roma Tre with title "Design and Implementation of a MPPT algorithm for photovoltaic panels based on neural networks". Feed-Forward Multi Layer Perceptron solution for MPPT for photovoltaic panels.
More info and the thesis (in italian) on my [website](https://flavioprimo.xyz/programming-languages/design-implementation-mppt-algorithm-photovoltaic-panels-based-neural-networks/).
Texas Instruments Launchpad Stellaris implementation available [here](https://github.com/flaprimo/MPPTNeuralNetwork/).

Includes 3 independent libraries:
* **NeuralNet** - loads configuration files, manages and computes Feed-Forward Multi Layer Perceptron Neural Nets. By default it loads the Neural Net for solving MPPT. It takes voltage, current and temperature of the photovoltaic panel and outputs the optimal voltage to apply to the panel in order to get the MPP. 
* **Simulation** - Simulate a photovoltaic panel with 700 irradiance and temperature samples. It then compare MPP results with the one calculated by the Neural Net.
* **Helper** - time profiling of the application.

Libraries/Tech:
* [CMake](http://cmake.org/) - test and production builds
* [Unity](http://www.throwtheswitch.org/unity/) - unit testing for C

# Credits
Made by: [Flavio Primo](https://flavioprimo.xyz/about/)

Supervisor: [Francesco Riganti Fulginei](https://it.linkedin.com/in/francesco-riganti-fulginei-102153b/)
